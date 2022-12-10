/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:18:00 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/09 22:48:59 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "notlibft.h"

// memset
# include <string.h>

// printf
# include <stdio.h>

// malloc, free
# include <stdlib.h>

// write, usleep
# include <unistd.h>

// gettimeofday
# include <sys/time.h>

/* pthread_{create, detach, join, mutex_init,
mutex_destroy, mutex_lock, mutex_unlock} */
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				die;
	int				eat;
	int				slp;
	int				last;
	int				max_eat;
	int				forks;
	int				*goal;
	int				*stop;
	int				*prev_f;
	int				*next_f;
	pthread_mutex_t	*goal_m;
	pthread_mutex_t	*prev_m;
	pthread_mutex_t	*next_m;
}	t_philo;

// philo.c
void	free_philos(t_philo **p, int n);
int		set_goal(t_philo **p, char **av, int i);
int		init_philos(t_philo **p, char **av, int i);
int		alloc_philos(t_philo **philos, char **av);

// utils.c
void	logs(char *msg, int ic);
int		get_time(void);

// forks.c
int		check_forks_mutex(t_philo *p);
int		alloc_forks(t_philo **p, char **av, int i);
void	take_fork(t_philo *p);
void	release_fork(t_philo *p);

// routine.c
void	*routine(void *passed);
void	dream(t_philo *p);
void	eat(t_philo *p);
void	think(t_philo *p);
void	die(t_philo *p);

#endif