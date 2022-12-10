/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:33:55 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/10 14:43:04 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	think(t_philo *p)
{
	logs("is thinking", p->id);
	sem_wait(p->fork_s);
	if (*(p->stop))
		return ;
	logs("has taken a fork", p->id);
	sem_wait(p->fork_s);
	if (*(p->stop))
		return ;
	logs("has taken a fork", p->id);
}

void	eat(t_philo *p)
{
	p->last = get_time();
	logs("is eating", p->id);
	while (p->last + p->eat > get_time())
	{
		if (*(p->stop))
			break ;
	}
	sem_post(p->fork_s);
	sem_post(p->fork_s);
	if (*(p->stop))
		return ;
	sem_post(p->goal_s);
}

void	routine(t_philo *p)
{
	int	tmp;

	pthread_create(&(p->stop_t), NULL, &check_stop, p);
	pthread_create(&(p->die_t), NULL, &check_die, p);
	while (1)
	{
		if (*(p->stop))
			break ;
		think(p);
		if (*(p->stop))
			break ;
		eat(p);
		if (*(p->stop))
			break ;
		logs("is sleeping", p->id);
		tmp = get_time();
		while (tmp + p->slp > get_time())
		{
			if (*(p->stop))
				break ;
		}
	}
	pthread_join(p->stop_t, NULL);
	pthread_join(p->die_t, NULL);
	return ;
}

int	birth(t_philo *p, int *pids)
{
	int	i;

	i = -1;
	while (++i < p->nb)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			p->id = i + 1;
			p->last = get_time();
			routine(p);
			free_close(p, pids);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			i;
	int			*pids;
	t_philo		philo;
	pthread_t	checker;

	if (ac < 5 || ft_atoi(av[1]) == 0 || ac > 6 || init_philo(&philo, ac, av))
		return (1);
	pids = malloc(philo.nb * sizeof(int));
	if (!pids)
		return (2);
	if (birth(&philo, pids))
		return (0);
	pthread_create(&checker, NULL, &check_goal, (void *) &philo);
	i = -1;
	while (++i < philo.nb)
		waitpid(pids[i], NULL, 0);
	*(philo.stop) = 1;
	sem_post(philo.goal_s);
	pthread_join(checker, NULL);
	free_close(&philo, pids);
	return (0);
}
