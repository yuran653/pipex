/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:36:03 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/31 23:12:18 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_fd(int *fd)
{
	if (close(fd[0]) == -1)
		error_common();
	if (close(fd[1]) == -1)
		error_common();
}

void	error_env(char **env)
{
	execve(NULL, NULL, env);
	perror("\e[1;31mERROR:\e[0m environment not found");
	exit(EXIT_FAILURE);
}

int	validation(int argc, char **argv, char **env)
{
	if (!env)
		error_env(env);
	if (argc < 5)
	{
		ft_putstr_fd("\e[1;31mERROR:\e[0m not enough arguments. Instead of [",
			STDERR_FILENO);
		ft_putnbr_fd(argc - 1, STDERR_FILENO);
		ft_putstr_fd("] should be at least [4]\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[2])) == 0
		&& ft_strlen(argv[1]) == 8)
	{
		if (argc != 6)
		{
			ft_putstr_fd
				("\e[1;31mERROR:\e[0m wrong amount of arguments. Instead of [",
					STDERR_FILENO);
			ft_putnbr_fd(argc - 1, STDERR_FILENO);
			ft_putstr_fd("] should be [5]\n", STDERR_FILENO);
			exit(EXIT_SUCCESS);
		}
		return (1);
	}
	return (0);
}
