NAME				= minishell

HDRS_DIR			= ./include
SRCS_DIR			= ./src
OBJS_DIR			= ./obj

LIBFT 				= $(LIBFT_DIR)libft.a
LIBFT_DIR 			= ./libft/
LIBFT_H 			= $(LIBFT_DIR)

C_FILES				= main.c\
					minishell_linked_lists.c minishell_linked_lists2.c\
					minishell_linked_lists3.c minishell_linked_lists4.c\
					initialize_minishell.c\
					lexer.c lexer2.c\
					parser.c parser2.c parser3.c parser4.c\
					expander.c expander2.c expander3.c\
					expander4.c expander5.c\
					executor.c executor2.c executor3.c executor4.c\
					pipe.c pipe2.c\
					subshell.c\
					builtin.c builtin2.c builtin3.c builtin4.c\
					signal_handlers.c\
					heredoc.c\
					utils.c utils2.c utils3.c\
					
SRCS				= $(addprefix $(SRCS_DIR)/, $(C_FILES))
OBJS				= $(addprefix $(OBJS_DIR)/, $(C_FILES:.c=.o))

CC					= gcc
CFLAGS				= -g -Wall -Werror -Wextra $(INCS)
LFLAGS				=  -L$(LIBFT_DIR) -lreadline \
					-L$(HOME)/.brew/opt/readline/lib 
INCS				= -I$(HDRS_DIR) -I$(LIBFT_H)   
RM					= rm -rf
MKDIR				= mkdir -p

.DEFAULT_GOAL 		:= all

$(OBJS_DIR)/%.o 	: $(SRCS_DIR)/%.c 
					$(CC) $(CFLAGS) -c $< -o $@ 


$(OBJS_DIR) 		:
					$(MKDIR) $(MKDIRFLAGS) $(OBJS_DIR)

all 				: libft $(NAME) 

$(NAME) 			: $(SRCS) $(OBJS_DIR) $(OBJS)  $(LIBFT)
					$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBFT) -o $(NAME)

bonus 				: libft $(NAME)

libft				: 
					make -C $(LIBFT_DIR)

clean 				:
					make -C $(LIBFT_DIR) fclean
					$(RM)  $(OBJS)

fclean 				: clean
					make -C $(LIBFT_DIR) fclean
					$(RM)  $(NAME) $(OBJS_DIR) 

val 				: $(NAME)
					valgrind --leak-check=full --show-leak-kinds=all \
					 --track-origins=yes  --verbose \
					 --log-file=valgrind-out.txt \
         			./$(NAME)

re					: fclean all

.PHONY 				: all clean fclean re bonus libft val
