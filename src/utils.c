/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:18:01 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/02 13:43:57 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * command_not_found - Handles command not found error.
 * @cmd: The command that was not found.
 *
 * This function prints an error message indicating that the command was not found.
 */
void	command_not_found(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		ft_putstr_fd("pipex: no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return ;
	}
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

/**
 * file_not_found - Handles file not found error.
 * @file: The file that was not found.
 *
 * This function prints an error message indicating that the file was not found
 * or that permission was denied.
 */
void	file_not_found(char *file)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd("permission denied: ", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}

/**
 * put_error - Handles general errors and exits the program.
 * @function: The name of the function where the error occurred.
 * @pipe_fds: The pipe file descriptors.
 * @file_fds: The file descriptors for input and output files.
 *
 * This function prints an error message and closes any open file descriptors
 * before exiting the program.
 */
void	put_error(char *function, int (*pipe_fds)[2], int (*file_fds)[2])
{
	if (ft_strcmp(function, "Invalid number of arguments.\n") == 0)
		ft_printf("Invalid number of arguments.\n");
	else
		perror(function);
	if ((*pipe_fds))
		close_fds((*pipe_fds)[1], (*pipe_fds)[0]);
	if ((*file_fds))
		close_fds((*file_fds)[1], (*file_fds)[0]);
	exit(EXIT_FAILURE);
}

/**
 * close_fds - Closes two file descriptors.
 * @fd1: The first file descriptor.
 * @fd2: The second file descriptor.
 *
 * This function closes the specified file descriptors if they are open.
 */
void	close_fds(int fd1, int fd2)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
}

/**
 * free_arr - Frees a null-terminated array of strings.
 * @arr: The array to free.
 *
 * This function frees each string in the array and then frees the array itself.
 */
void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !arr[i])
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}
