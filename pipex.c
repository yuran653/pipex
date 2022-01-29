/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:33:41 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/27 21:11:38 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *argv, char **env)
{
	char	*path;
	char	**cmds;

	cmds = ft_split(argv, ' ');
	if (!cmds)
		error_malloc();
	if (access(cmds[0], F_OK) == 0)
	{
		execve(cmds[0], cmds, env);
		error_command(cmds);
	}
	path = get_path(env, cmds);
	execve(path, cmds, env);
	free_array(cmds);
	free(path);
	error_common();
}

void	pipex(char *argv, char **env)
{
	pid_t	pid;
	int		pipe_end[2];

	if (pipe(pipe_end) < 0)
		error_common();
	pid = fork();
	if (pid == -1)
		error_common();
	if (pid)
	{
		if (close(pipe_end[1]) == -1)
			error_common();
		if (dup2(pipe_end[0], STDIN_FILENO) == -1)
			error_common();
	}
	else
	{
		if (close(pipe_end[0]) == -1)
			error_common();
		if (dup2(pipe_end[1], STDOUT_FILENO) == -1)
			error_common();
		execute(argv, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	i;

	i = 2;
	validation(argc);
	fd[0] = open(argv[1], O_RDONLY);
	error_file(argv[1], fd[0]);
	fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	error_file(argv[argc - 1], fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_common();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_common();
	while (i < argc - 2)
		pipex(argv[i++], env);
	execute(argv[i], env);
	if (close(fd[0]) == -1)
		error_common();
	if (close(fd[1]) == -1)
		error_common();
	return (0);
}
