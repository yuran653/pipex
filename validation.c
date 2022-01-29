/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:36:03 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/27 13:46:44 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validation(int argc)
{
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
