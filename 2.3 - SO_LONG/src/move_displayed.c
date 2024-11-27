/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_displayed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:55:09 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Print congrats at the very end */

void	end_game(t_data *data)
{
	int	new_y;
	int	new_x;

	new_x = data->player_x;
	new_y = data->player_y;
	if (data->map[new_y + 1][new_x] == EXIT && (check_items(data) == 0))
		congrats_end(data);
	else if (data->map[new_y - 1][new_x] == EXIT && (check_items(data) == 0))
		congrats_end(data);
	else if (data->map[new_y][new_x + 1] == EXIT && (check_items(data) == 0))
		congrats_end(data);
	else if (data->map[new_y][new_x - 1] == EXIT && (check_items(data) == 0))
		congrats_end(data);
}

void	congrats_end(t_data *data)
{
	data->count++;
	ft_printf("Moves : %d\n", data->count);
	ft_printf("CONGRATS ! You did it in %d moves !\n", data->count);
	handle_close(data);
}

/* Check the items, if there are some left, etc. */

int	check_items(t_data *data)
{
	int	i;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (data->map[y][i] == 'C')
				count++;
			i++;
		}
		y++;
	}
	return (count);
}
