/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:37:44 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/06 21:37:44 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	freeflags(char **flags)
{
	free(*flags);
	return (0);
}

static void	parsenbr(const char *f, unsigned int *i, char **flags, int b)
{
	unsigned int	j;

	j = 0;
	if (b)
	{
		while ((*flags)[j] != '\0')
			++j;
		(*flags)[j] = '.';
	}
	++(*i);
	if (ft_in(f[*i], "123456789"))
		++(*i);
	while (ft_in(f[*i], "0123456789"))
		++(*i);
}

static void	parseflags(const char *f, unsigned int *i, char **flags)
{
	int	j;

	(*i)--;
	*flags = ft_calloc(7, sizeof(char));
	if (!(*flags))
		return ;
	while (ft_in(f[*i], "-+ #0"))
	{
		j = 0;
		if (!ft_in(f[*i], *flags))
		{
			while ((*flags)[j] != '\0')
				++j;
			(*flags)[j] = f[*i];
		}
		(*i)++;
	}
}

/*static int	isvalid(const char *f, const char t)
{
	int	i;

	i = -1;
	while (f[++i] != '\0')
	{
		if (f[i % 3] == '.' && (ft_in(f[(i + 1) % 3], ".")
				|| ft_in(f[(i + 2) % 3], ".") || ft_in(t, "p")))
			return (0);
		if (f[i % 3] == '+' && (ft_in(f[(i + 1) % 3], "+ #")
				|| ft_in(f[(i + 2) % 3], "+ #") || ft_in(t, "cspuxX")))
			return (0);
		if (f[i % 3] == '-' && (ft_in(f[(i + 1) % 3], "-")
				|| ft_in(f[(i + 2) % 3], "-")))
			return (0);
		if (f[i % 3] == ' ' && (ft_in(f[(i + 1) % 3], "+ #")
				|| ft_in(f[(i + 2) % 3], "+ #") || ft_in(t, "cpuxX")))
			return (0);
		if (f[i % 3] == '#' && (ft_in(f[(i + 1) % 3], "+ #")
				|| ft_in(f[(i + 2) % 3], "+ #") || ft_in(t, "cspdiu")))
			return (0);
		if (f[i % 3] == '0' && (ft_in(f[(i + 1) % 3], "0")
				|| ft_in(f[(i + 2) % 3], "0") || ft_in(t, "cp")))
			return (0);
	}
	return (1);
}*/

int	ft_parse(const char *f, char **p)
{
	unsigned int	i;
	unsigned int	j;
	char			*flags;

	i = 0;
	j = 0;
	while (f[i] != '\0')
	{
		if (f[i++] != '%')
			continue ;
		if (f[i++] == '%')
			continue ;
		parseflags(f, &i, &flags);
		parsenbr(f, &i, &flags, 0);
		if (f[i] == '.')
			parsenbr(f, &i, &flags, 1);
		if (!ft_in(f[i], "cspdiuxX%"))
			return (freeflags(&flags));
		//if (!isvalid((const char *) flags, f[i]))
		//	return (freeflags(&flags));
		(*p)[j++] = f[i++];
		freeflags(&flags);
	}
	return (1);
}
