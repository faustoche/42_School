/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:47:39 by fcrocq            #+#    #+#             */
/*   Updated: 2025/06/19 10:24:31 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_datas(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->height_map = 0;
	game->width_map = 0;
}

void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("NSEW", game->map[y][x]))
			{
				game->player_x = x;
				game->player_y = y;
				game->player_dir = game->map[y][x];
				game->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

/*
** Game->player * TILE_SIZE = position du coin supérieur gauche de la case
** TILE_SIZE / 2 = placer le joueur au centre de la case
** On garde l'angle à 60 degré car c'est l'angle le plus équilibré 
** player->fov_rd = (60 * M_PI) / 180 = conversion de 60 degres en radians
** player->rot = 0; // rotation de la vue, tourner à gauche ou à droite 
*/

void	init_player(t_player *player, t_game *game)
{
	player->player_x = game->player_x * TILE_SIZE + TILE_SIZE / 2;
	player->player_y = game->player_y * TILE_SIZE + TILE_SIZE / 2;
	if (game->player_dir == 'N')
		player->angle = 3 * M_PI / 2;
	else if (game->player_dir == 'S')
		player->angle = M_PI / 2;
	else if (game->player_dir == 'E')
		player->angle = 0;
	else if (game->player_dir == 'W')
		player->angle = M_PI;
	player->fov_rd = (60 * M_PI) / 180;
	player->rot = 0;
	player->left_right = 0;
	player->up_down = 0;
}

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx || !mlx->game)
		return (0);
	destroy_images(mlx->game, mlx);
	if (mlx->game->mlx_ptr)
		mlx_loop_end(mlx->game->mlx_ptr);
	cleanup_mlx(mlx->game);
	cleanup_game(mlx->game);
	free(mlx->game);
	free(mlx->player);
	free(mlx->ray);
	exit(EXIT_SUCCESS);
	return (0);
}
