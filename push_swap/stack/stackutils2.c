/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:43:39 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:10:40 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char	*stack_getmark(t_stack *self)
{
	t_stack	*tmp;
	char	*mark;
	int		i;

	tmp = stack_dup(self);
	stack_index(tmp);
	mark = ft_strdup("");
	i = 0;
	while (i < stack_getsize(tmp))
	{
		if (i != 0)
			mark = ft_strjoinf(mark, " ", 1, 0);
		mark = ft_strjoinf(mark, ft_itoa(stack_getn(tmp, i)), 1, 1);
		++i;
	}
	stack_destroy(tmp);
	return (mark);
}

void	stack_index(t_stack *a)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		minpos;
	int		lmpos;

	tmp = stack_dup(a);
	i = -1;
	lmpos = -1;
	while (++i < stack_getsize(a))
	{
		minpos = -1;
		j = -1;
		while (++j < stack_getsize(a))
		{
			if (((minpos < 0 && stack_getn(tmp, j) > stack_getn(tmp, lmpos))
					|| (stack_getn(tmp, j) <= stack_getn(tmp, minpos)
						&& (lmpos < 0
							|| stack_getn(tmp, j) > stack_getn(tmp, lmpos)))))
				minpos = j;
		}
		stack_setn(a, i + 1, minpos);
		lmpos = minpos;
	}
	stack_destroy(tmp);
}
