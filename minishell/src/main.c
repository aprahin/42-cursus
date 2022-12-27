/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:30 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/23 21:42:1 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

static int						g_last_exit;

int	get_g_last_exit(void)
{
	return (g_last_exit);
}

void	set_g_last_exit(int val)
{
	g_last_exit = val;
}

//
//3////t_lst *groups = void* of key - int type(of group)
// and value - t_lst	*group
//made in add_group_to_groups(), stored as a variable in prs_and_exec()
//
int	prs_and_exec(t_lst *tokens, t_shell *shell)
{
	t_lst		*groups;

	groups = new_tlst(NULL, NULL, hfree_voidptr_lst);
	if (!groups)
		return (EXIT_FAILURE);
	if (prs_tkns_into_groups(groups, tokens))
		return (hfree_tlst_ret1(groups));
	if (!(groups->size))
	{
		hfree_tlst(groups);
		return (EXIT_SUCCESS);
	}
	if (check_log_op(groups))
		return (hfree_tlst_ret1(groups));
	if (execute_tlst_cmds(groups, shell))
		return (hfree_tlst_ret1(groups));
	hfree_tlst(groups);
	return (EXIT_SUCCESS);
}
//shell_prompt = strjoin_with_delimeter(ft_itoa(get_g_last_exit()),
//	shell_prompt, '/');

char	*read_input(char *shell_prompt)
{
	char	*inp_line;
	int		tmp_fd;

	tmp_fd = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	inp_line = readline(shell_prompt);
	dup2(tmp_fd, STDOUT_FILENO);
	close(tmp_fd);
	if (inp_line && *inp_line)
		add_history(inp_line);
	return (inp_line);
}

//
//1////t_lst tokens = void* of key - int (LX_SEP) and value - char *
//made in lex_into_tokens(), stored as a variable in main()
//
int	main(int argc, char **argv, char **envp)
{
	char	*inp_line;
	t_shell	shell;
	t_lst	*tokens;

	if (initialize_minishell(&shell, envp))
		return (EXIT_FAILURE);
	while (shell.exit_shell)
	{
		prepare_main(&tokens, &inp_line, argv, argc);
		if (inp_line && *inp_line)
		{
			signal(SIGINT, sig_blocking_handler);
			signal(SIGQUIT, sig_quit_handler);
			if (!wc_to_42(&inp_line) && !(lex_into_tokens(tokens, inp_line)))
				prs_and_exec(tokens, &shell);
			free(inp_line);
		}
		else if (!inp_line)
			shell.exit_shell = 0;
		hfree_tlst(tokens);
		signal(SIGINT, sig_main_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	hfree_tshell(&shell);
	return (write(STDERR_FILENO, "exit\n", 5), hobliterate(), g_last_exit);
}
