/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:55:05 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the map is valid. */

int	is_valid(t_map *map)
{
	if (map->height == 0 || map->width == 0)
	{
		ft_printf("Error\nMap is empty\n");
		free(map);
		map = NULL;
		return (-1);
	}
	return (0);
}

/* Parse the map. */

int	map_parsing_lines(t_map *map)
{
	int		fd;

	fd = open_map_file(map);
	if (fd < 0)
		return (-1);
	if (read_and_validate_first_line(fd, map) < 0)
	{
		close(fd);
		return (-1);
	}
	if (read_and_check_lines(fd, map) < 0)
	{
		close(fd);
		return (-1);
	}
	if (is_valid(map) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

/* Open and check for valid symbol */

int	map_parsing_symbols(t_map *map)
{
	int		fd;

	fd = open_map_file(map);
	if (fd < 0)
		return (-1);
	if (check_map_symbols(fd) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

/* Check the extension */

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		ft_printf("Error\nInvalid file name\n");
		return (-1);
	}
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		ft_printf("Error\nFile extension must be .ber\n");
		return (-1);
	}
	return (0);
}

/* Open the map file. */

int	open_map_file(t_map *map)
{
	int	fd;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCan't open file\n");
		return (-1);
	}
	return (fd);
}
