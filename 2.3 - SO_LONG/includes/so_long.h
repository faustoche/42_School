/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:15 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define ENEMY 'S'
# define COLLECT 'C'
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <unistd.h>

/* Structure for floodfill */

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/* Structure for the game */

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_p_left;
	void	*img_p_right;
	void	*img_p_face;
	void	*img_p_back;
	void	*img_exit;
	void	*img_exit_back;
	void	*img_exit_face;
	void	*img_exit_left;
	void	*img_exit_right;
	void	*img_enemy;
	int		items_remaining;
	char	**map;
	char	*map_path;
	int		exit_access;
	int		collect_access;
	int		enemy_access;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collect_x;
	int		collect_y;
	int		enemy_x;
	int		enemy_y;
	int		items;
	int		count;
	int		map_width;
	int		map_height;
	int		moves;
	void	*player_current_image;
}	t_data;

/* Structure for the map */

typedef struct s_map
{
	char	*path;
	size_t	height;
	size_t	width;
	int		x;
	int		y;
	char	**grid;
}	t_map;

/* Error display */

void	allocation_error(t_data *data);
void	cleanup(t_data *data);
void	print_error_images(t_data *data);

/* Error map */

void	free_map_data(t_data *data);
void	free_all(char **arr);
void	destroy_image_safe(void *mlx_ptr, void **img_ptr);

/* File checker */

int		read_and_validate_first_line(int fd, t_map *map);
int		read_and_check_lines(int fd, t_map *map);
int		handle_lines(int fd, t_map *map, char **last_line);
int		check_line(char *line, size_t line_length, t_map *map, char **last_line);
int		handle_last_line(char *last_line, size_t map_width);

/* Grid */

void	map_filling(t_map *grid);
void	allocate_line(t_data *data, t_map pos);
int		read_line_grid(int fd, t_data *data);
int		grid_init(t_data *data);
int		write_error(int fd);

/* Init images */

void	init_images(t_data *data);
void	images_to_window(t_data *data, int height, int width);
void	player_enemy_to_window(t_data *data, int height, int width);
void	put_image(t_data *data);
void	put_floor(t_data *data, int width, int height);

/* Init map */

void	init_map_path(t_map *map, char *path);
void	parse_map(t_map *map);
void	init_data_map(t_data *data, t_map *map);
void	init_data(t_data *data);

/* Input. */

void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
int		handle_input(int keycode, t_data *data);

/* Main */

void	check_arguments(int ac, char **av);
void	find_player_position(t_data *data);
void	verify_paths(t_data *data);
void	init_window_and_run(t_data *data);

/* Map allocation. */

int		open_and_allocate_map(t_data *data);
int		allocate_and_copy_line(t_data *data, char *line, t_map *grid);
void	till_filling(t_data *data, int fd);
int		map_size(t_data *data);

/* Map checker */

int		validate_walls(char *line, size_t width);
size_t	get_line_length(char *line);
int		check_line_validity(char *line, size_t line_length, t_map *map);
int		validate_last_line(char *line, size_t line_length);

/* Map parsing */

int		is_valid(t_map *map);
int		map_parsing_lines(t_map *map);
int		map_parsing_symbols(t_map *map);
int		check_extension(char *filename);
int		open_map_file(t_map *map);

/* Move displayed */

void	end_game(t_data *data);
void	congrats_end(t_data *data);
int		check_items(t_data *data);

/* Open and close window */

int		open_window(t_data *data);
int		handle_close(t_data *data);
int		close_win(int keycode, t_data *data);
void	destroy_images(t_data *data);

/* Path checker */

void	check_path(t_data *data, t_point p, int *visited);
void	init_visited_path(int **visited, int width, int height);
int		within_boundaries(t_data *data, t_point p);
void	update_access(t_data *data, t_point p);
void	flood_fill_check(t_data *data, t_point p, int *visited);

/* Symbol checker */

int		check_map_symbols(int fd);
int		check_map_requirements(int p_count, int e_count, int c_count);
int		process_line(char *line, int *p_count, int *e_count, int *c_count);
int		valid_symbol(char c);
void	update_counts(char c, int *p_count, int *e_count, int *c_count);

/* Utils */

int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);

/* **************************************************** */
/*                                                      */
/*                       BONUS !                        */
/*                                                      */
/* **************************************************** */

void	init_enemy(t_data *data);
void	hit_by_enemy(t_data *data);

#endif