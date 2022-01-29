/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:57:36 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/30 02:17:30 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	save_heredoc(char **buff)
{
	int	pipe_fd[2];
	int	i;

	i = -1;
	if (pipe(pipe_fd) < 0)
		error_common();
	while (buff[++i])
		ft_putstr_fd(buff[i], pipe_fd[1]);
	if (close(pipe_fd[1]) == -1)
		error_common();
	free_array(buff);
	return (pipe_fd[0]);
}

int	heredoc(char **argv)
{
	int		i;
	char	**buff;

	i = -1;
	buff = (char **)malloc(sizeof(char *) * 1000);
	if (!buff)
		error_malloc();
	while (++i >= 0)
	{
		ft_putstr_fd("here_doc > ", STDOUT_FILENO);
		buff[i] = get_next_line(STDIN_FILENO);
		if (!buff[i])
			i--;
		else if (ft_strncmp(buff[i], argv[2], ft_strlen(argv[2])) == 0
			&& ft_strncmp(buff[i], "\n", 1) != 0
			&& ft_strlen(buff[i]) - 1 == ft_strlen(argv[2]))
		{
			buff[i] = NULL;
			return (save_heredoc(buff));
		}
	}
	return (0);
}
