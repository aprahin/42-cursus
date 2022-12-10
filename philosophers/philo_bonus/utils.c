/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:25:49 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/10 14:45:06 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	logs(char *msg, int id)
{
	printf("%i %i %s\n", get_time(), id, msg);
}

int	get_time(void)
{
	static int		start = -1;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (start < 0)
		start = time.tv_sec;
	return ((time.tv_sec - start) * 1000 + time.tv_usec / 1000);
}

void	free_close(t_philo *p, int *pids)
{
	free(pids);
	free(p->stop);
	sem_close(p->fork_s);
	sem_close(p->goal_s);
	sem_close(p->stop_s);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_GOAL);
	sem_unlink(SEM_STOP);
}

int	init_philo(t_philo *p, int ac, char **av)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_GOAL);
	sem_unlink(SEM_STOP);
	p->nb = ft_atoi(av[1]);
	p->die = ft_atoi(av[2]);
	p->eat = ft_atoi(av[3]);
	p->slp = ft_atoi(av[4]);
	if (ac == 6)
	{
		p->max_eat = ft_atoi(av[5]);
		p->goal = ft_atoi(av[5]) * ft_atoi(av[1]);
	}
	else
	{
		p->max_eat = 0;
		p->goal = -1;
	}
	p->fork_s = sem_open(SEM_FORK, O_CREAT, 0644, p->nb);
	p->goal_s = sem_open(SEM_GOAL, O_CREAT, 0644, 0);
	p->stop_s = sem_open(SEM_STOP, O_CREAT, 0644, 0);
	p->stop = malloc(sizeof(int));
	if (!p->stop)
		return (1);
	*(p->stop) = 0;
	return (0);
}
