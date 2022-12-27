/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:16:10 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 01:19:27 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

//
//(void)argv (void)argc suppress warning about an unused return value
//errno - number of last error
//
void	prepare_main(t_lst **tokens, char **line, char **argv, int argc)
{
	(void)argv;
	(void)argc;
	signal(SIGINT, sig_main_handler);
	errno = 0;
	*tokens = new_tlst(cmp_int_keys, NULL, hfree);
	*line = read_input(SHELL_PROMPT);
}

//
//write envp line left and right values to arg str
//if writing to either arg str failed hfree and exit
//
static int	get_val_from_envp_line(const char *s, char **left, char **right)
{
	int		i;
	int		j;

	if (!s)
		return (EXIT_FAILURE);
	j = 0;
	while (s[j] && !ft_strchr("=", s[j]))
		j++;
	i = j;
	*left = (char *)hmalloc(sizeof(char) * (j + 1));
	if (!left)
		return (EXIT_FAILURE);
	while (i--)
		(*left)[i] = s[i];
	(*left)[j] = '\0';
	if (!s[j])
		*right = NULL;
	else
		*right = ft_strdup((char *)(s + j + 1));
	if (right)
		return (EXIT_SUCCESS);
	hfree(*left);
	return (EXIT_FAILURE);
}

//
//initialize t_shell t_lst *envp_state where key - envp var name, value - str
//
static int	initialize_tshell_envp_state(t_lst *l, char **envp)
{
	char			*key;
	char			*val;
	t_ui			i;

	if (!envp || !*envp || !l)
		return (-1);
	i = -1;
	while (envp[++i])
	{
		if (get_val_from_envp_line(envp[i], &key, &val))
			return (shell_err(1,
					"Error: initialize_tshell_envp_state()", 1, 0));
		if (add_node(l, key, val))
			return (shell_err(1,
					"Error: initialize_tshell_envp_state()", 1, 0));
	}
	return (EXIT_SUCCESS);
}

//
//fill in with fptrs to builtins
//
static void	initialize_tshell_builtins(t_shell *shell)
{
	shell->built_in_names[0] = "echo";
	shell->built_in_names[1] = "cd";
	shell->built_in_names[2] = "pwd";
	shell->built_in_names[3] = "export";
	shell->built_in_names[4] = "unset";
	shell->built_in_names[5] = "env";
	shell->built_in_names[6] = "exit";
	shell->built_in_f[0] = &builtin_echo;
	shell->built_in_f[1] = &builtin_cd;
	shell->built_in_f[2] = &builtin_pwd;
	shell->built_in_f[3] = &builtin_export;
	shell->built_in_f[4] = &builtin_unset;
	shell->built_in_f[5] = &builtin_env;
	shell->built_in_f[6] = &builtin_exit;
}

int	initialize_minishell(t_shell *shell, char **envp)
{
	signal(SIGQUIT, SIG_IGN);
	set_g_last_exit(0);
	shell->update_envp = 1;
	shell->exit_shell = 1;
	shell->g_last_exit_str = NULL;
	shell->envp = NULL;
	shell->envp_state = new_tlst(cmp_str_keys, hfree, hfree);
	if (!(shell->envp_state))
		return (shell_err(1, "initialize_minishell()", 1, 0));
	if (initialize_tshell_envp_state(shell->envp_state, envp))
		return (EXIT_FAILURE);
	initialize_tshell_builtins(shell);
	return (EXIT_SUCCESS);
}
