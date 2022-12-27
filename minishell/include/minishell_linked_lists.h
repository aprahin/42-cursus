/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_linked_lists.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:19 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 14:47:04 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LINKED_LISTS_H
# define MINISHELL_LINKED_LISTS_H

# include "../libft/incs/libft.h" 
# include <stdlib.h>

# define LEX_KEY_SEP			0
# define LEX_KEY_WORD			1
# define LEX_KEY_PARN_L			2
# define LEX_KEY_PARN_R			3
# define LEX_KEY_SING_Q			4
# define LEX_KEY_OR				5
# define LEX_KEY_AND			6
# define LEX_KEY_REDIR_OUT		7
# define LEX_KEY_REDIR_IN		8
# define LEX_KEY_REDIR_APPEND	9
# define LEX_KEY_HEREDOC		10
# define LEX_KEY_DOUB_Q			11
# define LEX_KEY_PIPE			12
# define LEX_KEY_ERROR			13

//
//0b base 2
//cmd groups types - builtin or binary, subshell, pipeline
//
# define CMD_TYPE_BI_BIN		0b0010000
# define CMD_TYPE_PIPE			0b1000000
# define CMD_TYPE_SUBSH			0b0100000

//
//cmd types - set explicit >, <<, () set implicitly <, >
//tcmd type is explicitly and implicitly
//set in parse_tkn_to_tcmd_and_tlst_words*()
//cmd_to_inp < - 0b101 (~CMD_TO_HEREDOC), cmd_to_out > - 0b110 (~CMD_TO_APPEND)
//
# define CMD_TO_APPEND			0b001
# define CMD_TO_HEREDOC 		0b010
# define CMD_TO_SUBSH 			0b100

typedef unsigned int			t_ui;

//
//cmp_key_f returns 0 if elements are equal 
//cmp_int_keys, cmp_str_keys
//
typedef int						(*t_cmp_key_f)	(const void *k1,
		const void *k2);

//
//hfree vs hfree_voidptr_lst for both dstr_key_f and dstr_val_f
//rm_node erases key or/and val of t_key_val_lst if dstr_f is not NULL
//set_val(), hfree_tlst()  will destroy key and/or value if dstr_f are not 0//

typedef void					(*t_dstr_key_f)	(void *key);
typedef void					(*t_dstr_val_f)	(void *val);

//
//the important t_lst:
//1) t_lst tokens 2) t_lst	*group 3) t_lst *groups
//4) t_lst	*args (dif for group with
//and wo pipes)	5) 	t_lst	*cmds from t_exec_one_gr
//
//1////t_lst tokens = void* of key - int (LEX_KEY) and value - char *
//made in lex_into_tokens(), stored as a variable in main()
//
//2////t_lst	*group = void* of key - int (LEX_KEY) and value - char *
//made in tkns_to_one_group() (with long type of the group),
//stored in t_lst *groups 
//
//in tkns_to_one_group() we split cmds into groups by:
//1) log op because parts of log expr have to be executed separately
//2) paranteses () as every subshell has to be executed in a separate process
//
//group is tokens that have to be executed in
//a subshell or are a part of logical expression
//group is tokens from t_lst tokens until
//&& || or inside the highest lvl subshell ()
//if && || are inside subshell () we write them as part of the group 
//
//3////t_lst *groups = void* of key -
//int type(of group) and value - t_lst	*group
//made in add_group_to_groups(), stored as a variable in prs_and_exec()
//type(of groups) - CMD_TYPE_BI_BIN	CMD_TYPE_PIPE CMD_TYPE_SUBSH
//for log op that follow group value is 0, key - tkn LEX_KEY_*
//
//4//args are group split into subgroups by pipes 
//
//for group without pipes
//4A////t_lst	*args = void* of key - int (LEX_KEY) and value - char * 
//args is tkns from t_lst group until the end of subshell ()
//made in  parse_tkn_to_tcmd_and_tlst_words(), stored in t_lst	*cmds
//
//for group with pipes
//4B////t_lst	*args = void* of key - int
//type(of group) and value - t_lst	*group 
//args is group from t_lst groups until
//the end of subshell ()  or pipe outside ()
//made in  parse_tkn_to_tcmd_and_tlst_words(), stored in t_lst	*cmds
//
//5////t_lst	*cmds = void* of t_lst args and value - t_cmd	*info
//made in set_texeconegr_cmds(), stored in t_exec_one_gr
//that is stored as a variable in exec_one_group()
//

typedef struct s_key_val_pair_list
{
	void				*key;
	void				*val;
	void				*next;
}	t_key_val_lst;

typedef struct s_linked_list
{
	t_key_val_lst		*head;
	t_cmp_key_f			cmp_k;
	t_dstr_key_f		dstr_k;
	t_dstr_val_f		dstr_v;
	t_ui				size;
}	t_lst;

//
//cmd types - set explicit >, <<, () set implicitly <, >
//tcmd type is explicitly and implicitly
//set in parse_tkn_to_tcmd_and_tlst_words*()
//cmd_to_inp < - 0b101 (~CMD_TO_HEREDOC), cmd_to_out > - 0b110 (~CMD_TO_APPEND)
//
typedef struct s_cmd_info
{
	char			*file_in;
	char			*file_out;
	char			*delimiter;
	int				type;
	int				subsh_lvl;
}	t_cmd_info;

typedef struct s_execute_one_group
{
	t_lst			*cmds;
	t_lst			*heredoc_files_names;
	int				type;	
}	t_exec_group;

//minishell_linked_lists.c 
t_lst				*new_tlst(t_cmp_key_f cmp_k,
						t_dstr_key_f dstr_k, t_dstr_val_f dstr_v);
t_key_val_lst		*new_key_val_tlst(void *key, void *val);
int					add_node(t_lst *list, void *key, void *val);
int					rm_tlst_node(t_lst *list, const void *key);

//minishell_linked_lists2.c 
int					set_val(t_lst *list, void *key, void *new_val);
void				*get_val(t_lst *list, const void *key);
int					lst_has_key(t_lst *list, const void *key);
int					cmp_int_keys(const void *k1, const void *k2);
int					cmp_str_keys(const void *k1, const void *k2);

//minishell_linked_lists3.c
t_exec_group		*new_texec_group(int type);
void				hfree_texec_group(void *group);
void				hfree_voidptr_lst(void *llist);
void				hfree_tlst(t_lst *list);

//minishell_linked_lists4.c
t_key_val_lst		*get_next_tkn(t_key_val_lst *curr);
void				hmalloc_t_cmd_info(t_cmd_info **info);
int					hfree_tlst_ret1(t_lst *groups);
int					hfree_tlst_ret0(t_lst *groups);

#endif
