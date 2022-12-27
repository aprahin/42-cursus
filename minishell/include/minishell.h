/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:16:15 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 12:08:3 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include "../libft/incs/libft.h" 
# include "../include/minishell_linked_lists.h"

# define SHELL_PROMPT "\033[1m\033[37mmini\033[1m\033[31mhell \033[0m"

# define ERR_SH "minihell: "
# define ERR_CMD ": command not found"
# define ERR_FILE ": No such file or directory"
# define ERR_PERMS ": Permission denied"
# define ERR_CREAT ": couldn't create file"
# define ERR_CLOSE ": couldn't close file"
# define ERR_DIR ": command cannot be a directory"

# define ERR_CD_HOME "minihell: cd: HOME not set"
# define ERR_CD_CD "minihell: cd: No such file or directory"
# define ERR_CD_ARG "minihell: cd: too many arguments"

# define ERR_ECHO_WR "minihell: echo: write error: No space left on device"

# define ERR_PWD_WR "minihell: pwd: write error: No space left on device"

# define ERR_EXP_ID1 "minihell: export: `"
# define ERR_EXP_ID2 "': not a valid identifier"
# define ERR_EXP_WR "minihell: export: write error: No space left on device"

# define ERR_ENV_ARG "minihell: env: too many arguments"
# define ERR_ENV_WR "minihell: env: write error: No space left on device"

# define ERR_EXIT_NUM1 "minihell: exit: "
# define ERR_EXIT_NUM2 ": numeric argument required"
# define ERR_EXIT_ARG "minihell: exit: too many arguments"
# define ERR_EXIT_EXIT "minihell: exit: failed to exit"

# define ERR_IN_EXIST "file: No such file or directory"
# define ERR_IN_PERM "file: Permission denied"
# define ERR_OUT_PERM "file: Permission denied"
# define ERR_OUT_CREAT "file: couldn't create file"
# define ERR_OUT_CLOSE "file: couldn't close file"

# define ERR_HD_EXIST "create_heredoc(): tmp file already exists"

# define ERR_LEX_QU "minihell: syntax error near \
unclosed single or double quotes"

# define ERR_PRS_LREDIR "minihell: syntax error near \
missing token after < or <<"
# define ERR_PRS_RREDIR "minihell: syntax error near \
missing token after > or >>"
# define ERR_PRS_PARN "minihell: syntax error near `()'"
# define ERR_PRS_LOG "minihell: syntax error near `&&' or `||'"
# define ERR_PRS_PIPE "minihell: syntax error near missing token after |"

extern void						rl_replace_line(const char *str, int i);// macOS
extern void						rl_clear_history(void);

typedef unsigned int			t_ui;
typedef unsigned long			t_ul;
typedef struct s_minishell		t_shell;
typedef int						(*t_built_in)(t_key_val_lst *, t_shell *, int);

struct s_minishell
{
	t_built_in					built_in_f[7];
	char						*built_in_names[7];
	char						**envp;
	t_lst						*envp_state;
	char						update_envp;
	char						exit_shell;
	char						*g_last_exit_str;
};

//main.c
int								get_g_last_exit(void);
void							set_g_last_exit(int val);
char							*read_input(char *shell_prompt);
int								prs_and_exec(t_lst *tokens, t_shell *info);

//initialize_minishell.c 
int								initialize_minishell(t_shell *shell,
									char **envp);
void							prepare_main(t_lst **tokens, char **line,
									char **argv, int argc);

//lexer*.c
int								lex_into_tokens(t_lst *tokens, char *str);
int								is_special_char(char c);
int								lex_quotes(t_lst *tokens, char *line,
									t_ul i, t_ul *t);
int								lex_word(t_lst *tokens, char *line,
									t_ul i, t_ul *t);

//parser*.c
//parser.c
int								check_log_op(t_lst *groups);
int								prs_tkns_into_groups(t_lst *groups,
									t_lst *tokens);
int								is_log_op(void *tok_key);
//parser2.c
int								set_texecgroup_cmds(t_lst *expanded,
									t_exec_group *cmds);
int								groups_and_group_to_args(t_key_val_lst **tkn,
									t_cmd_info *tcmd, t_lst *args);
//parser3.c
int								hfree_parse_tkn_err(t_cmd_info *info,
									t_lst *args);
int								hfree_parse_tkn_syntax_err(t_cmd_info *info,
									t_lst *args);
int								hfree_parse_tkn_ret1(t_cmd_info *info,
									t_lst *args);
int								handle_middle_file(t_cmd_info *tcmd);
int								args_and_tcmd_info_to_cmds(
									t_key_val_lst *gr_tkn, t_lst *cmds);

//parser4.c
int								handle_middle_file_in(t_cmd_info *info);

//utils*.c
//utils.c
int								shell_err(int ret, const char *msg,
									char liberr, int g_e);
char							**hmalloc2darr_upto_idx(int m, int n);
void							*hfree2darr_upto_idx(char **arr, int m);
char							*ft_uitoa(t_ui n);
int								ft_isspace(char c);
//utils2.c
char							**hfree_2darr(char **str2, int j);
int								hfree_tshell(t_shell *info);
int								hfree_texecgroup_and_tlst(t_exec_group *group,
									t_lst *expanded);
int								get_in_fd(t_cmd_info *info);
int								get_out_fd(t_cmd_info *info);
//utils3.c
int								update_g_last_exit(t_shell *info);
char							*strjoin_with_delimeter(const char *s1,
									const char *s2, char d);
int								wc_to_42(char **str);
void							named_err(const char *start, const char *name,
									const char *end, int g_e);

#endif
