# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfritsch <gfritsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 11:17:57 by gfritsch          #+#    #+#              #
#    Updated: 2022/04/11 15:20:31 by gfritsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_quote.c			\
			string_utils.c		\
			parser.c			\
			ft_memset.c			\
			redo_split.c		\
			indexer.c			\
			ft_token.c			\
			ft_is.c				\
			unload.c			\
			convert_env_var.c	\
			main.c

OBJS	=	$(SRCS:.c=.o)

LIBS	=	-lreadline

NAME	=	minishell

CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address

all		:	$(NAME)

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all


.PHONY	:	all clean fclean re
