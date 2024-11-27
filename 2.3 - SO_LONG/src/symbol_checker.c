/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:55:20 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Verify any wrong symbol */

int	check_map_symbols(int fd)
{
	char	*line;
	int		p_count;
	int		e_count;
	int		c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (process_line(line, &p_count, &e_count, &c_count) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (check_map_requirements(p_count, e_count, c_count));
}

/* Check if there's a player, an exit and at least 1 collectible */

int	check_map_requirements(int p_count, int e_count, int c_count)
{
	if (p_count != 1 || e_count != 1 || c_count < 1)
	{
		ft_printf("Error\nMissing player, exit or item\n");
		return (-1);
	}
	return (0);
}

int	process_line(char *line, int *p_count, int *e_count, int *c_count)
{
	size_t	i;
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line_len > 0 && line[line_len - 1] == '\n')
			line_len--;
	i = 0;
	while (i < line_len)
	{
		if (!valid_symbol(line[i]))
		{
			ft_printf("Error\nInvalid symbol on the map\n");
			return (-1);
		}
		update_counts(line[i], p_count, e_count, c_count);
		i++;
	}
	return (0);
}

int	valid_symbol(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E'
		|| c == 'C' || c == 'S');
}

void	update_counts(char c, int *p_count, int *e_count, int *c_count)
{
	if (c == 'P')
		(*p_count)++;
	else if (c == 'E')
		(*e_count)++;
	else if (c == 'C')
		(*c_count)++;
}
