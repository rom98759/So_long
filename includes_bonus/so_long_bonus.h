/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:47:43 by rcaillie          #+#    #+#             */
/*   Updated: 2025/01/23 19:14:47 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* -------------------------------- INCLUDES -------------------------------- */

# include <fcntl.h>			// open, close
# include <unistd.h>		// read, write
# include <stdlib.h>		// malloc, free
# include <stdio.h>			// snprintf
# include <limits.h>		// INT_MAX
# include <math.h>			// fabs (for dda)

# include "libft.h"
# include "get_next_line.h"
# include "pr_printf.h"
# include "structure_bonus.h"
# include "errors_msg_bonus.h"
# include <MLX42/MLX42.h>

/* -------------------------------- DEFINES --------------------------------- */

# define IMG_LEN		32
# define NB_FRAME		5
# define FRAME_DELAY	20

/* ----------------------------- FUNCTION PROTOTYPES ------------------------ */

/* Initialization */
void	init_game(t_game *game);
void	init_malloc(t_game *game);
void	init_animation(t_game *game);

/* Errors */
void	ft_error(char *str);
void	ft_error_free(char **map);
void	free_tx(t_tx *tx, t_game *game);
void	free_img(t_img *img, t_game *game);
void	ft_exit_error(t_game *game, char *str);

/* Frees */
void	free_map(char **map);
void	free_map_data(t_map *map);
void	ft_error_free_map_data(t_map *map_data, char *str);
void	ft_exit(t_game *game);
void	free_digit_textures(t_tx *tx);
void	free_coins_textures(t_tx *tx);
void	free_img_digits(t_game *game);
void	free_img_coins(t_game *game);

/* Map Utilities */
int		ft_tablen(char **tab);
char	**ft_map_dup(char **map);
int		count_pieces(char **map);
char	**open_map(char *path);
int		get_map_width(char **map);
int		get_map_height(char **map);

/* Utils */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/* Parsing */
t_map	*ft_parsing(char *path);
int		is_valid_map(char **map);
int		is_finish(char **map);

/* Flood Fill */
int		fill(char **map, t_point size, t_point pos, char c);
int		flood_fill(char **map, int len_x, int len_y);
int		fill_exit(char **map, t_point size, t_point pos);
int		flood_fill_exit(char **map, int len_x, int len_y);
int		check_exit_accessibility(char **map);

/* Checks */
int		check_wall(char **map);
int		check_valid_char(char **map);
int		check_too_large(char **map);

/* Position Helpers */
t_point	find_player(char **map);
t_point	get_pos(char **map, char c);
t_point	create_point(int x, int y, char c);

/* Rendering */
int		display_window(mlx_image_t *img, t_game *game, int x, int y);
void	display_coins(t_game *game, int x, int y);
int		load_tx(t_game *game);
int		load_img(t_game *game);
void	char_display(t_game *game, t_point p);
void	render_map(t_game *game);

/* Rendering Coins */
void	load_img_coins(t_game *game);
void	render_coins(t_game *game);
void	disable_all_coin_instances(t_game *game);
void	enable_visible_coins(t_game *game);

/* Rendering Moves */
void	render_move_counter(t_game *game);
void	load_img_digits(t_game *game);

/* Player Orientation */
void	reverse_image_horizontal(mlx_texture_t *texture);
void	reverse_player(t_game *game, int facing_left);

/* Hooks */
void	keyhook(mlx_key_data_t keydata, void *param);
void	loop_hook(void *param);
void	animate_enemies(t_game *game);
void	animate_coins(t_game *game);

/* Image Checks */
int		check_load_img(t_img *img);
int		check_load_tx(t_tx *tx);
void	init_texture(t_game *game);

/* Map Drawing */
int		get_index(mlx_image_t *img, int x, int y);
int		get_index_coins(mlx_image_t **coins, int current_frame, int x, int y);

/* Player Movements */
void	move_player(t_game *game, int x, int y);
void	print_moves(t_game *game);
void	update_player_position(t_game *game, int new_x, int new_y);
void	handle_coins(t_game *game, int x, int y);
void	handle_exit(t_game *game, int new_x, int new_y);

/* Enemy Movements */
void	render_enemy(t_game *game);
void	move_enemies_towards_player(t_game *game);
void	flood_fill_costs(t_game *game, int **costs, t_point p, int cost);
int		**initialize_cost_map(t_game *game);
void	free_cost_map(int **costs, int height);
t_point	find_next_move(t_game *game, int x, int y);
int		dda(t_game *game, t_point start, t_point end);

#endif