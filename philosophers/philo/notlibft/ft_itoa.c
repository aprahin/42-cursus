/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:55:28 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/09 15:01:28 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "notlibft.h"
#include <stdlib.h>

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

static void	neg(int *n, int *pm)
{
	if (*n < 0)
	{
		*n = -(*n);
		*pm = 1;
	}
	else
	{
		*pm = 0;
	}
	return ;
}

static void	setm(int *m, int *i)
{
	while (*m != 0)
	{
		*m /= 10;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		m;
	int		pm;

	i = 0;
	if (n == 0 || n == -2147483648)
		return (special(n));
	neg(&n, &pm);
	m = n;
	setm(&m, &i);
	s = malloc((pm + i + 1) * sizeof(char));
	if (!s)
		return (0);
	s[pm + i] = '\0';
	while (n != 0)
	{
		s[pm + (i--) - 1] = '0' + (n % 10);
		n /= 10;
	}
	if (pm)
		s[0] = '-';
	return (s);
}
