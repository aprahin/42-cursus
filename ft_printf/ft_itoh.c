/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:47 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/08 16:51:32 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*special(int n)
{
	char	*s;
	char	*t;
	int		i;

	t = "80000000";
	i = 7;
	if (n == 0)
	{
		s = malloc(2 * sizeof(char));
		if (!s)
			return (0);
		ft_bzero(s, 2);
		s[0] = '0';
		return (s);
	}
	s = ft_calloc(9, sizeof(char));
	if (!s)
		return (0);
	while (i >= 0)
	{
		s[i] = t[i];
		i--;
	}
	s[8] = '\0';
	return (s);
}

static char	*addone(char *s, const char *hex)
{
	int	l;

	l = 7;
	while (ft_in(s[l], "fF"))
		s[l--] = '0';
	s[l] = hex[ft_in(s[l], hex)];
	return (s);
}

static char	*negitoh(int n, const char *hex)
{
	char	*s;
	int		i;
	int		m;

	m = n;
	i = 0;
	while (m > 0)
	{
		m /= 16;
		i++;
	}
	s = ft_calloc(9, sizeof(char));
	if (!s)
		return (0);
	m = 9 - i;
	while (--m > 0)
		s[m - 1] = hex[15];
	while (m++ < i)
	{
		s[8 - m] = hex[15 - (n % 16)];
		n /= 16;
	}
	return (addone(s, hex));
}

char	*ft_itoh(int n, const char *hex)
{
	char	*s;
	int		i;
	int		m;

	if (n == 0 || n == -2147483648)
		return (special(n));
	else if (n < 0)
		return (negitoh(-n, hex));
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
