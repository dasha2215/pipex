/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:16:11 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/02 13:41:03 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * fork_and_pipe - Handles the forking and piping of processes.
 * @argv: The array of command-line arguments.
 * @envp: The environment variables.
 * @status: Pointer to the status variable.
 *
 * This function creates a pipe and forks two child processes to execute the commands
 * with piped input/output.
 */
void	fork_and_pipe(char **argv, char **envp, int *status)
{
	int		pipe_fds[2];
	int		file_fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fds) == -1)
		put_error("pipe", &pipe_fds, NULL);
	file_fds[0] = open(argv[1], O_RDONLY);
	if (file_fds[0] < 0)
		file_not_found(argv[1]);
	file_fds[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fds[1] < 0)
		file_not_found(argv[4]);
	pid1 = fork();
	if (pid1 == -1)
		put_error("fork", &pipe_fds, &file_fds);
	if (pid1 == 0)
		first_child_process(file_fds, pipe_fds, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		put_error("fork", &pipe_fds, &file_fds);
	if (pid2 == 0)
		second_child_process(file_fds, pipe_fds, argv, envp);
	close_fds(file_fds[1], file_fds[0]);
	parent_process(&pipe_fds, pid1, pid2, status);
}

/**
 * parent_process - Waits for the child processes to finish.
 * @pipe_fds: The pipe file descriptors.
 * @pid1: The process ID of the first child.
 * @pid2: The process ID of the second child.
 * @status: Pointer to the status variable.
 *
 * This function closes the pipe file descriptors and waits for both child processes
 * to finish.
 */
void	parent_process(int (*pipe_fds)[2], int pid1, int pid2, int *status)
{
	close((*pipe_fds)[0]);
	close((*pipe_fds)[1]);
	waitpid(pid1, status, 0);
	waitpid(pid2, status, 0);
}

/**
 * first_child_process - Executes the first command.
 * @file_fd: The file descriptors for input and output files.
 * @pipe_fd: The pipe file descriptors.
 * @argv: The array of command-line arguments.
 * @envp: The environment variables.
 *
 * This function redirects the input and output to the appropriate file descriptors
 * and executes the first command.
 */
void	first_child_process(int file_fd[2], int pipe_fd[2],
		char **argv, char **envp)
{
	close_fds(pipe_fd[0], file_fd[1]);
	if (file_fd[0] < 0)
	{
		close(pipe_fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(file_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close_fds(pipe_fd[1], file_fd[0]);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close_fds(pipe_fd[1], file_fd[0]);
		exit(EXIT_FAILURE);
	}
	close_fds(pipe_fd[1], file_fd[0]);
	execute_command(argv[2], envp);
}

/**
 * second_child_process - Executes the second command.
 * @file_fd: The file descriptors for input and output files.
 * @pipe_fd: The pipe file descriptors.
 * @argv: The array of command-line arguments.
 * @envp: The environment variables.
 *
 * This function redirects the input and output to the appropriate file descriptors
 * and executes the second command.
 */
void	second_child_process(int file_fd[2], int pipe_fd[2],
		char **argv, char **envp)
{
	close_fds(pipe_fd[1], file_fd[0]);
	if (file_fd[1] < 0)
	{
		close(pipe_fd[0]);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close_fds(pipe_fd[0], file_fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(file_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close_fds(pipe_fd[0], file_fd[1]);
		exit(EXIT_FAILURE);
	}
	close_fds(pipe_fd[0], file_fd[1]);
	execute_command(argv[3], envp);
}

/**
 * execute_command - Executes a command.
 * @input_cmd: The command to execute.
 * @envp: The environment variables.
 *
 * This function splits the command into arguments, finds the command's path,
 * and then executes it using execve.
 */
void	execute_command(char *input_cmd, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(input_cmd, ' ');
	if (!cmd)
		put_error("malloc", NULL, NULL);
	cmd_path = get_command_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_arr(cmd);
		exit(127);
	}
	execve(cmd_path, cmd, envp);
	perror("execve");
	free_arr(cmd);
	free(cmd_path);
	exit(EXIT_FAILURE);
}
