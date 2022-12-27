/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_linked_lists.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:08:29 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 12:32:32 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_linked_lists.h"

//
//cmp_k_f is used by set_val() to find the node with the arg key
//
t_lst	*new_tlst(t_cmp_key_f cmp_k, t_dstr_key_f dstr_k, t_dstr_val_f dstr_v)
{
	t_lst	*list;

	list = (t_lst *)hmalloc(sizeof(t_lst));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->cmp_k = cmp_k;
	list->dstr_k = dstr_k;
	list->dstr_v = dstr_v;
	list->size = 0;
	return (list);
}

t_key_val_lst	*new_key_val_tlst(void *key, void *val)
{
	t_key_val_lst	*elem;

	elem = (t_key_val_lst *)hmalloc(sizeof(t_key_val_lst));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->val = val;
	elem->next = NULL;
	return (elem);
}

//
//add new node at the end of the existing minishell lst
//
int	add_node(t_lst *list, void *key, void *val)
{
	t_key_val_lst	*ptr;

	if (!list)
		return (EXIT_FAILURE);
	if (!list->head)
	{
		list->head = new_key_val_tlst(key, val);
		if (list->head)
			++(list->size);
		return (!(list->head));
	}
	ptr = list->head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_key_val_tlst(key, val);
	if (ptr->next)
		++(list->size);
	return (!(ptr->next));
}

static void	rm_key_val_lst_node(t_lst *list, t_key_val_lst *elem,
		t_key_val_lst *prev)
{
	if (prev)
		prev->next = elem->next;
	else
		list->head = elem->next;
	if (list->dstr_k)
		list->dstr_k(elem->key);
	if (list->dstr_v)
		list->dstr_v(elem->val);
	hfree(elem);
	--(list->size);
}

//
//erases key or/and val of t_key_val_lst if dstr_f is not NULL
//
int	rm_tlst_node(t_lst *list, const void *key)
{
	t_key_val_lst	*ptr;
	t_key_val_lst	*prev;

	if (!list)
		return (EXIT_FAILURE);
	if (!(list->size))
		return (EXIT_SUCCESS);
	ptr = list->head;
	prev = NULL;
	while (ptr)
	{
		if (!(list->cmp_k(key, ptr->key)))
		{
			rm_key_val_lst_node(list, ptr, prev);
			return (EXIT_SUCCESS);
		}
		prev = ptr;
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}
