/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:50:11 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/22 15:36:09 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*select_wall_texture(t_ray *ray, t_game *game)
{
	if (ray->flag == 1)
	{
		if (cos(ray->ray_angle) > 0)
			return (&game->east);
		else
			return (&game->west);
	}
	else
	{
		if (sin(ray->ray_angle) < 0)
			return (&game->north);
		else
			return (&game->south);
	}
}

/* Calculus for perspective projection */

int	calculate_wall_height(t_ray *ray, t_player *player)
{
	return ((int)((TILE_SIZE / ray->distance)
		* ((WIDTH / 2) / tan(player->fov_rd / 2))));
}

void	draw_textured_wall(t_mlx *mlx, int ray, int top_pixel, int bottom)
{
	draw_wall_portion(mlx, ray, top_pixel, bottom);
}
