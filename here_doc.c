/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:57:36 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/29 18:03:07 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	save_heredoc(char **line)
{
	int	pipe_fd[2];
	int	i;

	i = -1;
	if (pipe(pipe_fd) < 0)
		error_common();
	while (line[++i])
		ft_putstr_fd(line[i], pipe_fd[1]);
	if (close(pipe_fd[1]) == -1)
		error_common();
	return (pipe_fd[0]);
}

int	heredoc(char **argv)
{
	int		i;
	char	**line;

	i = -1;
	line = (char **)malloc(sizeof(char *) * 1000);
	if (!line)
		error_malloc();
	while (++i >= 0)
	{
		line[i] = get_next_line(STDIN_FILENO);
		if (!line[i])
			error_malloc();
		if (ft_strncmp(line[i], argv[2], ft_strlen(argv[2])) == 0
			&& ft_strncmp(line[i], "\n", 1) != 0
			&& ft_strlen(line[i]) - 1 == ft_strlen(argv[2]))
		{
			line[i] = NULL;
			return (save_heredoc(line));
		}
	}
	return (0);
}
