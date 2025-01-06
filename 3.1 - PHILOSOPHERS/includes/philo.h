/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:51:22 by fcrocq            #+#    #+#             */
/*   Updated: 2025/01/06 15:20:51 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

/*-------------- OUTPUT --------------*/

# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define FORK "has taken a fork\n"
# define DIE "died\n"

/*-------------- STRUCTURES / THREADS --------------*/

struct	s_philo;

typedef struct s_data
{
	int					must_eat;
	int					nb_philo;
	int					sleep_time;
	int					eat_time;
	int					die_time;
	int					died;
	int					start_time;
	struct s_philo		*philo;
	pthread_mutex_t		*lock;
	pthread_mutex_t		message;
	pthread_mutex_t		died_mutex;
	pthread_mutex_t		mutex_last_meal;
}	t_data;

typedef struct s_philo
{
	int					fork_left;
	int					fork_right;
	int					id;
	int					meals_eaten;
	int					time_to_eat;
	int					time_to_sleep;
	time_t				last_meal;
	time_t				started_at;
	pthread_t			thread;
	t_data				*data;
	pthread_mutex_t		*lock;
	pthread_mutex_t		*message;
}	t_philo;

/*-------------- FUNCTIONS --------------*/

/* Eating */

void	forks_check(t_philo *philo, int *left_fork, int *right_fork);
void	update_meal(t_philo *philo);
int		eat(t_philo *philo);
int		check_death(t_philo *philo);

/* Init datas */

int		init_data(int ac, char **av, t_data *data);
int		init_malloc(t_data *data);
void	init_forks(t_data *data);
void	init_philo(t_data *data);

/* Init threads */

void	init_thread(t_data *data);
void	init_mutex(t_data *data, int nb_philo, int k);
void	check_mutex(t_data *data, int nb_philo);

/* Main */

void	start_simulation(t_data *data);
void	cleanup_data(t_data *data);
int		single_philo(t_philo *philo);

/* Routine */

void	*routine(void *arg);
int		sleep_think(t_philo *philo);
int		check_philo_status(t_data *data, int i);
int		meal_done(t_data *data);
int		monitoring(t_data *data, int i);

/* Utils */

time_t	get_time(void);
long	ft_atoi(char *str);
void	ft_usleep(long int time);
void	print_message(char *str, t_philo *philo);

#endif