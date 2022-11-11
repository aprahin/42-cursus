/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:20:05 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/06 10:20:05 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	getflags(const char *f, char **flags, unsigned int *i)
{
	while (ft_in(f[*i], "-+ #0"))
	{
		if (!ft_in(f[*i], *flags))
			ft_addchar(flags, f[*i], 1);
		(*i)++;
	}
}

static void	purgeflags(char **flags)
{
	if (ft_in((*flags)[0], "xX"))
		ft_removechar(flags, "+ ");
	else if (ft_in((*flags)[0], "idu"))
		ft_removechar(flags, "#");
	else if (ft_in((*flags)[0], "cp"))
		ft_removechar(flags, ".+ #0");
	else
		ft_removechar(flags, "+ #0");
	if (ft_in('+', *flags))
		ft_removechar(flags, " ");
	if (ft_in(('-'), *flags) || ft_in(('.'), *flags))
		ft_removechar(flags, "0");
}

static int	callprint(char *flags, int width, int prec, va_list args)
{
	if (ft_in(flags[0], "diu"))
		return (ft_printnbr(flags, width, prec, args));
	else if (ft_in(flags[0], "xX"))
		return (ft_printhex(flags, width, prec, args));
	else if (flags[0] == 's')
		return (ft_printstr(flags, width, prec, args));
	else if (flags[0] == 'c')
		return (ft_printchar(flags, width, args));
	else if (flags[0] == 'p')
		return (ft_printptr(flags, width, args));
	else if (flags[0] == '%')
		return (ft_printpc(flags, width));
	return (0);
}

static unsigned int	putpc(const char *format,
	unsigned int i, va_list args, int *n)
{
	char	*flags;
	int		width;
	int		prec;

	flags = ft_calloc(8, sizeof(char));
	if (!flags)
		return (-1);
	flags[0] = '_';
	prec = -1;
	getflags(format, &flags, &i);
	width = ft_atoi(format + i);
	while (ft_in(format[i], "0123456789"))
		++i;
	if (format[i] == '.')
	{
		ft_addchar(&flags, '.', 1);
		prec = ft_atoi(format + i + 1);
	}
	while (ft_in(format[i], ".0123456789"))
		++i;
	flags[0] = format[i];
	purgeflags(&flags);
	*n += callprint(flags, width, prec, args);
	free(flags);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				n;
	unsigned int	i;

	i = 0;
	n = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i++]);
			n++;
			continue ;
		}
		if (!ft_in(format[++i], "cspdiuxX%+0 #-.0123456789"))
			continue ;
		i = putpc(format, i, args, &n) + 1;
	}
	va_end(args);
	return (n);
}
