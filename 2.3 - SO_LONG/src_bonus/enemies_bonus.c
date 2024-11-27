/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:55:32 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_data *data)
{
	int	height;
	int	width;

	data->img_enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			"src_bonus/textures/ENEMY/enemy1.xpm", &width, &height);
	if (!data->img_enemy)
	{
		ft_printf("Error\nCan't open image file\n");
		handle_close(data);
	}
}

void	hit_by_enemy(t_data *data)
{
	data->count++;
	ft_printf("Moves : %d\n", data->count);
	ft_printf("Oh no, you got hit by a meteor...\n");
	handle_close(data);
}
