/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:35:34 by eprotsen          #+#    #+#             */
/*   Updated: 2022/11/28 05:50:55 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char *) s;
	while (i < n)
	{
		if (*buf == (unsigned char)c)
			return (buf);
		buf++;
		i++;
	}
	return (0);
}
