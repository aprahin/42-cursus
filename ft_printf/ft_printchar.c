/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:31:09 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/09 21:31:09 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printchar(const char *flags, int width, va_list args)
{	
	char	c;
	int		l;

	l = 0;
	c = (unsigned char) va_arg(args, int);
	if (!c)
		l++;
	width -= 1;
	if (!ft_in('-', flags))
	{
		while (width-- > 0)
			l += ft_putchar(' ');
	}
	if (!c)
		ft_putchar(0);
	else
		l += ft_putchar(c);
	while (width-- > 0)
		l += ft_putchar(' ');
	return (l);
}
