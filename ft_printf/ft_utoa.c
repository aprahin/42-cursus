/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:25:56 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/09 01:25:56 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*special(int n)
{
	char	*s;
	char	*t;
	int		i;

	t = "-2147483648";
	i = 10;
	if (n == 0)
	{
		s = malloc(2 * sizeof(char));
		if (!s)
			return (0);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	s = malloc(12 * sizeof(char));
	if (!s)
		return (0);
	while (i >= 0)
	{
		s[i] = t[i];
		i--;
	}
	s[11] = '\0';
	return (s);
}

static void	neg(unsigned int *n, int o)
{
	if (o < 0)
	{
		*n = 4294967295 + o + 1;
	}
	else
	{
		*n = o;
	}
	return ;
}

static void	setm(unsigned int *m, int *i)
{
	while (*m != 0)
	{
		*m /= 10;
		(*i)++;
	}
}

char	*ft_utoa(unsigned int o)
{
	char				*s;
	int					i;
	unsigned int		n;
	unsigned int		m;

	i = 0;
	if (o == 0)
		return (special(o));
	neg(&n, o);
	m = n;
	setm(&m, &i);
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (0);
	s[i] = '\0';
	while (n != 0)
	{
		s[(i--) - 1] = '0' + (n % 10);
		n /= 10;
	}
	return (s);
}
