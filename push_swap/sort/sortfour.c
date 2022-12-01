/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfour.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:52:54 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/30 00:26:50 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static char	*getmorecase(char	*mark)
{
	if (!ft_strncmp(mark, "3 1 2 4", 7))
		return (ft_strdup("rra\nsa\nrr\nrr\n"));
	if (!ft_strncmp(mark, "3 1 4 2", 7))
		return (ft_strdup("ra\nsa\nra\n"));
	if (!ft_strncmp(mark, "3 2 1 4", 7))
		return (ft_strdup("rra\nsa\nrr\nrr\nsa\n"));
	if (!ft_strncmp(mark, "3 2 4 1", 7))
		return (ft_strdup("sa\nrra\n"));
	if (!ft_strncmp(mark, "3 4 1 2", 7))
		return (ft_strdup("ra\nra\n"));
	if (!ft_strncmp(mark, "3 4 2 1", 7))
		return (ft_strdup("ra\nra\nsa\n"));
	if (!ft_strncmp(mark, "4 1 2 3", 7))
		return (ft_strdup("ra\n"));
	if (!ft_strncmp(mark, "4 1 3 2", 7))
		return (ft_strdup("ra\nra\nsa\nrra\n"));
	if (!ft_strncmp(mark, "4 2 1 3", 7))
		return (ft_strdup("ra\nsa\n"));
	if (!ft_strncmp(mark, "4 2 3 1", 7))
		return (ft_strdup("rra\nsa\nra\n"));
	if (!ft_strncmp(mark, "4 3 1 2", 7))
		return (ft_strdup("sa\nra\nra\n"));
	if (!ft_strncmp(mark, "4 3 2 1", 7))
		return (ft_strdup("sa\nra\nra\nsa\n"));
	return (ft_strdup(""));
}

static char	*getcase(char	*mark)
{
	if (!ft_strncmp(mark, "1 2 3 4", 7))
		return (ft_strdup(""));
	if (!ft_strncmp(mark, "1 2 4 3", 7))
		return (ft_strdup("pb\nrra\nsa\npa\n"));
	if (!ft_strncmp(mark, "1 3 2 4", 7))
		return (ft_strdup("pb\nsa\npa\n"));
	if (!ft_strncmp(mark, "1 3 4 2", 7))
		return (ft_strdup("rra\nsa\n"));
	if (!ft_strncmp(mark, "1 4 2 3", 7))
		return (ft_strdup("sa\nra\n"));
	if (!ft_strncmp(mark, "1 4 3 2", 7))
		return (ft_strdup("pb\nra\nsa\npa\n"));
	if (!ft_strncmp(mark, "2 1 3 4", 7))
		return (ft_strdup("sa\n"));
	if (!ft_strncmp(mark, "2 1 4 3", 7))
		return (ft_strdup("sa\npb\nrra\nsa\npa\n"));
	if (!ft_strncmp(mark, "2 3 1 4", 7))
		return (ft_strdup("ra\nra\nsa\nra\n"));
	if (!ft_strncmp(mark, "2 3 4 1", 7))
		return (ft_strdup("rra\n"));
	if (!ft_strncmp(mark, "2 4 1 3", 7))
		return (ft_strdup("rra\nsa\nrra\n"));
	if (!ft_strncmp(mark, "2 4 3 1", 7))
		return (ft_strdup("ra\nsa\nra\nra\n"));
	return (getmorecase(mark));
}

char	*sortfour(t_stack *a)
{
	char	*mark;
	char	*moves;

	mark = stack_getmark(a);
	moves = getcase(mark);
	free(mark);
	return (moves);
}
