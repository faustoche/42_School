/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:54 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	check_arguments(ac, av);
	init_data(&data);
	init_map_path(&map, av[1]);
	parse_map(&map);
	init_data_map(&data, &map);
	find_player_position(&data);
	verify_paths(&data);
	init_window_and_run(&data);
	handle_close(&data);
	return (EXIT_SUCCESS);
}

/* Check arguments and extension */

void	check_arguments(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nOnly one argument needed\n");
		exit(EXIT_FAILURE);
	}
	if (check_extension(av[1]) != 0)
		exit(EXIT_FAILURE);
}

/* Find the actual player position on the map */

void	find_player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == START)
			{
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
}

/* Verify if the path is available to go to the exit */

void	verify_paths(t_data *data)
{
	int	items_total;
	int	*visited;

	visited = NULL;
	init_visited_path(&visited, data->map_width, data->map_height);
	items_total = check_items(data);
	data->exit_access = 0;
	data->collect_access = 0;
	check_path(data, (t_point){data->player_x, data->player_y}, visited);
	if (data->exit_access == 0 || data->collect_access < items_total)
	{
		ft_printf("Error\nCannot access to exit or items\n");
		free(visited);
		free_all(data->map);
		if (data->map_path)
		{
			free(data->map_path);
			data->map_path = NULL;
		}
		exit(EXIT_FAILURE);
	}
	free(visited);
}

/* Init the window and the game */

void	init_window_and_run(t_data *data)
{
	if (open_window(data) != 0)
	{
		free(data->map_path);
		data->map_path = NULL;
		handle_close(data);
	}
	init_images(data);
	init_enemy(data);
	put_image(data);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, close_win, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		handle_close, data);
	mlx_loop(data->mlx_ptr);
}
