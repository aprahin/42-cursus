/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:20:52 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/10 17:14:25 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static char	*sdup(const char *src)
{
	int		i;
	char	*s;

	i = 0;
	if (!src)
		return ((char *) src);
	while (src[i] != '\0')
		++i;
	s = malloc(i + 1);
	if (!s)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		s[i] = src[i];
		++i;
	}
	s[i] = '\0';
	return (s);
}

static void	setwidth(int *width, const char *s, int prec)
{
	if (prec >= 0)
		*width -= min(prec, ft_strlen(s));
	else
		*width -= ft_strlen(s);
}

int	ft_printstr(const char *flags, int width, int prec, va_list args)
{
	char	*s;
	int		l;
	int		i;

	l = 0;
	i = 0;
	s = sdup(va_arg(args, char *));
	if (!s)
	{
		s = ft_calloc(7, sizeof(char));
		if (!s)
			return (0);
		ft_strlcpy(s, "(null)", 7);
	}
	if (!s)
		return (0);
	setwidth(&width, s, prec);
	while (!ft_in('-', flags) && width-- > 0)
		l += ft_putchar(' ');
	while (prec-- != 0 && s[i] != '\0')
		l += ft_putchar(s[i++]);
	while (width-- > 0)
		l += ft_putchar(' ');
	free(s);
	return (l);
}
