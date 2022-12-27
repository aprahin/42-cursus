/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:13:43 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 00:29:51 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-R CheckForbiddenSourceHeader
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "halloc.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_count
{
	char			format_char;
	char			type_c;
	char			*type_s;
	long			type_d_i;
	unsigned int	type_u;
	unsigned int	type_x_x;
	unsigned long	type_p;
	int				chars_printed;
}	t_count;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
/*
incomplete type 'void' is not assignable
undefined behavior if dest||src NULL.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/*
ft_strlcat(NULL, b, 0);
if size < dst_len, returns size + src_len w/o null termination
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
/*
we need f functionality for both const str and non-const str
with no function overloading we do it by returning non-const ptr
*/
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
//the dif between chars values interpreted as unsigned char C99
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//c and s contents are interpreted as unsigned char.
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
/*
if n int out of the range of int - undefined behavior.
-2147483648 input * (-1) -> (2147483648>2147483647)-2147483648
*/
int		ft_atoi(const char *nptr);
// mem is set to 0.  If nmemb or size is 0 returns NULL 
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
//-2147483648 input * (-1) -> (2147483648>2147483647)-2147483648
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
/*
lst ptr to the head of the linked list
if new is NULL new->next may segfault
*/
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
//free(NULL) results in noargction
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(const char *s, ...);
void	print_format_string(const char *s, t_count *print, va_list args);
void	clear_struct(t_count *print);

void	print_arg(t_count *print, va_list args);
void	print_arg2(t_count *print, va_list args);
void	printf_putchar(t_count *print, char c, int fd);
void	printf_putstr(t_count *print, char *str, int fd);
void	printf_putnbr(t_count *print, int nbr, int fd);
void	print_u(t_count *print, unsigned int nbr, int fd);
void	print_x(t_count *print, unsigned int nbr, int fd);
void	print_p(t_count *print, unsigned long nbr, int fd);

char	*get_next_line(int fd);
char	*read_until_nl(int fd, char *str);
char	*chars_before_nl(char *str);
char	*chars_after_nl(char *str);

size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlcpy(char	*dst, const char *src, size_t size);
char	*gnl_strjoin(char *s1, char *s2);

#endif
