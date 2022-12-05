# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 12:13:42 by aprahin           #+#    #+#              #
#    Updated: 2022/12/04 23:56:50 by aprahin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOURS

_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

# COMPILATION FLAGS

CFLAGS		=	-Wall -Wextra -Werror ${IFLAGS}

IFLAGS 		=	${addprefix -I,${IDIR}}

# DIRECTORIES

DIR			=	./
ODIR		=	objects/
LDIR		=	libft/
IDIR		=	include/

# SOURCES

LSRC	=		ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putchar.c \
				ft_addchar.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_printf.c \
				ft_in.c \
				ft_itoh.c \
				ft_printnbr.c \
				ft_utoa.c \
				ft_printstr.c \
				ft_printchar.c \
				ft_printptr.c \
				ft_printpc.c \
				ft_printhex.c \
				ft_removechar.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_splitutils.c \
				ft_strjoinf.c \
				get_next_line.c \
				get_next_line_utils.c \

SRC			=	pipex.c \
				pipex_utils1.c \
				pipex_utils2.c \
				pipex_utils3.c \

SRCS		=	${addprefix ${DIR}, ${SRC}}
LSRCS		=	${addprefix ${LDIR}, ${LSRC}}

# OBJECTS

OBJS		=	${addprefix ${ODIR}, ${OBJ}}
LOBJS		=	${addprefix ${ODIR}, ${LOBJ}}

OBJ			=	${SRC:.c=.o}
LOBJ		=	${LSRC:.c=.o}

# COMMANDS

CC			=	gcc
RM			=	rm -f
RMDIR		=	rmdir
MKDIR		=	mkdir

# NAME

NAME		=	pipex
LNAME		=	libft

# MANDATORY

all:		${NAME}

${NAME}:	${ODIR} echolib ${LOBJS} echoendlib echoname ${OBJS} echoendname
			@printf "${_BOLD}${_WHITE}Compiling ${_YELLOW}everything${_END}\n"
			@${CC} ${IFLAGS} ${OBJS} ${LOBJS} -o ${NAME}
			@printf "${_BOLD}${_GREEN}OK! ${_WHITE}(./${NAME})${_END}\n\n"

clean:
			@printf "\n${_BOLD}${_WHITE}Removing ${_RED}${NAME}${_WHITE} objects${_END}\n"
			@${RM} ${addprefix ${ODIR}, ${OBJS:${LDIR}%=%}}
			@printf "${_BOLD}${_WHITE}Removing ${_RED}${LNAME}${_WHITE} objects${_END}\n\n"
			@${RM} ${addprefix ${ODIR}, ${LOBJS:${LDIR}%=%}}
			@if [ -d "${ODIR}" ]; then rm -Rf ${ODIR}; fi

fclean:		clean
			@printf "${_BOLD}${_WHITE}Removing ${_RED}${NAME}${_WHITE} (./${NAME})${_END}\n\n"
			@${RM} ${NAME}

re:			fclean all

# EXTRA

${ODIR}:
			@${MKDIR} ${ODIR}

bonus:		all

.PHONY:		all clean fclean re bonus

# IMPLICIT

${ODIR}%.o:	${LDIR}%.c
			@${CC} ${CFLAGS} ${IFLAGS} -c -o $@ $<
			@printf "${_BOLD}${_GREEN}.${_END}"

${ODIR}%.o:	${DIR}%.c
			@${CC} ${CFLAGS} ${IFLAGS} -c -o $@ $<
			@printf "${_BOLD}${_GREEN}.${_END}"

# PRETTY

echolib:
			@printf "\n${_BOLD}${_WHITE}Compiling ${_YELLOW}${LNAME}${_END}\n"

echoendlib:
			@printf "\n${_BOLD}${_GREEN}OK!${_END}\n"

echoname:
			@printf "${_BOLD}${_WHITE}Compiling ${_YELLOW}${NAME}${_END}\n"

echoendname:
			@printf "\n${_BOLD}${_GREEN}OK!${_END}\n"
