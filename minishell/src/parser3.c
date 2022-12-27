/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:26:19 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 16:52:47 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	hfree_parse_tkn_ret1(t_cmd_info *info, t_lst *args)
{
	hfree_tlst(args);
	hfree(info);
	return (EXIT_FAILURE);
}

//return (shell_err(1, "minihell: syntax error", 0, 258));
int	hfree_parse_tkn_syntax_err(t_cmd_info *info, t_lst *args)
{
	hfree_tlst(args);
	hfree(info);
	set_g_last_exit(0);
	return (1);
}

int	hfree_parse_tkn_err(t_cmd_info *info, t_lst *args)
{
	hfree_tlst(args);
	hfree(info);
	return (shell_err(1, "Error: hfree_parse_tkn_err()", 1, 0));
}

// [EXAMPLE] echo hello world > midfile > outfile
// [EXAMPLE] cat infile | ls doesntexist | wc > midfile > outfile
// midfile has to be handled before being overwritten by a new outfile in
// groups_and_group_to_args2().
// create the file if it doesn't exist
// unlink if it exists and is >
// don't do anything if it exists and is >>
// if there are no write permission, don't output to next redirection
//		return (0) if it's OK to replace file_out with new file_out
//		return (1) if it's not (permissions not OK)

// RECTIFICATION: > takes precedence over everything. So, we should erase
// content in every "> file" and not just the middle ones
// DOESN'T TAKE PRECEDENCE IF THE MIDFILE HAS NO WRITE PERMISSIONS
int	handle_middle_file(t_cmd_info *tcmd)
{
	int			tmp_fd;
	struct stat	file_stat;

	if (tcmd->file_out == NULL)
		return (0);
	if (access(tcmd->file_out, F_OK) == 0)
	{
		if (access(tcmd->file_out, W_OK) != 0)
			return (EXIT_FAILURE);
		if (stat(tcmd->file_out, &file_stat) != 0)
			return (shell_err(1, "hmd(): couldn't get file stat", 0, 1));
	}
	else
		file_stat.st_mode = 0644;
	if ((tcmd->type & CMD_TO_APPEND) == 0)
		tmp_fd = open(tcmd->file_out, O_WRONLY | O_CREAT | O_TRUNC,
				file_stat.st_mode);
	else
		tmp_fd = open(tcmd->file_out, O_WRONLY | O_CREAT | O_APPEND,
				file_stat.st_mode);
	close(tmp_fd);
	return (0);
}

//
//5////t_lst	*cmds = void* of t_lst args and value - t_cmd	*info 
//args are group split into subgroups by pipes 
//made in set_texeconegr_cmds(), stored in 
//t_exec_one_gr that is stored as a variable in exec_one_group()
//
int	args_and_tcmd_info_to_cmds(t_key_val_lst *gr_tkn, t_lst *cmds)
{
	t_cmd_info	*tcmd;
	t_lst		*args;

	hmalloc_t_cmd_info(&tcmd);
	args = new_tlst(NULL, NULL, NULL);
	if (!tcmd || !args)
		return (shell_err(1, "Error: args_and_tcmd_to_cmds()", 1, 0));
	while (gr_tkn && (*(int *)&(gr_tkn)->key != LEX_KEY_PIPE
			|| tcmd->subsh_lvl))
	{
		if (groups_and_group_to_args(&gr_tkn, tcmd, args))
			return (hfree_parse_tkn_err(tcmd, args));
		gr_tkn = gr_tkn->next;
	}
	if ((!(args->size) && !(tcmd->file_out) && !(tcmd->file_in)))
		return (hfree_parse_tkn_syntax_err(tcmd, args));
	if (!gr_tkn || *(int *)&gr_tkn->key == LEX_KEY_PIPE)
	{
		if (add_node(cmds, args, tcmd))
			return (hfree_parse_tkn_err(tcmd, args));
		return (EXIT_SUCCESS);
	}
	hfree_tlst(args);
	hfree(tcmd);
	return (EXIT_FAILURE);
}
