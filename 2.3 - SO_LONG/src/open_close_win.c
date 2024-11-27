/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:55:13 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Open the window. */

int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		handle_close(data);
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, (100 * data->map_width),
			(100 * data->map_height), "so_long");
	if (!data->win_ptr)
	{
		handle_close(data);
	}
	return (0);
}

/* Close and kill the window. */

int	handle_close(t_data *data)
{
	int	i;

	i = 0;
	destroy_images(data);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	if (data->map_path)
	{
		free(data->map_path);
		data->map_path = NULL;
	}
	exit(EXIT_SUCCESS);
	return (0);
}

/* Close the window with escape. */

int	close_win(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		handle_close(data);
	return (0);
}

/* Destroy all of the images */

void	destroy_images(t_data *data)
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
}
