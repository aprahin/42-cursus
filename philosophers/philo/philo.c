/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:17:10 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/09 22:47:37 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **p, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (p[i]->next_f)
			free(p[i]->next_f);
		p[i]->next_f = NULL;
		if (p[i]->next_m)
		{
			pthread_mutex_destroy(p[i]->next_m);
			free(p[i]->next_m);
		}
		p[i]->next_m = NULL;
	}
	free(p[0]->stop);
	free(p[0]->goal);
	if (p[0]->goal_m)
	{
		pthread_mutex_destroy(p[0]->goal_m);
		free(p[0]->goal_m);
	}
	while (--i >= 0)
		free(p[i]);
	free(p);
}

int	set_goal(t_philo **p, char **av, int i)
{
	if (i + 1 == 1)
	{
		p[i]->goal = malloc(sizeof(int));
		if (!(p[i]->goal))
			return (1);
		p[i]->goal_m = malloc(sizeof(pthread_mutex_t));
		if (!(p[i]->goal_m))
			return (1);
		if (av[5])
		{
			*(p[i]->goal) = ft_atoi(av[5]) * ft_atoi(av[1]);
			p[i]->max_eat = ft_atoi(av[5]);
		}
		else
		{
			*(p[i]->goal) = -1;
			p[i]->max_eat = 0;
		}
		pthread_mutex_init(p[i]->goal_m, NULL);
		return (0);
	}
	p[i]->goal = p[0]->goal;
	p[i]->goal_m = p[0]->goal_m;
	p[i]->max_eat = p[0]->max_eat;
	return (0);
}

int	init_philos(t_philo **p, char **av, int i)
{
	p[i]->id = i + 1;
	p[i]->die = ft_atoi(av[2]);
	p[i]->eat = ft_atoi(av[3]);
	p[i]->slp = ft_atoi(av[4]);
	if (alloc_forks(p, av, i))
		return (1);
	pthread_mutex_init(p[i]->next_m, NULL);
	if (set_goal(p, av, i))
		return (1);
	*(p[i]->next_f) = 1;
	p[i]->last = get_time();
	if (i + 1 == 1)
	{
		p[i]->stop = malloc(sizeof(int));
		*(p[i]->stop) = 0;
	}
	else
		p[i]->stop = p[0]->stop;
	if (!(p[i]->stop))
		return (1);
	return (0);
}

int	alloc_philos(t_philo **philos, char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			free_philos(philos, i);
			return (1);
		}
		if (init_philos(philos, av, i))
		{
			free_philos(philos, i + 1);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			i;
	pthread_t	*threads;
	t_philo		**philos;

	if (ac < 5 || ft_atoi(av[1]) == 0 || ac > 6)
		return (1);
	philos = malloc(ft_atoi(av[1]) * sizeof(t_philo *));
	if (!philos)
		return (2);
	if (alloc_philos(philos, av))
		return (3);
	threads = malloc(ft_atoi(av[1]) * sizeof(pthread_t));
	if (!threads)
		return (4);
	i = -1;
	while (++i < ft_atoi(av[1]))
		pthread_create(&threads[i], NULL, &routine, philos[i]);
	i = -1;
	while (++i < ft_atoi(av[1]))
		pthread_join(threads[i], NULL);
	free_philos(philos, ft_atoi(av[1]));
	free(threads);
	return (0);
}
