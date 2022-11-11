# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 20:15:21 by aprahin           #+#    #+#              #
#    Updated: 2022/11/05 20:15:21 by aprahin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror -Ilibft

NAME	= libftprintf.a

SRCS	= ft_putchar.c ft_addchar.c ft_putnbr.c ft_putstr.c ft_printf.c ft_in.c ft_itoh.c ft_printnbr.c ft_utoa.c ft_printstr.c ft_printchar.c ft_printptr.c ft_printpc.c ft_printhex.c ft_removechar.c

LIBFT	= libft

OBJS	= ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBFT}
			cp libft/libft.a .
			mv libft.a ${NAME}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			${MAKE} -C ${LIBFT} clean

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}/libft.a

re:			fclean all

bonus:		${NAME}

.PHONY:		all clean fclean re
