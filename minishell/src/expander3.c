/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:15:17 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 02:16:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/expander.h"

static int	extract_ret0(char	**envp_ptr)
{
	*envp_ptr = NULL;
	return (EXIT_SUCCESS);
}

static int	extract_envp_var(const char *s, t_shell *info,
		char **envp_ptr, t_ui *j)
{
	t_ui			i;
	char			*name;

	i = 0;
	if (!s[i])
		return (extract_ret0(envp_ptr));
	if (s[i] == '?')
	{
		if (update_g_last_exit(info))
			return (EXIT_FAILURE);
		*envp_ptr = info->g_last_exit_str;
		*j += 1;
		return (EXIT_SUCCESS);
	}
	while (ft_isalnum(s[i]) || s[i] == '_')
		++i;
	if (!i)
		return (extract_ret0(envp_ptr));
	name = ft_substr(s, 0, i);
	if (!name)
		return (shell_err(1, "Error: extract_envp_var()", 1, 0));
	*envp_ptr = get_val(info->envp_state, name);
	*j += i;
	hfree(name);
	return (EXIT_SUCCESS);
}

static int	expand_envp_var(char *s, t_shell *info,
		t_lst *fragms, t_exp_frg *texpfr)
{
	char			*envp_ptr;

	if (extract_envp_var(s + *(texpfr->i) + 1, info, &envp_ptr, texpfr->i))
		return (EXIT_FAILURE);
	if (!envp_ptr && s[*(texpfr->i)] == '$')
		*(texpfr->size) += (++(texpfr->fragm_info->e) || 1);
	if (envp_ptr)
	{
		if (hmalloc_tfragm_info(&(texpfr->fragm_info), 0, ft_strlen(envp_ptr)))
			return (EXIT_FAILURE);
		if (add_node(fragms, texpfr->fragm_info, envp_ptr))
		{
			hfree(texpfr->fragm_info);
			return (shell_err(1, "Error: combine_fragments()", 1, 0));
		}
		*(texpfr->size) += (texpfr->fragm_info->e);
	}
	++(*(texpfr->i));
	return (EXIT_SUCCESS);
}

static void	prepare_expand_envp_var(t_exp_frg *texpfr, t_fragm_info *fragm_info,
		t_ui *i, t_ui *size)
{
	texpfr->fragm_info = fragm_info;
	texpfr->i = i;
	texpfr->size = size;
}

int	combine_fragments(char *s, t_shell *info, t_lst *fragms, t_ui *size)
{
	t_fragm_info	*fragm_info;
	t_exp_frg		texpfr;
	t_ui			i;
	t_ui			j;

	i = 0;
	j = 0;
	fragm_info = NULL;
	while (s[i])
	{
		while (s[i] && s[i] != '$')
			*size += (++i || 1);
		if (hmalloc_tfragm_info(&fragm_info, j, i))
			return (EXIT_FAILURE);
		if (add_node(fragms, fragm_info, s))
			return (hfree_tfram_info_err(fragm_info));
		prepare_expand_envp_var(&texpfr, fragm_info, &i, size);
		if (s[i] == '$' && expand_envp_var(s, info, fragms, &texpfr))
			return (EXIT_FAILURE);
		j = i;
	}
	return (EXIT_SUCCESS);
}
