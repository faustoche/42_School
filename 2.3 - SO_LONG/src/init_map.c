/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:47 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialize the map path */

void	init_map_path(t_map *map, char *path)
{
	map->path = ft_strdup(path);
	if (!map->path)
	{
		ft_printf("Error\nFailed memory allocation\n");
		free(map->path);
		map->path = NULL;
		exit(EXIT_FAILURE);
	}
}

/* Make sure that the map is working before opening it */

void	parse_map(t_map *map)
{
	if (map_parsing_lines(map) != 0)
	{
		free(map->path);
		map->path = NULL;
		exit(EXIT_FAILURE);
	}
	if (map_parsing_symbols(map) != 0)
	{
		free(map->path);
		map->path = NULL;
		exit(EXIT_FAILURE);
	}
}

/* Initialize the data related to the map */

void	init_data_map(t_data *data, t_map *map)
{
	data->map_height = map->height;
	data->map_path = map->path;
	data->map_width = map->width;
	data->map = NULL;
	if (grid_init(data) != 0)
	{
		free(map->path);
		map->path = NULL;
		exit(EXIT_FAILURE);
	}
}

/* Initialize all the datas to avoid any leaks or conditional jump */

void	init_data(t_data *data)
{
	data->img_collect = NULL;
	data->img_floor = NULL;
	data->img_wall = NULL;
	data->img_exit = NULL;
	data->img_p_back = NULL;
	data->img_p_face = NULL;
	data->img_p_left = NULL;
	data->img_p_right = NULL;
	data->img_enemy = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->map_path = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->count = 0;
	data->exit_access = 0;
	data->collect_access = 0;
	data->enemy_access = 0;
}
