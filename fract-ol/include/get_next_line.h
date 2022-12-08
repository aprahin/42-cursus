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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		getnl(const char *s);
char	*trimtonl(char **s);
void	append(char **s, char **b);
char	*endread(char **s, char *b, int r);
int		makestr(char **s, int fd);
char	*get_next_line(int fd);

#endif
