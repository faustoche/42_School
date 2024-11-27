/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:41 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initiate the grid. */

void	map_filling(t_map *grid)
{
	grid->x = 0;
	grid->y = 0;
}

/* Allocate the line to fill and free in case of problems. */

void	allocate_line(t_data *data, t_map pos)
{
	data->map[pos.y] = (char *)malloc((data->map_width + 1) * sizeof(char));
	if (!data->map[pos.y])
	{
		ft_printf("Error\nAllocation failed\n");
		allocation_error(data);
	}
}

/* Read the file, and copies every symbol into map tab. */

int	read_line_grid(int fd, t_data *data)
{
	char	*line;
	t_map	grid;

	grid.y = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		write_error(fd);
	line = get_next_line(fd);
	while (line)
	{
		if (allocate_and_copy_line(data, line, &grid) != 0)
		{
			free(line);
			free_map_data(data);
			close(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
		grid.y++;
	}
	close(fd);
	return (0);
}

/* Initiate the map and fill the grid with map info. */

int	grid_init(t_data *data)
{
	int	fd;

	fd = open_and_allocate_map(data);
	if (fd < 0)
		return (-1);
	if (read_line_grid(fd, data) < 0)
	{
		free_map_data(data);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

/* Display an error message and close the file if needed */

int	write_error(int fd)
{
	ft_printf("Error\nCan't open the map\n");
	if (fd >= 0)
		close(fd);
	return (-1);
}
