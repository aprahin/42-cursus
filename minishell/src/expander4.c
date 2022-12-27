/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:15:35 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 02:17:40 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/expander.h"

static t_lst	*expand_asterisk_pwd(const char *word)
{
	DIR				*dir;
	struct dirent	*dirf;
	t_lst			*words;
	char			pwd[PATH_MAX];

	if (!(getcwd(pwd, PATH_MAX)))
		return (NULL);
	dir = opendir(pwd);
	words = new_tlst(cmp_int_keys, NULL, NULL);
	if (!dir || !words)
		return (NULL);
	dirf = readdir(dir);
	while (dirf)
	{
		if (match_asterisk(dirf, word))
			add_node(words, (void *)LEX_KEY_WORD,
				ft_strdup((char *)(dirf->d_name)));
		dirf = readdir(dir);
	}
	if (!(words->size))
	{
		hfree_tlst(words);
		words = NULL;
	}
	return (closedir(dir), words);
}

t_lst	*expand_asterisk(const char *word)
{
	if (!ft_strchr(word, '*'))
		return (NULL);
	if (ft_strchr(word, '/'))
		return (NULL);
	return (expand_asterisk_pwd(word));
}

int	expand_segment_hfree(t_lst *fragms, char **word)
{
	if (fragms)
		hfree_tlst(fragms);
	if (*word)
		hfree(*word);
	return (EXIT_FAILURE);
}

void	exp_last_word_tkn(t_lst *str, char **word, t_exp *ei)
{
	t_key_val_lst	*cursor;

	if (!(ei->size))
	{
		cursor = str->head;
		while (cursor)
		{
			if (*(int *)&cursor->key != LEX_KEY_WORD)
				return ;
			cursor = cursor->next;
		}
		hfree(*word);
		*word = NULL;
	}
}

int	expand_segment_copy(t_lst *fragms, char *word)
{
	t_key_val_lst	*fragms_ptr;
	t_ui			i;
	t_ui			j;

	fragms_ptr = fragms->head;
	i = 0;
	while (fragms_ptr)
	{
		j = ((t_fragm_info *)fragms_ptr->key)->s;
		while (j < ((t_fragm_info *)fragms_ptr->key)->e)
			word[i++] = ((char *)fragms_ptr->val)[j++];
		fragms_ptr = fragms_ptr->next;
	}
	return (EXIT_SUCCESS);
}
