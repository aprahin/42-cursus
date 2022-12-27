/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_linked_lsts2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:02:26 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/13 20:08:46 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_linked_lists.h"

//
//when value for they key is found rewrite value
//some values should be hfreed before rewrite - if dstr_f hfree() is used
//if new_tlst_pair failed returns EXIT_FAILURE (1), otherwise EXIT_SUCCESS (0)
//
int	set_val(t_lst *list, void *key, void *new_val)
{
	t_key_val_lst	*ptr;

	if (!list)
		return (EXIT_FAILURE);
	if (!(list->size))
		return (add_node(list, key, new_val));
	ptr = list->head;
	while (1)
	{
		if (!(list->cmp_k(key, ptr->key)))
		{
			if (list->dstr_v)
				list->dstr_v(ptr->val);
			ptr->val = new_val;
			return (EXIT_SUCCESS);
		}
		if (ptr->next)
			ptr = ptr->next;
		else
			break ;
	}
	ptr->next = new_key_val_tlst(key, new_val);
	if (ptr->next)
		++(list->size);
	return (!(ptr->next));
}

//
//return value, or NULL if none found
//
void	*get_val(t_lst *list, const void *key)
{
	t_key_val_lst	*ptr;

	if (!list || !(list->size))
		return (NULL);
	ptr = list->head;
	while (ptr)
	{
		if (!(list->cmp_k(key, ptr->key)))
			return (ptr->val);
		ptr = ptr->next;
	}
	return (NULL);
}

//
//return 0 if no value to be found, 1 otherwise
//
int	lst_has_key(t_lst *list, const void *key)
{
	t_key_val_lst	*ptr;

	ptr = list->head;
	while (ptr)
	{
		if (!(list->cmp_k(ptr->key, key)))
			return (EXIT_FAILURE);
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}

//
//t_cmp_key_f 
//
int	cmp_int_keys(const void *k1, const void *k2)
{
	if (*(int *)&k1 == *(int *)&k2)
		return (EXIT_SUCCESS);
	if (*(int *)&k1 < *(int *)&k2)
		return (-1);
	return (EXIT_FAILURE);
}

//
//t_cmp_key_f 
//
int	cmp_str_keys(const void *k1, const void *k2)
{
	return (ft_strncmp((const char *)k1, (const char *)k2,
			ft_strlen((const char *)k1) + 1));
}
