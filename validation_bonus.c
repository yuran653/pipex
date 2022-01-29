/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:36:03 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/29 20:44:42 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	validation(int argc, char **argv)
{
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
