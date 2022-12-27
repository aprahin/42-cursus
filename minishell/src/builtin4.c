/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:40:34 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 14:46:25 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

int	builtin_env(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd)
{
	t_key_val_lst	*envp;

	if (get_argc(cmd_ptr) > 1)
		return (shell_err(EXIT_FAILURE, ERR_ENV_ARG, 0, 1));
	envp = info->envp_state->head;
	while (envp)
	{
		if (envp->val)
		{
			if (write(out_fd, envp->key, ft_strlen(envp->key)) < 0)
				return (shell_err(125, ERR_ENV_WR, 0, 125));
			ft_putstr_fd("=", out_fd);
			ft_putstr_fd(envp->val, out_fd);
			ft_putstr_fd("\n", out_fd);
		}
		envp = envp->next;
	}
	return (0);
}

int	builtin_unset(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd)
{
	t_key_val_lst	*arg_ptr;
	t_key_val_lst	*envp;

	(void) out_fd;
	(void) cmd_ptr;
	arg_ptr = get_arg_ptr(cmd_ptr)->next;
	while (arg_ptr)
	{
		rm_tlst_node(info->envp_state, arg_ptr->val);
		arg_ptr = arg_ptr->next;
	}
	(void) envp;
	return (0);
}

// checks if an argument is a number bigger than a long long or isn't numeric
int	check_limit(char *nbr)
{
	int		i;
	int		j;
	char	*max;

	j = 0;
	max = "9223372036854775807";
	while (nbr[j] == '\t' || nbr[j] == '\n' || nbr[j] == '\v'
		|| nbr[j] == '\f' || nbr[j] == '\r' || nbr[j] == ' ')
		j++;
	if (nbr[j] == '+' || nbr[j] == '-')
	{
		if (nbr[j++] == '-')
			max = "9223372036854775808";
	}
	i = -1;
	while ((nbr + j)[++i] != '\0')
	{
		if (!ft_isdigit((nbr + j)[i]))
			return (1);
	}
	if (ft_strlen(nbr + j) < 19)
		return (0);
	if (ft_strlen(nbr + j) > 19 || ft_strncmp(nbr + j, max, 20) > 0)
		return (1);
	return (0);
}

// this atoi outputs values for long long that are correct after modulo
int	my_atoi(const char *str)
{
	int	i;
	int	pm;
	int	n;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		++i;
	pm = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			pm = -1;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i++] - '0';
	}
	return (pm * n);
}

int	builtin_exit(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd)
{
	t_key_val_lst	*arg_ptr;
	int				exit_value;

	(void) out_fd;
	(void) info;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (get_argc(cmd_ptr) == 1)
		return (hobliterate(), exit(get_g_last_exit()), 1);
	arg_ptr = get_arg_ptr(cmd_ptr)->next;
	if (check_limit(arg_ptr->val))
	{
		named_err(ERR_EXIT_NUM1, arg_ptr->val, ERR_EXIT_NUM2, 2);
		hobliterate();
		exit(get_g_last_exit());
	}
	if (get_argc(cmd_ptr) > 2)
		return (shell_err(1, ERR_EXIT_ARG, 0, 1));
	exit_value = my_atoi(arg_ptr->val);
	exit_value = exit_value % 256;
	if (exit_value < 0)
		exit_value += 256;
	hobliterate();
	exit(exit_value);
	return (shell_err(1, ERR_EXIT_EXIT, 0, 1));
}
