/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:44 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialize the images. */

void	init_images(t_data *data)
{
	int	height;
	int	width;

	data->img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/ITEMS/item1.xpm", &width, &height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/FLOOR/floor.xpm", &width, &height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/WALLS/wall1.xpm", &width, &height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/EXIT/exit.xpm", &width, &height);
	data->img_p_back = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/PLAYER/player_back1.xpm", &width, &height);
	data->img_p_face = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/PLAYER/player_face1.xpm", &width, &height);
	data->img_p_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/PLAYER/player_left1.xpm", &width, &height);
	data->img_p_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/textures/PLAYER/player_right1.xpm", &width, &height);
	data->player_current_image = data->img_p_face;
	if (!data->img_p_back || !data->img_p_face
		|| !data->img_p_right || !data->img_p_left
		|| !data->img_collect || !data->img_floor || !data->img_wall
		|| !data->img_exit)
		print_error_images(data);
}

/* Prepare the images for the window */

void	images_to_window(t_data *data, int height, int width)
{
	char	symbol;
	int		y;
	int		x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			symbol = data->map[y][x];
			if (symbol == WALL)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_wall, x * width, y * height);
			else if (symbol == COLLECT)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_collect, x * width, y * height);
			else if (symbol == EXIT)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_exit, x * width, y * height);
			x++;
		}
		y++;
	}
}

/* Same but with the player and the enemy */

void	player_enemy_to_window(t_data *data, int height, int width)
{
	char	symbol;
	int		y;
	int		x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			symbol = data->map[y][x];
			if (symbol == START)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->player_current_image, x * width, y * height);
			else if (symbol == ENEMY)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_enemy, x * width, y * height);
			x++;
		}
		y++;
	}
}

/* DIsplay the images on the window */

void	put_image(t_data *data)
{
	int	width;
	int	height;

	width = 100;
	height = 100;
	put_floor(data, width, height);
	images_to_window(data, height, width);
	player_enemy_to_window(data, height, width);
}

/* Draw the floor on the window. */

void	put_floor(t_data *data, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_floor, x * width, y * height);
			x++;
		}
		y++;
	}
}
