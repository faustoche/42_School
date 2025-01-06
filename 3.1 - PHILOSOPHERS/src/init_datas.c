/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:58:49 by fcrocq            #+#    #+#             */
/*   Updated: 2025/01/06 14:54:16 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Initiate all the datas of the data structure
** Check for that the input is valid
** Call initiate malloc
*/

int	init_data(int ac, char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	if ((data->nb_philo <= 0 || data->die_time <= 0 || data->eat_time <= 0
			|| data->sleep_time <= 0) || (ac == 6 && data->must_eat <= 0))
	{
		printf("Numbers are invalids\n");
		return (-1);
	}
	data->died = 0;
	data->start_time = 0;
	init_malloc(data);
	return (0);
}

/*
** Initiate the variables that needs malloc
** Check if there's any problem with the malloc
*/

int	init_malloc(t_data *data)
{
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	data->lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philo);
	if (!data->lock || !data->philo)
	{
		printf("Failed malloc\n");
		if (data->philo)
			free(data->philo);
		if (data->lock)
			free(data->lock);
		return (-1);
	}
	return (0);
}

/*
** While the loop iterate on the number of philo, the function check:
** - i = 0 : first, his left fork is the first and the last one (circle)
** - i % 2 == 0 : even, his left fork is his neighbors one (at neighbor index)
** - i % 2 != 0 : uneven, his left fork is his at his index (i)
** If the philo is even, he gets his own right fork (he gave the left one)
** If the philo is uneven, his right fork is neighbors's one 
*/

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (i == 0)
			data->philo[i].fork_left = data->nb_philo - 1;
		else if (i % 2 == 0)
			data->philo[i].fork_left = i - 1;
		else
			data->philo[i].fork_left = i;
		if (i % 2 == 0)
			data->philo[i].fork_right = i;
		else
			data->philo[i].fork_right = i - 1;
		i++;
	}
	init_philo(data);
}

/*
** Initiate the datas of the philo structure
*/

void	init_philo(t_data *data)
{
	int		i;
	time_t	start;

	start = get_time();
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].lock = data->lock;
		data->philo[i].meals_eaten = data->must_eat;
		data->philo[i].data = data;
		data->philo[i].time_to_eat = data->eat_time;
		data->philo[i].time_to_sleep = data->sleep_time;
		data->philo[i].started_at = start;
		data->philo[i].last_meal = start;
		data->philo[i].message = &data->message;
		i++;
	}
}
