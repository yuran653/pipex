/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:36:03 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/31 16:26:56 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_env(char **env)
{
	execve(NULL, NULL, env);
	perror("\e[1;31mERROR:\e[0m environment not found");
	exit(EXIT_FAILURE);
}

void	validation(int argc, char **env)
{
	if (!env)
		error_env(env);
	if (argc < 5)
	{
		ft_putstr_fd("\e[1;31mERROR:\e[0m not enough arguments. Instead of [",
			STDERR_FILENO);
		ft_putnbr_fd(argc - 1, 1);
		ft_putstr_fd("] should be [4]\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (argc > 5)
	{
		ft_putstr_fd("\e[1;31mERROR:\e[0m too much arguments. Instead of [",
			STDERR_FILENO);
		ft_putnbr_fd(argc - 1, 1);
		ft_putstr_fd("] should be [4]\n", 1);
		exit(EXIT_SUCCESS);
	}
}
