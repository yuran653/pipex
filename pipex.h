/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:15:27 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/29 18:36:07 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "./libft/libft.h"

void	pipex(char *argv, char **env);
void	execute(char *argv, char **env);
void	execute_last(char *argv, char **env);
void	validation(int argc);
char	*get_path(char **env, char **cmds);
char	*get_exec_path(int i, char **cmds_path, char *cmds);
char	**find_path(char **env);
void	free_array(char **arr);
void	error_file(char *file_name, int fd);
void	error_command(char **cmds);
void	error_malloc(void);
void	error_path(void);
void	error_common(void);

#endif
