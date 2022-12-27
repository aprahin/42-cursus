/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:13:42 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 11:49:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

//# include <linux/limits.h>
# include <limits.h>

# include "../include/minishell_linked_lists.h"
# include "../include/minishell.h"

typedef struct s_fragm_info
{
	t_ui			s;
	t_ui			e;
}	t_fragm_info;

typedef struct s_expand_fragment
{
	t_fragm_info	*fragm_info;
	t_ui			*i;
	t_ui			*size;
}	t_exp_frg;

typedef struct s_expand
{
	t_ui			size;
	int				f;
}	t_exp;

typedef struct s_wildcard
{
	int	i;
	int	j;
	int	l_wc;
}	t_wildcard;

//expander*.c
//expander.c
t_lst				*expand_group(t_lst *group, t_shell *info);
int					is_expandable(void *key);
//expander2.c
int					expand_segment(t_lst *str, t_shell *info,
						char **word, t_exp *texp);
int					hmalloc_tfragm_info(t_fragm_info **ci, t_ui i, t_ui j);
int					hfree_tfram_info_err(t_fragm_info *ci);
//expander3.c
int					combine_fragments(char *s, t_shell *info, t_lst *fragms,
						t_ui *size);
//expander4.c
int					expand_segment_copy(t_lst *fragms, char *word);
void				exp_last_word_tkn(t_lst *str, char **word, t_exp *ei);
int					expand_segment_hfree(t_lst *fragms, char **word);
t_lst				*expand_asterisk(const char *word);
//expander5.c
int					match_asterisk(struct dirent *dirf, const char *word);
void				add_expanded_tkn2(t_lst *expanded,
						char *word, t_lst *words);
void				ft_to_wildcard(char **word);

#endif
