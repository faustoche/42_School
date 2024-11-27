/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:55:17 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* CHeck if the path if valid */

void	check_path(t_data *data, t_point p, int *visited)
{
	if (!within_boundaries(data, p) || data->map[p.y][p.x] == '1'
		|| visited[p.y * data->map_width + p.x])
		return ;
	else if (!within_boundaries(data, p) || data->map[p.y][p.x] == 'E'
		|| visited[p.y * data->map_width + p.x])
	{
		data->exit_access = 1;
		return ;
	}
	else if (!within_boundaries(data, p) || data->map[p.y][p.x] == 'S'
		|| visited[p.y * data->map_width + p.x])
	{
		data->enemy_access++;
		return ;
	}
	visited[p.y * data->map_width + p.x] = 1;
	update_access(data, p);
	flood_fill_check(data, p, visited);
}

/* Initialized the validated path */

void	init_visited_path(int **visited, int width, int height)
{
	int	i;

	*visited = malloc(sizeof(int) * (height * width));
	if (!*visited)
	{
		ft_printf("Error\n");
		return ;
	}
	i = 0;
	while (i < height * width)
	{
		(*visited)[i] = 0;
		i++;
	}
}

/* Is the path within the boundaries ? */

int	within_boundaries(t_data *data, t_point p)
{
	return (p.x >= 0 && p.y >= 0 && p.x < data->map_width
		&& p.y < data->map_height);
}

/* Update the access */

void	update_access(t_data *data, t_point p)
{
	if (data->map[p.y][p.x] == EXIT)
		data->exit_access = 1;
	else if (data->map[p.y][p.x] == COLLECT)
		data->collect_access++;
	else if (data->map[p.y][p.x] == ENEMY)
		data->enemy_access++;
	else if (data->map[p.y][p.x] != START)
		data->map[p.y][p.x] = 'V';
}

/* Flood fill */

void	flood_fill_check(t_data *data, t_point p, int *visited)
{
	check_path(data, (t_point){p.x, p.y - 1}, visited);
	check_path(data, (t_point){p.x, p.y + 1}, visited);
	check_path(data, (t_point){p.x - 1, p.y}, visited);
	check_path(data, (t_point){p.x + 1, p.y}, visited);
}
