/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:59:02 by fcrocq            #+#    #+#             */
/*   Updated: 2025/01/06 14:49:37 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** If the philo is an even number, he will start to pick the left fork
** If the philo is an uneven number, he will pick the right one
*/

void	forks_check(t_philo *philo, int *first_fork, int *second_fork)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = philo->fork_left;
		*second_fork = philo->fork_right;
	}
	else
	{
		*first_fork = philo->fork_right;
		*second_fork = philo->fork_left;
	}
}

/*
** Lock the last_meal value so it's not changing in the meantime
** Update last_meal with get_time and unlock the value when done
** Decremente meals to follow the number of times each philo eat if needed
*/

void	update_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->died_mutex);
	pthread_mutex_lock(&philo->data->mutex_last_meal);
	philo->last_meal = get_time();
	if (philo->meals_eaten > 0)
		philo->meals_eaten--;
	pthread_mutex_unlock(&philo->data->mutex_last_meal);
	pthread_mutex_unlock(&philo->data->died_mutex);
	ft_usleep(philo->time_to_eat);
}

/*
** Main function the eating action
** Check if someone is dead.
** If someone died, return (-1) to stop simulation
** If everyone is still alive, simulation is going on
*/

int	eat(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	forks_check(philo, &first_fork, &second_fork);
	pthread_mutex_lock(&philo->lock[first_fork]);
	if (check_death(philo) == -1)
	{
		pthread_mutex_unlock(&philo->lock[first_fork]);
		return (-1);
	}
	pthread_mutex_unlock(&philo->lock[first_fork]);
	print_message(FORK, philo);
	pthread_mutex_lock(&philo->lock[second_fork]);
	if (check_death(philo) == -1)
	{
		pthread_mutex_unlock(&philo->lock[second_fork]);
		return (-1);
	}
	print_message(FORK, philo);
	print_message(EAT, philo);
	update_meal(philo);
	pthread_mutex_unlock(&philo->lock[second_fork]);
	return (0);
}

/*
** Lock the dying mutex
** If someone is already dead or they're is not meal left to eat, return (-1)
** Unlock the dying mutex
*/

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->died_mutex);
	if (philo->data->died || philo->meals_eaten == 0)
	{
		pthread_mutex_unlock(&philo->data->died_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->died_mutex);
	return (0);
}
