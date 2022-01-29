# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 12:26:15 by jgoldste          #+#    #+#              #
#    Updated: 2022/01/29 19:43:42 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS		=	pipex.c		pipex_utils.c		error.c		validation.c

SRCS_B		=	pipex_bonus.c		pipex_utils_bonus.c		error_bonus.c\
				validation_bonus.c	here_doc.c\
				get_next_line.c		get_next_line_utils.c

HEADER		=	pipex.h

HEADER_B	=	pipex_bonus.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS))

D_FILES_B	=	$(patsubst %.c,%.d,$(SRCS_B))

INCLUDES	=	-I.

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -rf

LIB			=	./libft/libft.a

YELLOW		=	"\033[1;33m"
GREEN		=	"\033[1;32m"
END			=	"\033[0m"

.PHONY		:	all bonus libft clean fclean re rebonus

all			:	libft $(NAME)

libft		:	
				$(MAKE) -C $(dir $(LIB))

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MD

$(NAME)		:	$(OBJS) $(LIB)
#				ifeq ($(strip $(SRCS)),$(strip $(SRCS_B)))
#					$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(OBJS)
#					@echo ${GREEN} "\n\tPipex bonus is compiled\n" ${END}
#				else
#					@$(RM) $(OBJS_B) $(D_FILES_B)
					$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(OBJS)
					@echo ${GREEN} "\n\tPipex is compiled\n" ${END}
#				endif

bonus		:	
				@$(RM) $(OBJS) $(D_FILES)
				@make SRCS='$(SRCS_B)' HEADER='$(HEADER_B)'

clean		:	
				@$(RM) $(OBJS) $(OBJS_B) $(D_FILES) $(D_FILES_B)
				@$(MAKE) -C $(dir $(LIB)) clean
				@echo ${YELLOW} "\n\tPipex 'clean' status: DONE\n" ${END}
				
fclean		:	clean
				@$(RM) $(NAME)
				@$(MAKE) -C $(dir $(LIB)) fclean
				@echo ${YELLOW} "\n\tPipex 'fclean' status: DONE\n" ${END}

re			:	fclean all

rebonus		:	fclean bonus