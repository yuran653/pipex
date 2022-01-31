/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:15:27 by jgoldste          #+#    #+#             */
/*   Updated: 2022/01/31 23:15:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	pipex(char *argv, char **env);
void	duplicate(int *fd);
void	execute(char *argv, char **env);
void	execute_last(char *argv, char **env);
void	close_fd(int *fd);
int		validation(int argc, char **argv, char **env);
int		heredoc(char **argv);
int		save_heredoc(char *buff);
char	*join_buff_line(char *buff, char *line);
int		check_value(char *line, char *argv);
char	*get_path(char **env, char **cmds);
char	*get_exec_path(int i, char **cmds_path, char **cmds);
char	**find_path(char **env);
void	free_array(char **arr);
void	error_file(char *file_name, int fd);
void	error_env(char **env);
void	error_command(char **cmds);
void	error_malloc(void);
void	error_path(void);
void	error_common(void);
char	*get_next_line(int fd);
char	*get_full_line(int fd, char *line, char *buff);
char	*get_end_line(char *line, char *buff);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_strlcat_gnl(char *dst, char *src);
void	ft_strlcpy_gnl(char *dst, char *src);
int		ft_strchr_gnl(char *str, int c);
int		ft_strlen_gnl(char *str);

#endif
