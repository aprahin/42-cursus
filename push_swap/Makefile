# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 12:37:58 by aprahin           #+#    #+#              #
#    Updated: 2022/12/01 01:30:23 by aprahin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror

LDLIBS	=	-l${LNAME}
LDFLAGS =	${addprefix -L,${LDIR}}
INFLAGS =	${addprefix -I,${IDIR}}

NAME	=	push_swap
BNAME	=	checker

LIB		=	${LDIR}/libft.a
IDIR	=	include libft
LDIR	=	libft
LNAME	=	ft

SRCS	=	stack/stack.c \
			stack/stacksetter.c \
			stack/stackgetter.c \
			stack/stackmove.c \
			stack/stackutils.c \
			stack/stackutils2.c \
			libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_isascii.c \
			libft/ft_isprint.c \
			libft/ft_strlen.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_strlcpy.c \
			libft/ft_strlcat.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strncmp.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strnstr.c \
			libft/ft_atoi.c \
			libft/ft_calloc.c \
			libft/ft_strdup.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_striteri.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putchar.c \
			libft/ft_addchar.c \
			libft/ft_putnbr.c \
			libft/ft_putstr.c \
			libft/ft_printf.c \
			libft/ft_in.c \
			libft/ft_itoh.c \
			libft/ft_printnbr.c \
			libft/ft_utoa.c \
			libft/ft_printstr.c \
			libft/ft_printchar.c \
			libft/ft_printptr.c \
			libft/ft_printpc.c \
			libft/ft_printhex.c \
			libft/ft_removechar.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstsize.c \
			libft/ft_lstlast.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstdelone.c \
			libft/ft_lstclear.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \
			libft/ft_strjoinf.c \
			utils/utils.c

PSRCS	=	pswap/push_swap.c \
			sort/sortutils.c \
			sort/sortthree.c \
			sort/sortfour.c \
			sort/sortfive.c \
			sort/sortbessert.c \
			sort/optirot.c \
			sort/optips.c \
			sort/sortbessertutils.c \

BSRCS	=	check/checker.c \
			check/checkerutils.c \

OBJS	= ${SRCS:.c=.o}
POBJS	= ${PSRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}

CC		= gcc
RM		= rm -f

all:		${NAME} bonus

${NAME}:	${OBJS} ${POBJS}
			@${CC} ${INFLAGS} ${OBJS} ${POBJS} -o ${NAME}
			@echo Compiling push_swap \(./${NAME}\)

%.o:		%.c
			${CC} ${CFLAGS} ${INFLAGS} -c -o $@ $<

clean:
			@${RM} ${OBJS}
			@${RM} ${POBJS}
			@${RM} ${BOBJS}
			@echo Cleaning

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${BNAME}

re:			fclean all

bonus:		${OBJS} ${BOBJS}
			@${CC} ${INFLAGS} ${OBJS} ${BOBJS} -o ${BNAME}
			@echo Compiling checker \(./${BNAME}\)

.PHONY:		all clean fclean re bonus
