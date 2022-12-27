/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:07:21 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/26 14:26:22 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"
#include "../include/expander.h"

int	check_file_not_dir(char *filepath)
{
	struct stat	file_stat;

	if (access(filepath, F_OK) != 0)
		return (named_err(ERR_SH, filepath, ERR_FILE, 127), 1);
	stat(filepath, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		return (named_err(ERR_SH, filepath, ERR_DIR, 127), 1);
	return (0);
}

//
//wait_for_terminated_children(exec_pid, &signal)
//
//waitpid() suspends processs exec 
//until a child specified by pid has changed state. 
//WEXITSTATUS macro returns the exit code specified by the child
//WIFSIGNALED–query status to see if a child process ended abnormally
//ENOTRECOVERABLE - State not recoverable
//WTERMSIG: Determine which signal caused the child process to exit
//returns the numeric value of the signal that was raised by the child process.
//

static void	wait_for_terminated_children(int pid, int *sig)
{
	int		pid2;

	if (pid <= 0)
		return ;
	pid2 = 1;
	while (pid2 > 0)
	{
		pid2 = waitpid(0, sig, 0);
		if (pid == pid2)
		{
			set_g_last_exit(WEXITSTATUS(*sig));
			if (WIFSIGNALED(*sig))
			{
				set_g_last_exit(WTERMSIG(*sig));
				if (get_g_last_exit() != 131)
					set_g_last_exit(get_g_last_exit() + SUBPREXECFAIL);
			}
		}
	}
}

int	create_texecgroup_heredoc(t_exec_group *exec_gr)
{
	t_key_val_lst		*cursor_one_gr;
	t_cmd_info			*tcmdinfo;
	int					ret;

	cursor_one_gr = exec_gr->cmds->head;
	while (cursor_one_gr)
	{
		tcmdinfo = (t_cmd_info *)cursor_one_gr->val;
		ret = 0;
		if (tcmdinfo->type & CMD_TO_HEREDOC)
			ret = create_heredoc(tcmdinfo, exec_gr->heredoc_files_names);
		if (ret == 2)
		{
			set_g_last_exit(130);
			return (EXIT_FAILURE);
		}
		cursor_one_gr = cursor_one_gr->next;
	}
	return (EXIT_SUCCESS);
}

//
//pid_t execute_texeconegr(t_exec_one_gr *cmds, t_shell *shell);
//it has separate routines for executing commands 
//with pipe, subshell, binary and builtins
//and returns the pid of the launched 
//process to execute_tlst_cmds() that waits all
//
//5////t_lst	*cmds = void* of t_lst args and value - t_exec_one_gr	*info 
//made in set_texeconegr_cmds(), stored in t_exec_one_gr 
//that is stored as a variable in exec_one_group()
//args are group split into subgroups (args) by pipes
//
pid_t	exec_one_group(int type, t_lst *group, t_shell *info, int *sig)
{
	t_lst			*expanded;
	t_exec_group	*cmds;
	pid_t			exec_pid;

	exec_pid = -1;
	expanded = expand_group(group, info);
	if (expanded)
	{
		cmds = new_texec_group(type);
		if (!cmds)
			return (-1);
		if (set_texecgroup_cmds(expanded, cmds))
			return (hfree_texecgroup_and_tlst(cmds, expanded));
		if (create_texecgroup_heredoc(cmds))
			return (hfree_texecgroup_and_tlst(cmds, expanded));
		exec_pid = executor(cmds, info);
		wait_for_terminated_children(exec_pid, sig);
		hfree_tlst(expanded);
		hfree_texec_group(cmds);
	}
	return (exec_pid);
}

//
//executes log op that were outside subshell parantheses
//there may be still some log op inside groups
//
// echo A || echo B && echo C && echo D
// A
// C
// D
/*static int	exec_log_op_outside_paran(t_key_val_lst *ptr, int *expect)
{
	if ((!(get_g_last_exit()) && (*(int *)&ptr->key == LEX_KEY_OR))
		|| (get_g_last_exit() != 0 && (*(int *)&ptr->key == LEX_KEY_AND)))
		return (EXIT_FAILURE);
	*expect = 0;
	return (EXIT_SUCCESS);
}*/

int	execute_tlst_cmds(t_lst *groups, t_shell *shell)
{
	t_key_val_lst		*grps;
	pid_t				epid;
	int					sig;
	int					exec_once;

	exec_once = 0;
	grps = groups->head;
	while (grps)
	{
		if (!exec_once)
		{
			epid = exec_one_group(*(int *)&(grps)->key, grps->val, shell, &sig);
			if (epid < 0)
				return (EXIT_FAILURE);
			exec_once = 1;
		}
		if (exec_once && get_g_last_exit() == 0
			&& (*(int *)&grps->key == LEX_KEY_AND))
			exec_once = 0;
		if (exec_once && get_g_last_exit() != 0
			&& (*(int *)&grps->key == LEX_KEY_OR))
			exec_once = 0;
		grps = grps->next;
	}
	return (EXIT_SUCCESS);
}
