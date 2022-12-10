/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:12:21 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/09 15:01:28 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "notlibft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*e;
	t_list	*s;

	if (!lst)
		return (0);
	s = ft_lstnew((*f)(lst->content));
	if (!s)
		return (0);
	if (lst->next)
		e = s;
	while (lst->next)
	{
		e->next = ft_lstnew((*f)(lst->next->content));
		if (!(e->next))
		{
			ft_lstclear(&s, (del));
			return (0);
		}
		lst = lst->next;
		e = e->next;
	}
	return (s);
}
