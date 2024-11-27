/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:50 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Move the character up. */

void	up(t_data *data)
{
	int	n_x;
	int	n_y;

	n_x = data->player_x;
	n_y = data->player_y;
	if (n_y - 1 < 0)
		return ;
	if (data->map[n_y - 1][n_x] == ENEMY)
		hit_by_enemy(data);
	else if ((n_y - 1) >= 0 && data->map[n_y - 1][n_x] != WALL
		&& (n_y - 1) >= 0 && data->map[n_y - 1][n_x] != EXIT)
	{
		data->map[n_y][n_x] = FLOOR;
		data->map[n_y - 1][n_x] = START;
		data->player_y = n_y - 1;
		data->count++;
		data->player_current_image = data->img_p_back;
		ft_printf("Moves : %d\n", data->count);
	}
	else
		end_game(data);
}

/* Move the character down. */

void	down(t_data *data)
{
	int	n_x;
	int	n_y;

	n_x = data->player_x;
	n_y = data->player_y;
	if (n_y + 1 < 0)
		return ;
	if (data->map[n_y + 1][n_x] == ENEMY)
		hit_by_enemy(data);
	else if ((n_y + 1) < data->map_height && data->map[n_y + 1][n_x] != WALL
		&& (n_y + 1) < data->map_height && data->map[n_y + 1][n_x] != EXIT)
	{
		data->map[n_y][n_x] = FLOOR;
		data->map[n_y + 1][n_x] = START;
		data->player_y = n_y + 1;
		data->count++;
		data->player_current_image = data->img_p_face;
		ft_printf("Moves : %d\n", data->count);
	}
	else
		end_game(data);
}

/* Move the character on the left. */

void	left(t_data *data)
{
	int	n_x;
	int	n_y;

	n_x = data->player_x;
	n_y = data->player_y;
	if (n_x - 1 < 0)
		return ;
	if (data->map[n_y][n_x - 1] == ENEMY)
		hit_by_enemy(data);
	else if ((n_x - 1) >= 0 && data->map[n_y][n_x - 1] != WALL
		&& (n_x - 1) >= 0 && data->map[n_y][n_x - 1] != EXIT)
	{
		data->map[n_y][n_x] = FLOOR;
		data->map[n_y][n_x - 1] = START;
		data->player_x = n_x - 1;
		data->count++;
		data->player_current_image = data->img_p_left;
		ft_printf("Moves : %d\n", data->count);
	}
	else
		end_game(data);
}

/* Move the character on the right. */

void	right(t_data *data)
{
	int	n_x;
	int	n_y;

	n_x = data->player_x;
	n_y = data->player_y;
	if (n_x + 1 < 0)
		return ;
	if (data->map[n_y][n_x + 1] == ENEMY)
		hit_by_enemy(data);
	else if ((n_x + 1) < data->map_width && data->map[n_y][n_x + 1] != WALL
		&& (n_x + 1) < data->map_width && data->map[n_y][n_x + 1] != EXIT)
	{
		data->map[n_y][n_x] = FLOOR;
		data->map[n_y][n_x + 1] = START;
		data->player_x = n_x + 1;
		data->count++;
		data->player_current_image = data->img_p_right;
		ft_printf("Moves : %d\n", data->count);
	}
	else
		end_game(data);
}

/* Handle keys according to what's pressed. */

int	handle_input(int key, t_data *data)
{
	if (key == XK_W || key == XK_w || key == XK_Up)
		up(data);
	else if (key == XK_A || key == XK_a || key == XK_Left)
		left(data);
	else if (key == XK_S || key == XK_s || key == XK_Down)
		down(data);
	else if (key == XK_D || key == XK_d || key == XK_Right)
		right(data);
	else
		return (0);
	put_image(data);
	return (0);
}
