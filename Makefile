# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 15:17:27 by gwagner           #+#    #+#              #
#    Updated: 2024/08/23 16:17:11 by gwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			=	srcs/
INC_DIR			=	includes/
LIBFT_DIR		=	includes/libft/

LIBFT			=	$(LIBFT_DIR)libft.a

PARSE_DIR		=	$(SRC_DIR)parsing/
EXEC_DIR		=	$(SRC_DIR)execution/
ARGS_DIR		=	$(PARSE_DIR)arguments/
ERR_DIR 		=	$(PARSE_DIR)errorcheck/

MAIN_SRC		=	$(SRC_DIR)minishell.c
ARGS_SRC		=	split_args.c put_args.c parse_utils.c arglist01.c arglist02.c enviroment01.c enviroment02.c
ERR_SRC			=	syntax_error.c
EXEC_SRC		=

ARGS_SRCS		=	$(patsubst %.c,$(ARGS_DIR)%.c,$(ARGS_SRC))
ERR_SRCS		=	$(patsubst %.c,$(ERR_DIR)%.c,$(ERR_SRC))
EXEC_SRCS		=	$(patsubst %.c,$(EXEC_DIR)%.c,$(EXEC_SRC))

ARGS_OBJS		=	$(ARGS_SRCS:.c=.o)
ERR_OBJS		=	$(ERR_SRCS:.c=.o)
EXEC_OBJS		=	$(EXEC_SRCS:.c=.o)
OBJS			=	$(MAIN_SRC:.c=.o) $(ARGS_OBJS) $(ERR_OBJS) $(EXEC_OBJS)

BLUE		=	\033[0;94m
RED 		=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\e[0;33m
CYAN		=	\033[0;96m
COLOR		=	\033[0m

CC				=	@cc -Wall -Werror -Wextra
RM				=	@rm -f

NAME			=	lainshell

%.o:			%.c
					$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
					@make -sC $(LIBFT_DIR)
					@$(CC) $(OBJS) ${LIBFT} -o $(NAME) -lreadline
					@./lain.sh

clean:
					@make -sC $(LIBFT_DIR) clean
					$(RM) $(OBJS)

fclean:			clean
					@make -sC $(LIBFT_DIR) fclean
					$(RM) $(NAME)

re:				fclean all

lain:			
				@firefox https://www.youtube.com/watch?v=MM8RufZr5lw

.PHONY:			all clean fclean re
