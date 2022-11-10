/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:52:48 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/25 16:56:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (void *) s1;
	q = (void *) s2;
	while (n > 0)
	{
		if (*p != *q)
			return (*p - *q);
		p++;
		q++;
		n--;
	}
	return (0);
}
