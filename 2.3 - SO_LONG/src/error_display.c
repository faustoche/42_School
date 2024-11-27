/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:27 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* In case of failed memory allocation */

void	allocation_error(t_data *data)
{
	ft_printf("Error\nMemory allocation\n");
	if (data->map_path)
	{
		free(data->map_path);
		data->map_path = NULL;
	}
	if (data->map)
		free_map_data(data);
	handle_close(data);
	exit (EXIT_FAILURE);
}

/* Cleanup everything to unsure there's no leaks */

void	cleanup(t_data *data)
{
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_collect);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_floor);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_wall);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_exit);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_p_back);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_p_face);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_p_left);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_p_right);
	destroy_image_safe(data->mlx_ptr, (void **)&data->img_enemy);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free_map_data(data);
	if (data->map_path)
	{
		free(data->map_path);
		data->map_path = NULL;
	}
	exit(EXIT_SUCCESS);
}

void	print_error_images(t_data *data)
{
	ft_printf("Error\nCan't open image file\n");
	handle_close(data);
}
