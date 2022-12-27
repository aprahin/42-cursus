NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar
ARFLAGS		= -rcs
RM			= rm -rf

INCS_DIR	= ./incs

LIBFT_DIR		= ./srcs/libft
LIBFT			= ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_lstsize.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				get_first_heap.c\
				hcalloc.c\
				hfree.c\
				hmalloc.c\
				hobliterate.c\
				ptr_move.c\

GNL_DIR			= ./srcs/get_next_line
GNL				= get_next_line.c\
				get_next_line_utils.c

FT_PRINTF_DIR	= ./srcs/ft_printf
FT_PRINTF		= ft_printf.c\
				ft_printf_put.c\
				ft_print_format.c\
				ft_print_arg.c

all: $(NAME)

$(NAME): libft gnl ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $^ -o $@
	$(AR) $(ARFLAGS) $(NAME) $@

libft: $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
ft_printf: $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

clean:
	$(RM) $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
	$(RM) $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF:.c=.o))
	$(RM) $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft gnl ft_printf
