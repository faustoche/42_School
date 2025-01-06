/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:57:46 by fcrocq            #+#    #+#             */
/*   Updated: 2025/01/06 14:58:03 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Iterate into a while loop for each philosopher. 
** Initiate the routine in each thread with pthread_create
** If there is any problem, join the threads before leaving.
** J is used to check if each thread has been waited
*/

void	init_thread(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&routine, &data->philo[i]) != 0)
		{
			printf("Failed to create thread for philosophers\n");
			while (j < i)
			{
				pthread_join(data->philo[j].thread, NULL);
				j++;
			}
			return ;
		}
		i++;
	}
}

/*
** Initiate the mutexes and destroy them if there is a problem
*/

void	init_mutex(t_data *data, int nb_philo, int k)
{
	int	i;

	i = 0;
	if (k == 0)
		check_mutex(data, nb_philo);
	else
	{
		pthread_mutex_destroy(&data->message);
		pthread_mutex_destroy(&data->died_mutex);
		pthread_mutex_destroy(&data->mutex_last_meal);
		while (i < nb_philo)
		{
			pthread_mutex_destroy(&data->lock[i]);
			i++;
		}
	}
}

/*
** Initiate the mutexes
*/

void	check_mutex(t_data *data, int nb_philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->message, NULL) != 0
		|| pthread_mutex_init(&data->died_mutex, NULL) != 0
		|| pthread_mutex_init(&data->mutex_last_meal, NULL) != 0)
	{
		printf("Failed to initialize mutex\n");
		return ;
	}
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&(data->lock[i]), NULL) != 0)
		{
			printf("Failed to initialize lock\n");
			while (--i >= 0)
				pthread_mutex_destroy(&(data->lock[i]));
			pthread_mutex_destroy(&data->message);
			pthread_mutex_destroy(&data->died_mutex);
			pthread_mutex_destroy(&data->mutex_last_meal);
			return ;
		}
		i++;
	}
}
