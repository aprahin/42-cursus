/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optirot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:13:54 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/30 13:24:15 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	getrevs(int rn, int l)
{
	if (l % 2 == 1)
	{
		if (rn > (l / 2) + 1)
			return (l - rn);
		return (0);
	}
	else
	{
		if (rn > (l / 2))
			return (l - rn);
		return (0);
	}
}

static void	rmrot(char ***mlist, int *i, char *rot, int size)
{
	int		j;

	j = *i;
	while ((*mlist)[j] && ft_strncmp((*mlist)[j], rot, 2) == 0)
		++j;
	j = getrevs(j - *i, size);
	if (j > 0)
	{
		while (j-- > 0)
		{
			free((*mlist)[*i]);
			(*mlist)[(*i)++] = ft_strjoin("r", rot);
		}
		while ((*mlist)[*i] && ft_strncmp((*mlist)[*i], rot, 2) == 0)
		{
			free((*mlist)[*i]);
			(*mlist)[*i] = "-";
			++(*i);
		}
	}
	else
		++(*i);
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

static void	updatepush(char **mlist, char *rot, int *size, int i)
{
	if (mlist[i][0] == 'p')
	{
		if ((mlist[i][1] == 'a' && ft_strchr(rot, 'a'))
			|| (mlist[i][1] == 'b' && ft_strchr(rot, 'b')))
			(*size)++;
		else
			(*size)--;
	}
}

char	*optirot(char *moves, char *rot, int size)
{
	char	**mlist;
	char	*opti;
	int		i;

	mlist = ft_split(moves, '\n');
	i = 0;
	while (mlist[i])
	{
		if (ft_strncmp(mlist[i], rot, 2) == 0 && ft_strlen(rot) == 2)
			rmrot(&mlist, &i, rot, size);
		else if (ft_strncmp(mlist[i], rot, 3) == 0 && ft_strlen(rot) == 3)
			rmrot(&mlist, &i, rot, size);
		else
		{
			updatepush(mlist, rot, &size, i);
			++i;
		}
	}
	opti = mergemoves(mlist);
	free(moves);
	free(mlist);
	return (opti);
}
