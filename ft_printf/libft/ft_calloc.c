/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:48:04 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/31 16:23:56 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*c_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p = (unsigned char) c;
		p++;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;
	void	*s;

	if (count == 0 || size == 0)
	{
		s = malloc(1);
		return (s);
	}
	array = malloc(count * size);
	if (!array)
		return (0);
	return (c_memset(array, 0, count * size));
}
