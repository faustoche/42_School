/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:57 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Open the file and allocate the map. */

int	open_and_allocate_map(t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCan't open file\n");
		return (-1);
	}
	data->map = (char **)malloc((data->map_height + 1) * sizeof(char *));
	if (!data->map)
	{
		close(fd);
		allocation_error(data);
		return (-1);
	}
	while (i < data->map_height)
	{
		data->map[i] = NULL;
		i++;
	}
	data->map[data->map_height] = NULL;
	return (fd);
}

/* Copies every line in grid and make sure that the map is not too big */

int	allocate_and_copy_line(t_data *data, char *line, t_map *grid)
{
	int	x;

	data->map[grid->y] = (char *)malloc((data->map_width + 1) * sizeof(char));
	if (!data->map[grid->y])
	{
		free(line);
		free_map_data(data);
		return (-1);
	}
	if (map_size(data) < 0)
	{
		ft_printf("Error\nMap is too big\n");
		return (-1);
	}
	x = 0;
	while (x < data->map_width)
	{
		data->map[grid->y][x] = line[x];
		x++;
	}
	data->map[grid->y][data->map_width] = '\0';
	return (0);
}

/* Fill the tiles according to the map. */

void	till_filling(t_data *data, int fd)
{
	char	*line;
	t_map	pos;

	pos.y = 0;
	line = get_next_line(fd);
	while (line)
	{
		pos.x = 0;
		while (line[pos.x])
		{
			data->map[pos.y][pos.x] = line[pos.x];
			pos.x++;
		}
		free(line);
		pos.y++;
		line = get_next_line(fd);
	}
	close(fd);
}

/* Check the map size */

int	map_size(t_data *data)
{
	if (data->map_width >= 20 || data->map_height >= 11)
		return (-1);
	return (0);
}
