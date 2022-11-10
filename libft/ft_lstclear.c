/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:03:22 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/07 16:03:22 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*e;

	if (!(*lst))
		return ;
	while ((*lst)->next)
	{
		(*del)((*lst)->content);
		e = (*lst)->next;
		free(*lst);
		(*lst) = e;
	}
	(*del)((*lst)->content);
	free(*lst);
	*lst = 0;
}
