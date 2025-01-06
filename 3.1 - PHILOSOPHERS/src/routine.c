/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:06:51 by fcrocq            #+#    #+#             */
/*   Updated: 2025/01/06 15:12:42 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Synchronise philo with usleep
** Handle the single philo cause
** Endless loop until soneone died or there's no meal left
*/

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_sleep / 2);
	if (single_philo(philo))
		return (NULL);
	while (1)
	{
		pthread_mutex_lock(&philo->data->died_mutex);
		if (philo->data->died || philo->meals_eaten == 0)
		{
			pthread_mutex_unlock(&philo->data->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->died_mutex);
		if (eat(philo) == -1)
			break ;
		if (sleep_think(philo) == -1)
			break ;
	}
	return (NULL);
}

/*
** If someone died, return (-1)
** Print sleep and usleep the sleeping time
** Check again if someone died in another thread
***/

int	sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->died_mutex);
	if (philo->data->died)
	{
		pthread_mutex_unlock(&philo->data->died_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->died_mutex);
	print_message(SLEEP, philo);
	ft_usleep(philo->time_to_sleep);
	pthread_mutex_lock(&philo->data->died_mutex);
	if (philo->data->died)
	{
		pthread_mutex_unlock(&philo->data->died_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->died_mutex);
	print_message(THINK, philo);
	return (0);
}

/*
** Check if someone died
** Update data->died
** Print dead message
*/

int	check_philo_status(t_data *data, int i)
{
	time_t	last_meal;
	time_t	current_time;

	pthread_mutex_lock(&data->mutex_last_meal);
	last_meal = data->philo[i].last_meal;
	pthread_mutex_unlock(&data->mutex_last_meal);
	current_time = get_time();
	if (current_time - last_meal > data->die_time)
	{
		pthread_mutex_lock(&data->died_mutex);
		if (data->philo[i].meals_eaten != 0 && !data->died)
		{
			data->died = 1;
			pthread_mutex_lock(data->philo[i].message);
			printf("%ld %d %s", current_time - data->philo[i].started_at,
				data->philo[i].id, DIE);
			pthread_mutex_unlock(data->philo[i].message);
		}
		pthread_mutex_unlock(&data->died_mutex);
		return (-1);
	}
	return (0);
}

/*
** Check if everyone ate the requiered number of meals
*/

int	meal_done(t_data *data)
{
	int	all_done;
	int	j;

	all_done = 1;
	j = 0;
	pthread_mutex_lock(&data->died_mutex);
	while (j < data->nb_philo)
	{
		if (data->philo[j].meals_eaten != 0)
			all_done = 0;
		j++;
	}
	pthread_mutex_unlock(&data->died_mutex);
	return (all_done);
}

/*
** Monitor everything 
*/

int	monitoring(t_data *data, int i)
{
	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (check_philo_status(data, i) == -1)
				return (-1);
			i++;
		}
		if (meal_done(data))
			return (0);
		ft_usleep(10);
	}
	return (0);
}
