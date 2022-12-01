/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:04:52 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/10 20:04:52 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(int count, int size);
int		ft_strlen(const char *s);
int		getnl(const char *s);
char	*trimtonl(char **s, char *b);
char	*ft_strjoin(char *s1, char *s2);
char	*endread(char **s, char *b, int r);
int		makefd(char **s, int fd);
char	*get_next_line(int fd);

#endif
