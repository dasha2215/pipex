/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:23:11 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/02 13:41:18 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mylib/ft_printf.h"
# include "../mylib/libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>

void	parse_args(int argc, char **argv);
char	*get_command_path(char *cmd, char **envp);
void	write_path(char **cmd, char *cmd_path);
char	*find_command(char *cmd, char **path_list);
char	*get_all_paths(char **envp);
void	fork_and_pipe(char **argv, char **envp, int *status);
void	parent_process(int (*pipe_fds)[2], int pid1, int pid2, int *status);
void	first_child_process(int file_fd[2], int pipe_fd[2],
			char **argv, char **envp);
void	second_child_process(int file_fd[2], int pipe_fd[2],
			char **argv, char **envp);
void	execute_command(char *cmd, char **envp);
void	handle_error(char *message);
void	put_error(char *function, int (*pipe_fds)[2], int (*file_fds)[2]);
void	close_child_fds(int pipe_fd, int file_fd);
void	command_not_found(char *cmd);
void	file_not_found(char *file);
void	close_fds(int fd1, int fd2);
void	free_arr(char **arr);

#endif