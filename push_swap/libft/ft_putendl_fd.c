/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:57:35 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/31 11:19:52 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	t[1];

	i = 0;
	t[0] = '\n';
	while (s[i] != '\0')
		++i;
	write(fd, (void *) s, i);
	write(fd, (void *) t, 1);
	return ;
}
