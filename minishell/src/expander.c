/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:25:53 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 11:38:57 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/expander.h"

static void	add_expanded_tkn(t_lst **str, t_key_val_lst **ptr)
{
	*str = new_tlst(cmp_int_keys, NULL, NULL);
	add_node(*str, (*ptr)->key, (*ptr)->val);
	while ((*ptr)->next && is_expandable(((t_key_val_lst *)(*ptr)->next)->key))
	{
		(*ptr) = (*ptr)->next;
		add_node(*str, (*ptr)->key, (*ptr)->val);
	}
}

static int	write_expanded(t_key_val_lst **ptr, t_lst *expanded, t_shell *info)
{
	char				*word;
	t_lst				*words;
	t_lst				*str;
	static t_exp		texp;

	if (*(int *)&(*ptr)->key == LEX_KEY_HEREDOC)
		texp.f = 1;
	if (is_expandable((*ptr)->key))
	{
		add_expanded_tkn(&str, ptr);
		if (expand_segment(str, info, &word, &texp) == 1)
			return (hfree_tlst_ret1(str));
		if (!word)
			return (hfree_tlst_ret0(str));
		words = expand_asterisk(word);
		ft_to_wildcard(&word);
		if (!words)
			add_node(expanded, (void *)LEX_KEY_WORD, word);
		else
			add_expanded_tkn2(expanded, word, words);
		hfree_tlst(str);
	}
	else
		add_node(expanded, (*ptr)->key, NULL);
	return (EXIT_SUCCESS);
}

int	is_expandable(void *key)
{
	int	k;

	k = *(int *)&key;
	return (k == LEX_KEY_WORD || k == LEX_KEY_DOUB_Q || k == LEX_KEY_SING_Q);
}

static int	expander_for_subshell(t_key_val_lst *ptr, t_lst *expanded)
{
	if (is_expandable(ptr->key))
		return (add_node(expanded, ptr->key, ft_strdup((char *)ptr->val)));
	return (add_node(expanded, ptr->key, ptr->val));
}

t_lst	*expand_group(t_lst *group, t_shell *info)
{
	int				subsh_lvl;
	t_lst			*expanded;
	t_key_val_lst	*ptr;

	ptr = group->head;
	expanded = new_tlst(cmp_int_keys, NULL, hfree);
	subsh_lvl = 0;
	while (expanded && ptr)
	{
		subsh_lvl += (*(int *)&ptr->key == LEX_KEY_PARN_L)
			+ (-1) * (*(int *)&ptr->key == LEX_KEY_PARN_R);
		if (subsh_lvl > 0 && expander_for_subshell(ptr, expanded))
		{
			hfree_tlst(expanded);
			return (NULL);
		}
		else if (!subsh_lvl && write_expanded(&ptr, expanded, info))
		{
			hfree_tlst(expanded);
			return (NULL);
		}
		ptr = ptr->next;
	}
	return (expanded);
}
