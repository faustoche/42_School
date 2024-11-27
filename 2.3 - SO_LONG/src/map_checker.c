/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:55:00 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the first line is only walls*/

int	validate_walls(char *line, size_t width)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		if (line[i] != '1')
		{
			ft_printf("Error\nMap is not surrounded by walls\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

size_t	get_line_length(char *line)
{
	size_t	line_length;

	line_length = ft_strlen(line);
	if (line_length > 0 && line[line_length - 1] == '\n')
		line_length--;
	return (line_length);
}

/* Check if the first character of each line is a wall */

int	check_line_validity(char *line, size_t line_length, t_map *map)
{
	if (line_length != (size_t)map->width)
	{
		ft_printf("Error\nMap isn't a rectangle\n");
		return (-1);
	}
	if (line[0] != '1' || line[line_length - 1] != '1')
	{
		ft_printf("Error\nMap is not surrounded by walls\n");
		return (-1);
	}
	return (0);
}

int	validate_last_line(char *line, size_t line_length)
{
	size_t	i;

	i = 0;
	while (i < line_length)
	{
		if (line[i] != '1')
		{
			ft_printf("Error\nMap is not surrounded by walls\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
