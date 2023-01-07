# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 00:10:44 by aprahin           #+#    #+#              #
#    Updated: 2022/12/26 19:29:57 by aprahin          ###   ########.fr        #
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

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -ggdb3
LFLAGS		=
IFLAGS 		=	$(addprefix -I,$(IDIR))

# DIRECTORIES

DIR			=	./
ODIR		=	objects/
IDIR		=	include/

# SOURCES

SRC			=	main.cpp \
				Harl.cpp \
				ftLog.cpp \

SRCS		=	$(addprefix $(DIR), $(SRC))

# OBJECTS

OBJS		=	$(addprefix $(ODIR), $(OBJ))

OBJ			=	$(SRC:.cpp=.o)

# VARS

NB			=	$(shell ls -l $(DIR) | grep -F .c | wc -l)
CNT			=	1

# COMMANDS

CC			=	c++
RM			=	rm -f
RMDIR		=	rmdir
MKDIR		=	mkdir

# NAME

NAME		=	HarlFilter

# MANDATORY

all:		$(NAME)

$(NAME):	$(ODIR) echoname $(OBJS) echoendname
			@printf "$(_BOLD)$(_WHITE)Compiling $(_YELLOW)everything$(_END)\n"
			@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)
			@printf "$(_BOLD)$(_GREEN)OK! $(_END)$(_DIM)$(_WHITE)(./$(NAME))$(_END)\n\n"

clean:
			@printf "\n$(_BOLD)$(_WHITE)Removing $(_RED)$(NAME)$(_WHITE) objects$(_END)\n"
			@$(RM) $(OBJS)
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

$(ODIR)%.o:	$(DIR)%.cpp
			@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<
			@printf "$(_ERASE)\r"
			@printf "$(_DIM)$(_YELLOW)$(subst $(DIR),,$<)$(_END)\n"
			@for i in $$(seq 1 $(CNT)); \
			do \
				printf "$(_BOLD)$(_GREEN).$(_END)"; \
			done
			@if [ $(NB) -gt $(CNT) ]; then \
			for i in $$(seq 1 $$(($(NB) - $(CNT)))); do printf "$(_DIM)$(_RED).$(_END)"; done \
			fi
			$(eval CNT=$(shell echo $$(($(CNT)+1))))
			@printf "\r$(_MUP)"
			@sleep 1;

# PRETTY

echoname:
			@printf "\n$(_BOLD)$(_WHITE)Compiling $(_YELLOW)$(NAME)$(_END)\n"

echoendname:
			@printf "$(_ERASE)"
			@printf "$(_BOLD)$(_GREEN)OK!$(_END)\n\n"
			@printf "$(_MON)"
