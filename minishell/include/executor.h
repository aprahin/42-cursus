/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:44:12 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 14:26:10 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../include/minishell.h"

//
//128 is used to indicate failure to execute another program in a subprocess. 
//src: https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html
//
# define SUBPREXECFAIL 128

//executor*.c
//executor.c
int				check_file_not_dir(char *filepath);
int				execute_tlst_cmds(t_lst *groups, t_shell *info);
pid_t			exec_one_group(int type, t_lst *group, t_shell *info, int *sig);
int				create_texecgroup_heredoc(t_exec_group *cmds);
//executor2.c
pid_t			executor(t_exec_group *cmds, t_shell *info);
int				make_execve_argv(t_key_val_lst *cmd, char ***args, char *path);
int				is_builtin(t_key_val_lst *cmd, t_shell *info);
int				access_cmd_file(t_key_val_lst *cmd,
					char *path, char **filepath);

//executor3.c
pid_t			execute_bb(t_exec_group *cmds, t_shell *info);
int				access_files(t_cmd_info *info);
pid_t			execute_builtin(t_key_val_lst *cmd_ptr, t_shell *info);
pid_t			execute_binary(t_key_val_lst *cmd_ptr, t_shell *info);
pid_t			fork_binary(t_key_val_lst *cmd_ptr,
					t_shell *info, char *filepath);

//executor4.c
int				generate_envp(t_shell *info, char ***envp);
int				update_tshell_envp(t_shell *info);
int				open_files(t_cmd_info *info, int *in_fd, int *out_fd);

//pipe.c
pid_t			execute_pipe(t_exec_group *cmds, t_shell *info);
pid_t			fork_pipe(t_key_val_lst *cmd_ptr, t_shell *info, int *pieps);
int				pipe_binary(t_key_val_lst *cmd_ptr, t_shell *info);

//pipe2.c
int				*open_pipes(t_exec_group *cmds);
int				dup_open_files(t_cmd_info *info, int *pipes);
void			close_pipes(int *pipes);

//subshell.c
pid_t			execute_subshell(t_key_val_lst *cmd_ptr, t_shell *info);

//builtin.c
t_key_val_lst	*get_arg_ptr(t_key_val_lst *cmd_ptr);
int				get_argc(t_key_val_lst *cmd_ptr);
int				print_export(t_shell *info, int out_fd);

//builtin2.c
char			*whereami(void);
int				cd_home(t_shell *info);
int				builtin_cd(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd);
int				builtin_echo(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd);
int				builtin_pwd(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd);

//builtin3.c
int				builtin_export(t_key_val_lst *cmd_ptr,
					t_shell *info, int out_fd);
//t_key_val_lst	*get_min_envp(t_shell *info, t_key_val_lst *last_ptr);
//int				check_var(char *var);
//int				replace_var(char *value, t_shell *info);
//int				set_var(char *value, t_shell *info);

//builtin4.c
int				builtin_env(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd);
int				builtin_unset(t_key_val_lst *cmd_ptr,
					t_shell *info, int out_fd);
int				builtin_exit(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd);
int				check_limits(char *nbr);
int				my_atoi(const char *str);
int				builtin_exit(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd);

//heredoc.c
int				create_heredoc(t_cmd_info *c_info, t_lst *heredoc_files_names);

//signal_handlers.c  
void			sig_main_handler(int signal);
void			sig_heredoc_handler(int signal);
void			sig_quit_handler(int signal);
void			sig_blocking_handler(int signal);

//print_context.c
void			print_exec_groups_key_value_pair(t_key_val_lst *groups_head,
					int i);
void			print_tlst_args(t_exec_group *cmds);

#endif