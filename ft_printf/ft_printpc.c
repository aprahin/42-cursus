/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:03:38 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/10 14:22:25 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printpc(const char *flags, int width)
{
	int		l;

	l = 0;
	width -= 1;
	if (!ft_in('-', flags))
	{
		while (width-- > 0)
			l += ft_putchar(' ');
	}
	l += ft_putchar('%');
	while (width-- > 0)
		l += ft_putchar(' ');
	return (l);
}
