/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:48:03 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 15:00:07 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sig_main_handler(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

// Running cat without argument and ctrl+c for example
void	sig_blocking_handler(int sig)
{
	(void) sig;
	write(2, "\n", 1);
}

// Running cat without argument and ctrl+/ for example
void	sig_quit_handler(int sig)
{
	(void) sig;
	ft_putstr_fd("Quit (core dumped)\n", 2);
}
//
//The 128+SIGINT after the last command died of a SIGINT 
//is a representation of its exit status made by bash
//(void)signal suppress warning about an unused return value (from the f call)
//

void	sig_heredoc_handler(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	hobliterate();
	exit(128 + SIGINT);
}
