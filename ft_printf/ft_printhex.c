/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:33 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/10 17:19:33 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_setwidth_putchar(const char *flags, int *width, char *s, int *l)
{
	(*width) -= ft_strlen(s);
	if ((ft_in('+', flags) || ft_in(' ', flags)))
		(*width) -= 1;
	if (ft_in('#', flags) && (ft_strncmp(s, "0", 2)) && s[0])
		(*width) -= 2;
	while (!ft_in('-', flags) && !ft_in('0', flags) && (*width)-- > 0)
		(*l) += ft_putchar(' ');
	if (ft_in('+', flags))
		(*l) += ft_putchar('+');
	else if (ft_in(' ', flags))
		(*l) += ft_putchar(' ');
	else if (ft_in('#', flags) && (ft_strncmp(s, "0", 2)) && s[0])
	{
		(*l) += ft_putchar('0');
		(*l) += ft_putchar(flags[0]);
	}
	while (!ft_in('-', flags) && ft_in('0', flags) && (*width)-- > 0)
		(*l) += ft_putchar('0');
}

int	ft_printhex(const char *flags, int width, int prec, va_list args)
{
	char	*s;
	int		l;

	l = 0;
	if (flags[0] == 'x')
		s = ft_itoh(va_arg(args, int), "0123456789abcdef");
	else
		s = ft_itoh(va_arg(args, int), "0123456789ABCDEF");
	if (!s)
		return (0);
	if (prec == 0 && s[0] == '0')
		s[0] = '\0';
	if (prec == -1)
		prec = 0;
	prec -= ft_strlen(s);
	if (prec > 0)
		width -= prec;
	ft_setwidth_putchar(flags, &width, s, &l);
	while (prec-- > 0)
		l += ft_putchar('0');
	l += ft_putstr(s);
	while (width-- > 0)
		l += ft_putchar(' ');
	free(s);
	return (l);
}
