/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:34 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check for the first line. */

int	read_and_validate_first_line(int fd, t_map *map)
{
	char	*line;
	size_t	i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_printf("Error\nEmpty file\n");
		return (-1);
	}
	map->width = (int)ft_strlen(line);
	if (map->width > 0 && line[map->width - 1] == '\n')
		map->width--;
	if (validate_walls(line, map->width) == -1)
	{
		free(line);
		close(fd);
		return (-1);
	}
	map->height = 1;
	free(line);
	return (0);
}

int	read_and_check_lines(int fd, t_map *map)
{
	char	*last_line;

	last_line = NULL;
	if (handle_lines(fd, map, &last_line) == -1)
		return (-1);
	if (handle_last_line(last_line, map->width) == -1)
		return (-1);
	return (0);
}

int	handle_lines(int fd, t_map *map, char **last_line)
{
	char	*line;
	size_t	line_length;

	line = get_next_line(fd);
	while (line != NULL)
	{
		line_length = get_line_length(line);
		if (check_line(line, line_length, map, last_line) == -1)
			return (-1);
		*last_line = line;
		map->height++;
		line = get_next_line(fd);
	}
	return (0);
}

int	check_line(char *line, size_t line_length, t_map *map, char **last_line)
{
	if (check_line_validity(line, line_length, map))
	{
		free(line);
		free(*last_line);
		return (-1);
	}
	if (*last_line)
		free(*last_line);
	return (0);
}

int	handle_last_line(char *last_line, size_t map_width)
{
	if (last_line && validate_last_line(last_line, map_width) == -1)
	{
		free(last_line);
		return (-1);
	}
	free(last_line);
	return (0);
}
