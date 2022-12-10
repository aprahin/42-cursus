/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:32:16 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/10 14:41:03 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include "notlibft.h"
# define SEM_FORK "sem_fork"
# define SEM_GOAL "sem_goal"
# define SEM_STOP "sem_stop"

// memset
# include <string.h>

// printf
# include <stdio.h>

// malloc, free
# include <stdlib.h>

// write, usleep, fork
# include <unistd.h>

// gettimeofday
# include <sys/time.h>

// waitpid
# include <sys/wait.h>

// pthread_{create, detach, join}
# include <pthread.h>

// kill
# include <signal.h>

// sems
# include <semaphore.h>

// O_ constants
# include <fcntl.h>

// mode constants
# include <sys/stat.h>

typedef struct s_philo
{
	int			nb;
	int			id;
	int			die;
	int			eat;
	int			slp;
	int			last;
	int			max_eat;
	int			goal;
	int			*stop;
	sem_t		*fork_s;
	sem_t		*goal_s;
	sem_t		*stop_s;
	pthread_t	stop_t;
	pthread_t	die_t;
}	t_philo;

// philo_bonus.c
void	think(t_philo *p);
void	eat(t_philo *p);
void	routine(t_philo *p);
int		birth(t_philo *p, int *pids);

// check.c
void	*check_stop(void *passed);
void	*check_die(void *passed);
void	*check_goal(void *passed);

// utils.c
void	logs(char *msg, int ic);
int		get_time(void);
void	free_close(t_philo *p, int *pids);
int		init_philo(t_philo *p, int ac, char **av);

#endif