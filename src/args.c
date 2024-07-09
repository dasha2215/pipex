/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:18:34 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/02 14:08:48 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * get_command_path - Gets the full path of a command.
 * @cmd: The command to search for.
 * @envp: The environment variables.
 *
 * This function searches for the command in the directories specified in the PATH
 * environment variable. If the command contains a '/', it checks if the command
 * is executable and returns the command itself if it is.
 *
 * Return: The full path to the command if found, NULL otherwise.
 */
char	*get_command_path(char *cmd, char **envp)
{
	char	*tmp;
	char	*paths;
	char	**path_list;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			tmp = ft_strdup(cmd);
			if (!tmp)
				put_error("malloc", NULL, NULL);
			return (tmp);
		}
		file_not_found(cmd);
		return (0);
	}
	paths = get_all_paths(envp);
	path_list = ft_split(paths, ':');
	if (!path_list)
		put_error("malloc", NULL, NULL);
	tmp = find_command(cmd, path_list);
	free_arr(path_list);
	return (tmp);
}

/**
 * find_command - Searches for a command in the list of paths.
 * @cmd: The command to search for.
 * @path_list: The list of paths to search in.
 *
 * This function appends the command to each path in the list and checks if the
 * resulting path is executable.
 *
 * Return: The full path to the command if found, NULL otherwise.
 */
char	*find_command(char *cmd, char **path_list)
{
	char	*tmp;
	char	*path;
	int		i;

	i = -1;
	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		put_error("malloc", NULL, NULL);
	while (path_list[++i])
	{
		path = ft_strjoin(path_list[i], tmp);
		if (!path)
			put_error("malloc", NULL, NULL);
		if (access(path, X_OK) == 0)
		{
			free(tmp);
			return (path);
		}
		free(path);
	}
	free(tmp);
	command_not_found(cmd);
	return (0);
}

/**
 * get_all_paths - Retrieves the PATH environment variable.
 * @envp: The environment variables.
 *
 * This function searches for the PATH environment variable and returns its value.
 *
 * Return: The value of the PATH environment variable.
 */
char	*get_all_paths(char **envp)
{
	char	*paths;
	int		i;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = envp[i] + 5;
			ft_putstr_fd(paths, 0);
			break ;
		}
		i++;
	}
	return (paths);
}
