/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 03:14:33 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 02:33:19 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_token_key(const char *line, t_ul i)
{
	if (line[i] == '|' && line[i + 1] && line[i + 1] == '|')
		return (LEX_KEY_OR);
	if (line[i] == '|')
		return (LEX_KEY_PIPE);
	if (line[i] == '>' && line[i + 1] && line[i + 1] == '>')
		return (LEX_KEY_REDIR_APPEND);
	if (line[i] == '>')
		return (LEX_KEY_REDIR_OUT);
	if (line[i] == '<' && line[i + 1] && line[i + 1] == '<')
		return (LEX_KEY_HEREDOC);
	if (line[i] == '<')
		return (LEX_KEY_REDIR_IN);
	if (line[i] == '&' && line[i + 1] && line[i + 1] == '&')
		return (LEX_KEY_AND);
	if (line[i] == '(')
		return (LEX_KEY_PARN_L);
	if (line[i] == ')')
		return (LEX_KEY_PARN_R);
	return (LEX_KEY_ERROR);
}

int	is_special_char(char c)
{
	return (c == '|' || c == '>' || c == '<'
		|| c == '&' || c == '(' || c == ')');
}

static int	lex_special_char(t_lst *tokens, char *line, t_ul i, t_ul *t)
{
	*t = get_token_key(line, i);
	if (*t == LEX_KEY_ERROR)
		return (shell_err(1, "Error: lex_special_char()\
		wrong type of special char", 0, 258));
	if (add_node(tokens, (void *)(*t), NULL))
		return (shell_err(1, "Error: lex_special_char()", 1, 0));
	*t = (*t == LEX_KEY_REDIR_APPEND || *t == LEX_KEY_HEREDOC
			|| *t == LEX_KEY_AND || *t == LEX_KEY_OR);
	return (EXIT_SUCCESS);
}

static int	lexer(t_lst *tokens, char *line, t_ul *i)
{
	t_ul	t;

	if (line[*i] == '\'' || line[*i] == '\"')
	{
		if (lex_quotes(tokens, line, *i, &t))
			return (shell_err(1, "Error: lex_quotes()", 1, 0));
		if (!t)
			return (shell_err(1, ERR_LEX_QU, 0, 0));
		*i += t + 1;
	}
	else if (line[*i] && is_special_char(line[*i]))
	{
		if (lex_special_char(tokens, line, *i, &t))
			return (EXIT_FAILURE);
		*i += t + 1;
	}
	else if (line[*i])
	{
		if (lex_word(tokens, line, *i, &t))
			return (shell_err(1, "Error: lex_word()r", 1, 0));
		*i += t;
	}
	return (EXIT_SUCCESS);
}

//
//1////t_lst tokens = void* of key - int (LEX_KEY_SEP) and value - char *
//made in lex_into_tokens(), stored as a variable in main()
//
//1 space for one continuos space segment
//add_node(tokens, (int *)LEX_KEY_SEP, 0)
//tokens stored in main()
//
int	lex_into_tokens(t_lst *tokens, char *line)
{
	t_ul	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] && ft_isspace(line[i])
			&& add_node(tokens, (int *)LEX_KEY_SEP, NULL))
			return (shell_err(1, "Error: lex_into_tokens()", 1, 0));
		while (line[i] && ft_isspace(line[i]))
			++i;
		if (lexer(tokens, line, &i))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
