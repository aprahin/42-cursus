/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:40 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/08 17:05:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	lputchar(const char *flags, int *width, int neg, int *l)
{
	if ((ft_in('+', flags) || ft_in(' ', flags)) && !neg)
		(*width) -= 1;
	while (!ft_in('-', flags) && !ft_in('0', flags) && (*width)-- > 0)
		(*l) += ft_putchar(' ');
	if (neg)
		(*l) += ft_putchar('-');
	if (ft_in('+', flags) && !neg)
		(*l) += ft_putchar('+');
	else if (ft_in(' ', flags) && !neg)
		(*l) += ft_putchar(' ');
	while (!ft_in('-', flags) && ft_in('0', flags) && (*width)-- > 0)
		(*l) += ft_putchar('0');
}

static void	setnpw(char **s, int *neg, int *prec, int *width)
{
	if ((*s)[0] == '-')
		*neg = 1;
	if (*prec == 0 && (*s)[0] == '0')
		(*s)[0] = '\0';
	if (*prec == -1)
		*prec = 0;
	*prec -= ft_strlen(*s) - *neg;
	*width -= ft_strlen(*s);
	if (*prec > 0)
		*width -= *prec;
}

int	ft_printnbr(const char *flags, int width, int prec, va_list args)
{
	char	*s;
	int		l;
	int		neg;

	neg = 0;
	l = 0;
	if (flags[0] == 'u')
		s = ft_utoa(va_arg(args, int));
	else
		s = ft_itoa(va_arg(args, int));
	if (!s)
		return (0);
	setnpw(&s, &neg, &prec, &width);
	lputchar(flags, &width, neg, &l);
	while (prec-- > 0)
		l += ft_putchar('0');
	l += ft_putstr(s + neg);
	while (width-- > 0)
		l += ft_putchar(' ');
	free(s);
	return (l);
}
