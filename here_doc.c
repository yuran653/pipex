/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:57:36 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/31 20:56:35 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_value(char *line, char *argv)
{
	unsigned long	len;

	len = ft_strlen(argv);
	if (ft_strncmp(line, argv, len) == 0 && ft_strncmp(line, "\n", 1) != 0
		&& ft_strlen(line) - 1 == len)
		return (1);
	else
		return (0);
}

char	*join_buff_line(char *buff, char *line)
{
	char	*buff_new;

	buff_new = ft_strjoin(buff, line);
	free(buff);
	free(line);
	return (buff_new);
}

int	save_heredoc(char *buff)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		error_common();
	ft_putstr_fd(buff, pipe_fd[1]);
	if (close(pipe_fd[1]) == -1)
		error_common();
	free(buff);
	return (pipe_fd[0]);
}

int	heredoc(char **argv)
{
	int		i;
	char	*line;
	char	*buff;

	i = 0;
	buff = ft_strdup("\0");
	if (!buff)
		error_malloc();
	while (++i > 0)
	{
		ft_putstr_fd("here_doc > ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (check_value(line, argv[2]))
		{
			free(line);
			return (save_heredoc(buff));
		}
		else
			buff = join_buff_line(buff, line);
	}
	return (0);
}
