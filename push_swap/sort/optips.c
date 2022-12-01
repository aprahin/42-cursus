/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optips.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:48:16 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:18:58 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	rmmoves(char ***mlist, int i, int j)
{
	free((*mlist)[i]);
	(*mlist)[i] = "-";
	free((*mlist)[j]);
	(*mlist)[j] = "-";
	return (1);
}

static char	*mergemoves(char **mlist)
{
	int		i;
	char	*merged;

	i = 0;
	merged = ft_strdup("");
	while (mlist[i])
	{
		if (mlist[i][0] == '-')
		{
			++i;
			continue ;
		}
		merged = ft_strjoinf(merged, mlist[i], 1, 1);
		merged = ft_strjoinf(merged, "\n", 1, 0);
		++i;
	}
	return (merged);
}

static int	checkdoubles(char ***mlist, int i)
{
	int	j;
	int	rmd;

	j = i + 1;
	rmd = 0;
	if ((*mlist)[i][0] == 'p' || (*mlist)[i][0] == 's')
	{
		while ((*mlist)[j])
		{
			if ((*mlist)[j][0] == '-')
				++j;
			else
				break ;
		}
		if (!(*mlist)[j])
			return (i + 1);
		if ((*mlist)[i][0] == 'p' && (*mlist)[j][0] == 'p'
		&& ft_strncmp((*mlist)[i], (*mlist)[j], 2))
			rmd = rmmoves(mlist, i, j);
		if ((*mlist)[i][0] == 's' && !ft_strncmp((*mlist)[i], (*mlist)[j], 2))
			rmd = rmmoves(mlist, i, j);
	}
	if (rmd)
		return (0);
	return (i + 1);
}

char	*optips(char *moves)
{
	char	**mlist;
	char	*opti;
	int		i;

	mlist = ft_split(moves, '\n');
	i = 0;
	while (mlist[i])
	{
		if (mlist[i][0] != '-')
			i = checkdoubles(&mlist, i);
		else
			++i;
	}
	opti = mergemoves(mlist);
	free(moves);
	free(mlist);
	return (opti);
}
