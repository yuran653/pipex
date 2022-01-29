/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:28:47 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/30 01:54:58 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	**find_path(char **env)
{
	int		i;
	char	*path;
	char	**cmds_path;

	i = -1;
	while (env[++i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path)
		{
			cmds_path = ft_split(path + 5, ':');
			if (!cmds_path)
				error_malloc();
			return (cmds_path);
		}
	}
	error_path();
	return (NULL);
}

char	*get_exec_path(int i, char **cmds_path, char **cmds)
{
	char	*exec_path;
	char	*slash_cmd;

	if (!cmds[0])
		error_command(cmds);
	slash_cmd = ft_strjoin("/", cmds[0]);
	if (!slash_cmd)
	{
		free_array(cmds);
		free_array(cmds_path);
		error_malloc();
	}
	exec_path = ft_strjoin(cmds_path[i], slash_cmd);
	if (!exec_path)
	{
		free(slash_cmd);
		free_array(cmds);
		free_array(cmds_path);
		error_malloc();
	}
	return (exec_path);
}

char	*get_path(char **env, char **cmds)
{
	int		i;
	char	*exec_path;
	char	**cmds_path;

	i = -1;
	cmds_path = find_path(env);
	while (cmds_path[++i])
	{
		exec_path = get_exec_path(i, cmds_path, cmds);
		if (access(exec_path, X_OK) == 0)
		{
			free_array(cmds_path);
			return (exec_path);
		}
		free(exec_path);
	}
	error_command(cmds);
	return (NULL);
}
