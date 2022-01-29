/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:27:19 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/29 18:25:02 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_common(void)
{
	perror("\e[1;31mERROR\e[0m");
	exit(EXIT_FAILURE);
}

void	error_path(void)
{
	perror("\e[1;31mERROR:\e[0m command's path not found");
	exit(EXIT_FAILURE);
}

void	error_malloc(void)
{
	perror("\e[1;31mERROR:\e[0m malloc allocation failure");
	exit(EXIT_FAILURE);
}

void	error_command(char **cmds)
{
	char	*str_err;

	str_err = ft_strjoin("\e[1;31mERROR:\e[0m command not found: ", cmds[0]);
	if (!str_err)
		error_malloc();
	perror(str_err);
	free(str_err);
	free_array(cmds);
	exit(EXIT_SUCCESS);
}

void	error_file(char *file_name, int fd)
{
	if (fd == -1)
	{
		ft_putstr_fd("\e[1;31mERROR:\e[0m ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": [", STDERR_FILENO);
		ft_putstr_fd(file_name, STDERR_FILENO);
		ft_putstr_fd("]\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
