/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:30 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Free every line of the map with data structure */

void	free_map_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->map_height)
		{
			if (data->map[i])
			{
				free(data->map[i]);
				data->map[i] = NULL;
			}
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
}

/* Free every line of the map with a char ** */

void	free_all(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		exit(EXIT_FAILURE);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/* Destroy images and initialize them at null */

void	destroy_image_safe(void *mlx_ptr, void **img_ptr)
{
	if (*img_ptr)
	{
		mlx_destroy_image(mlx_ptr, *img_ptr);
		*img_ptr = NULL;
	}
}
