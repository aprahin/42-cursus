/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:15:08 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 11:38:57 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/expander.h"

static t_fragm_info	*new_tfragm_info(t_ui s, t_ui e)
{
	t_fragm_info	*fragm_info;

	fragm_info = (t_fragm_info *)hmalloc(sizeof(t_fragm_info));
	if (!fragm_info)
		return (NULL);
	fragm_info->e = e;
	fragm_info->s = s;
	return (fragm_info);
}

int	hfree_tfram_info_err(t_fragm_info *fragm_info)
{
	hfree(fragm_info);
	return (shell_err(1, "Error: expand_group()", 1, 0));
}

int	hmalloc_tfragm_info(t_fragm_info **fragm_info, t_ui i, t_ui j)
{
	*fragm_info = new_tfragm_info(i, j);
	if (!(*fragm_info))
		return (shell_err(1, "Error: hmalloc_tfragm_info()", 1, 0));
	return (EXIT_SUCCESS);
}

static int	prepare_segment_expand(t_lst *str, t_shell *info,
		t_lst *fragms, t_exp *ei)
{
	t_fragm_info		*fragm_info;
	t_key_val_lst		*cursor;

	cursor = str->head;
	fragm_info = NULL;
	while (cursor)
	{
		if (*(int *)&cursor->key == LEX_KEY_SING_Q || ei->f)
		{
			if (hmalloc_tfragm_info(&fragm_info, 0,
					ft_strlen((char *)cursor->val)))
				return (EXIT_FAILURE);
			ei->size += fragm_info->e;
			if (add_node(fragms, fragm_info, cursor->val))
				return (hfree_tfram_info_err(fragm_info));
		}
		else if (combine_fragments((char *)cursor->val, info,
				fragms, &(ei->size)))
			return (EXIT_FAILURE);
		cursor = cursor->next;
	}
	ei->f = 0;
	return (EXIT_SUCCESS);
}

int	expand_segment(t_lst *str, t_shell *info, char **word, t_exp *texp)
{
	t_lst	*fragms;

	fragms = new_tlst(NULL, hfree, NULL);
	if (!fragms)
		return (shell_err(1, "Error: expand_segment()", 1, 0));
	texp->size = 0;
	*word = NULL;
	if (prepare_segment_expand(str, info, fragms, texp))
		return (expand_segment_hfree(fragms, word));
	*word = (char *)hmalloc(sizeof(char) * (texp->size + 1));
	if (!(*word))
		return (expand_segment_hfree(fragms, NULL));
	(*word)[texp->size] = '\0';
	if (expand_segment_copy(fragms, *word))
		return (expand_segment_hfree(fragms, word));
	exp_last_word_tkn(str, word, texp);
	hfree_tlst(fragms);
	return (EXIT_SUCCESS);
}
