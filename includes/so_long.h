/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:59:12 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/21 13:43:56 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> // open, close
# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free

# include "libft.h"
# include "get_next_line.h"
# include "pr_printf.h"
# include "structure.h"
# include "errors_msg.h"
# include <MLX42/MLX42.h>

# define IMG_LEN 32

// So_long
void	init_game(t_game *game);
void	init_malloc(t_game *game);

// Errors
void	ft_error(char *str);
void	ft_error_free(char **map);
void	free_tx(t_tx *tx, t_game *game);
void	free_img(t_img *img, t_game *game);
void	ft_exit_error(t_game *game, char *str);

// Frees
void	free_map(char **map);
void	free_map_data(t_map *map);
void	ft_error_free_map_data(t_map *map_data, char *str);
void	ft_exit(t_game *game);

// Maps utils
int		ft_tablen(char **tab);
char	**ft_map_dup(char **map);
int		count_pieces(char **map);
char	**open_map(char *path);

// Map utils 2
int		get_map_width(char **map);
int		get_map_height(char **map);

// Utils
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

// Parsing
t_map	*ft_parsing(char *path);
int		is_valid_map(char **map);
int		is_finish(char **map);

// Flood fill
int		fill(char **map, t_point size, t_point pos, char c);
int		flood_fill(char **map, int len_x, int len_y);
int		is_finish(char **map);
int		fill_exit(char **map, t_point size, t_point pos);
int		flood_fill_exit(char **map, int len_x, int len_y);
int		check_exit_accessibility(char **map);

// Check
int		check_wall(char **map);
int		check_valid_char(char **map);
int		check_too_large(char **map);

// Get pos
t_point	find_player(char **map);
t_point	get_pos(char **map, char c);
t_point	create_point(int x, int y, char c);

// Rendering
int		display_window(mlx_image_t *img, t_game *game, int x, int y);
int		load_tx(t_game *game);
int		load_img(t_game *game);
void	char_display(t_game *game, t_point p);
void	render_map(t_game *game);

// Player reverse
void	reverse_image_horizontal(mlx_texture_t *texture);
void	reverse_player(t_game *game, int facing_left);

// Hooks
void	keyhook(mlx_key_data_t keydata, void *param);

// Check load images
int		check_load_img(t_img *img);
int		check_load_tx(t_tx *tx);
void	init_texture(t_game *game);

// Draw map
int		get_index(mlx_image_t *image, int x, int y);

// Player movements
void	move_player(t_game *game, int x, int y);
void	print_moves(t_game *game);
void	update_player_position(t_game *game, int new_x, int new_y);
void	handle_coins(t_game *game, int x, int y);
void	handle_exit(t_game *game, int new_x, int new_y);

#endif
