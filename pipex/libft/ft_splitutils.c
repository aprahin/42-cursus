/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:56:59 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/04 23:07:15 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	switchedq(int *quote, int *depth, char *lastquote)
{
	*depth -= 1;
	if (*depth == 0)
	{
		*lastquote = 0;
		*quote = (*quote + 1) % 2;
	}
	else
	{
		if (*lastquote == '\'')
			*lastquote = '"';
		else
			*lastquote = '\'';
	}
}

int	checkquote(int *quote, const char *s, int i)
{
	static char	lastquote;
	static int	depth;
	int			ret;

	ret = *quote;
	if ((s[i] == '"' || s[i] == '\'') && !(s[i - 1] && s[i - 1] == '\\'))
	{
		if (!lastquote)
		{
			lastquote = s[i];
			depth = 1;
			*quote = (*quote + 1) % 2;
		}
		else if (lastquote == s[i])
			switchedq(quote, &depth, &lastquote);
		else
		{
			lastquote = s[i];
			depth += 1;
		}
	}
	return (ret);
}
