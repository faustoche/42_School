/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:22:15 by fcrocq            #+#    #+#             */
/*   Updated: 2025/01/06 15:04:09 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments");
		return (-1);
	}
	if (init_data(ac, av, &data) != 0)
		return (-1);
	start_simulation(&data);
	if (data.philo->meals_eaten == 0)
		printf("All philosophers ate %d times\n", data.must_eat);
	cleanup_data(&data);
	return (0);
}

/*
** Init everything
** Main thread wait for all the others
*/

void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	init_mutex(data, data->nb_philo, 0);
	init_forks(data);
	init_thread(data);
	monitoring(data, 0);
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	init_mutex(data, data->nb_philo, 1);
}

void	cleanup_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->died_mutex);
	pthread_mutex_destroy(&data->mutex_last_meal);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->lock[i]);
		i++;
	}
	if (data->philo)
		free(data->philo);
	if (data->lock)
		free(data->lock);
}

int	single_philo(t_philo *philo)
{
	if (philo->data->nb_philo == 1)
	{
		print_message(FORK, philo);
		ft_usleep(philo->data->die_time);
		print_message(DIE, philo);
		pthread_mutex_lock(&philo->data->died_mutex);
		philo->data->died = 1;
		pthread_mutex_unlock(&philo->data->died_mutex);
		return (1);
	}
	return (0);
}
