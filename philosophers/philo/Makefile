# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 00:10:44 by aprahin           #+#    #+#              #
#    Updated: 2022/12/09 22:28:23 by aprahin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOURS

_END		=	\e[0m
_BOLD		=	\e[1m
_DIM		=	\e[2m
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

_MOFF		=	\e[?25l
_MON		=	\e[?25h
_MUP		=	\e[1A
_ERASE		=	\e[K

# COMPILATION FLAGS

CFLAGS		=	-Wall -Wextra -Werror -ggdb3
LFLAGS		=
IFLAGS 		=	$(addprefix -I,$(IDIR))

# DIRECTORIES

DIR			=	./
ODIR		=	objects/
LDIR		=	notlibft/
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
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

SRC			=	philo.c \
				utils.c \
				forks.c \
				routine.c \

SRCS		=	$(addprefix $(DIR), $(SRC))
LSRCS		=	$(addprefix $(LDIR), $(LSRC))

# OBJECTS

OBJS		=	$(addprefix $(ODIR), $(OBJ))
LOBJS		=	$(addprefix $(ODIR), $(LOBJ))

OBJ			=	$(SRC:.c=.o)
LOBJ		=	$(LSRC:.c=.o)

# VARS

LNB			=	$(shell ls -l $(LDIR) | grep -F .c | wc -l)
NB			=	$(shell ls -l $(DIR) | grep -F .c | wc -l)
LCNT		=	1
CNT			=	1

# COMMANDS

CC			=	gcc
RM			=	rm -f
RMDIR		=	rmdir
MKDIR		=	mkdir

# NAME

NAME		=	philo
LNAME		=	notlibft

# MANDATORY

all:		$(NAME)

$(NAME):	$(ODIR) echolib $(LOBJS) echoendlib echoname $(OBJS) echoendname
			@printf "$(_BOLD)$(_WHITE)Compiling $(_YELLOW)everything$(_END)\n"
			@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LOBJS) -o $(NAME) $(LFLAGS)
			@printf "$(_BOLD)$(_GREEN)OK! $(_END)$(_DIM)$(_WHITE)(./$(NAME))$(_END)\n\n"

clean:
			@printf "\n$(_BOLD)$(_WHITE)Removing $(_RED)$(NAME)$(_WHITE) objects$(_END)\n"
			@$(RM) $(OBJS)
			@printf "$(_BOLD)$(_WHITE)Removing $(_RED)$(LNAME)$(_WHITE) objects$(_END)\n\n"
			@$(RM) $(LOBJS)
			@if [ -d "$(ODIR)" ]; then $(RMDIR) $(ODIR) || true; fi

fclean:		clean
			@printf "$(_MUP)$(_BOLD)$(_WHITE)Removing $(_RED)$(NAME)$(_WHITE) (./$(NAME))$(_END)\n\n"
			@$(RM) $(NAME)

re:			fclean all

# EXTRA

$(ODIR):
			@$(MKDIR) $(ODIR)

bonus:		all

.PHONY:		all clean fclean re bonus

# IMPLICIT

$(ODIR)%.o:	$(LDIR)%.c
			@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<
			@printf "$(_ERASE)\r"
			@printf "$(_DIM)$(_YELLOW)$(subst $(LDIR),,$<)$(_END)\n"
			@for i in $$(seq 1 $(LCNT)); \
			do \
				printf "$(_BOLD)$(_GREEN).$(_END)"; \
			done
			@for i in $$(seq 1 $$(($(LNB) - $(LCNT)))); \
			do \
				printf "$(_DIM)$(_RED).$(_END)"; \
			done
			$(eval LCNT=$(shell echo $$(($(LCNT)+1))))
			@printf "\r$(_MUP)"

$(ODIR)%.o:	$(DIR)%.c
			@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<
			@printf "$(_ERASE)\r"
			@printf "$(_DIM)$(_YELLOW)$(subst $(DIR),,$<)$(_END)\n"
			@for i in $$(seq 1 $(CNT)); \
			do \
				printf "$(_BOLD)$(_GREEN).$(_END)"; \
			done
			@for i in $$(seq 1 $$(($(NB) - $(CNT)))); \
			do \
				printf "$(_DIM)$(_RED).$(_END)"; \
			done
			$(eval CNT=$(shell echo $$(($(CNT)+1))))
			@printf "\r$(_MUP)"

# PRETTY

echolib:
			@printf "$(_MOFF)"
			@printf "\n$(_BOLD)$(_WHITE)Compiling $(_YELLOW)$(LNAME)$(_END)\n"

echoendlib:
			@printf "$(_ERASE)"
			@printf "$(_BOLD)$(_GREEN)OK!$(_END)\n"

echoname:
			@printf "\n$(_BOLD)$(_WHITE)Compiling $(_YELLOW)$(NAME)$(_END)\n"

echoendname:
			@printf "$(_ERASE)"
			@printf "$(_BOLD)$(_GREEN)OK!$(_END)\n\n"
			@printf "$(_MON)"
