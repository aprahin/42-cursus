/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:03:35 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/09 22:03:35 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*lutoh(unsigned long n, const char *hex)
{
	char				*s;
	int					i;
	unsigned long		m;

	m = n;
	i = 0;
	while (m > 0)
	{
		m /= 16;
		i++;
	}
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (0);
	while (i > 0)
	{
		s[i - 1] = hex[n % 16];
		--i;
		n /= 16;
	}
	return (s);
}

static void	allocptr(char **s, uintptr_t p)
{
	char	*t;

	if (!p)
	{
		*s = ft_calloc(6, sizeof(char));
		if (!(*s))
			return ;
		ft_strlcpy(*s, "0x0", 4);
	}
	else
	{
		t = lutoh(p, "0123456789abcdef");
		if (!t)
			return ;
		*s = ft_strjoin("0x", t);
		free(t);
	}
}

int	ft_printptr(const char *flags, int width, va_list args)
{
	uintptr_t	p;
	char		*s;
	int			l;

	s = NULL;
	p = va_arg(args, uintptr_t);
	allocptr(&s, p);
	if (!s)
		return (0);
	l = ft_strlen(s);
	width -= ft_strlen(s);
	while (!ft_in('-', flags) && width-- > 0)
		l += ft_putchar(' ');
	ft_putstr(s);
	while (width-- > 0)
		l += ft_putchar(' ');
	free(s);
	return (l);
}
