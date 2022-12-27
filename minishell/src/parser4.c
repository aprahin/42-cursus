/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:20:46 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 13:32:30 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	handle_middle_file_in(t_cmd_info *tcmd)
{
	if (tcmd->file_in == NULL)
		return (0);
	if (access(tcmd->file_in, F_OK) == 0)
	{
		if (access(tcmd->file_in, R_OK) != 0)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (0);
}
