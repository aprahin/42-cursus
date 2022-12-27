/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:15:30 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/27 09:16:43 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/expander.h"

void	add_expanded_tkn2(t_lst *expanded, char *word, t_lst *words)
{
	t_key_val_lst			*wptr;

	hfree(word);
	wptr = words->head;
	while (wptr)
	{
		add_node(expanded, (void *)LEX_KEY_WORD, wptr->val);
		if (wptr->next)
			add_node(expanded, (void *)LEX_KEY_SEP, NULL);
		wptr = wptr->next;
	}
	hfree_tlst(words);
}

static int	match_pattern2(const char *patt, const char *word, t_wildcard wc)
{
	while (word[wc.i] != '\0')
	{
		if (patt[wc.j] == '\0')
		{
			if (patt[wc.j - 1] == '*')
				return (1);
			return (0);
		}
		if (word[wc.i] == patt[wc.j])
			++wc.j;
		else if (patt[wc.j] != '*')
			wc.j = wc.l_wc + 1;
		else if (patt[wc.j] == '*')
		{
			wc.l_wc = wc.j;
			wc.j = wc.l_wc + 1;
		}
		++wc.i;
	}
	while (patt[wc.j++] != '\0')
	{
		if (patt[wc.j - 1] != '*')
			return (0);
	}
	return (1);
}

static int	match_pattern(const char *patt, const char *word)
{
	t_wildcard	wc;

	wc.i = 0;
	while (word[wc.i] == patt[wc.i])
		++wc.i;
	if (patt[wc.i] != '*')
		return (0);
	wc.l_wc = wc.i;
	wc.j = wc.l_wc + 1;
	return (match_pattern2(patt, word, wc));
}

int	match_asterisk(struct dirent *dirf, const char *word)
{
	return (((word[0] == '.' && dirf->d_name[0] == '.')
			|| (word[0] != '.' && dirf->d_name[0] != '.'))
		&& match_pattern(word, dirf->d_name));
}

void	ft_to_wildcard(char **word)
{
	int	i;

	i = -1;
	while ((*word)[++i])
	{
		if ((*word)[i] == -42)
			(*word)[i] = '*';
	}
}
