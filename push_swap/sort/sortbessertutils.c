/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbessertutils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:30:25 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:40:08 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	setrottop(t_stack *b, t_rot *rots)
{
	int	j;

	j = 0;
	while (j < stack_getsize(b))
	{
		if (stack_getn(b, j) == getmax(b))
		{
			rots->rset = j;
			rots->rrset = (stack_getsize(b) - j) % stack_getsize(b);
			return ;
		}
		++j;
	}
}

void	setrotmid(t_stack *b, t_rot *rots, int n)
{
	int	j;

	j = 0;
	while (1)
	{
		if (j + 1 >= stack_getsize(b))
		{
			rots->rset = 0;
			rots->rrset = 0;
			return ;
		}
		if (stack_getn(b, j) > n
			&& stack_getn(b, j + 1) < n)
		{
			rots->rset = j + 1;
			rots->rrset = stack_getsize(b) - j - 1;
			return ;
		}
		j++;
	}
}

static void	setrr(t_rot *rots, int rgrs)
{
	rots->rrget = 0;
	rots->rrset = 0;
	rots->rr = ft_min(rots->rget, rots->rset);
	rots->rget -= rots->rr;
	rots->rset -= rots->rr;
	rots->total = rgrs;
}

static void	setrrr(t_rot *rots, int rrgrrs)
{
	rots->rget = 0;
	rots->rset = 0;
	rots->rrr = ft_min(rots->rrget, rots->rrset);
	rots->rrget -= rots->rrr;
	rots->rrset -= rots->rrr;
	rots->total = rrgrrs;
}

void	setbest(t_rot *rots)
{
	int	rgrs;
	int	rrgrrs;
	int	rgrrs;
	int	rrgrs;

	rgrrs = rots->rget + rots->rrset;
	rrgrs = rots->rrget + rots->rset;
	rgrs = ft_max(rots->rget, rots->rset);
	rrgrrs = ft_max(rots->rrget, rots->rrset);
	if (rgrrs <= rrgrs && rgrrs <= rgrs && rgrrs <= rrgrrs)
	{
		rots->rrget = 0;
		rots->rset = 0;
		rots->total = rgrrs;
	}
	else if (rrgrs <= rgrrs && rrgrs <= rgrs && rrgrs <= rrgrrs)
	{
		rots->rget = 0;
		rots->rrset = 0;
		rots->total = rrgrs;
	}
	else if (rgrs <= rgrrs && rgrs <= rrgrs && rgrs <= rrgrrs)
		setrr(rots, rgrs);
	else
		setrrr(rots, rrgrrs);
}
