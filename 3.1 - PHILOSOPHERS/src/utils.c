/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:06:11 by fcrocq            #+#    #+#             */
/*   Updated: 2025/01/06 15:12:58 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	static time_t	start_time = 0;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (start_time == 0)
		start_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (current_time.tv_sec * 1000 + current_time.tv_usec
		/ 1000 - start_time);
}

long	ft_atoi(char *str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' && str[++i])
		sign = -1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (LONG_MAX);
		result = 10 * result + (str[i++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (LONG_MAX);
	}
	return (result * sign);
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(10);
}

void	print_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->died_mutex);
	if (!philo->data->died && philo->meals_eaten != 0)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s", get_time() - philo->started_at, philo->id, str);
		pthread_mutex_unlock(philo->message);
	}
	pthread_mutex_unlock(&philo->data->died_mutex);
}
