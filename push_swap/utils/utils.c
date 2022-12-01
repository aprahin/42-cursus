/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:41:10 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:03:30 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	checklimits(int argc, char **argv)
{
	int		i;
	int		j;
	char	*max;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		max = "2147483647";
		while (argv[i][j] == '\t' || argv[i][j] == '\n' || argv[i][j] == '\v'
			|| argv[i][j] == '\f' || argv[i][j] == '\r' || argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (argv[i][j++] == '-')
				max = "2147483648";
		}
		if (ft_strlen(argv[i] + j) < 10)
			continue ;
		if (ft_strlen(argv[i] + j) > 10 || ft_strncmp(argv[i] + j, max, 11) > 0)
			return (0);
	}
	return (1);
}

static void	advance(char *s, int *i)
{
	while (s[*i] == '\t' || s[*i] == '\n' || s[*i] == '\v'
		|| s[*i] == '\f' || s[*i] == '\r' || s[*i] == ' ')
		++(*i);
	if (s[*i] == '+' || s[*i] == '-')
		++(*i);
}

int	checkargs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		advance(argv[i], &j);
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		}
		j = 0;
		while (++j < argc)
		{
			if (i != j && ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
		}
	}
	if (checklimits(argc, argv))
		return (1);
	return (0);
}
