/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:42:03 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/10 10:22:18 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_BONUS_H
# define STRUCTURE_BONUS_H

/* -------------------------------- INCLUDES -------------------------------- */

# include <MLX42/MLX42.h>

/* ---------------------------- STRUCTURE DEFINITIONS ----------------------- */

/* Coordinate structure */
typedef struct s_point
{
	int		x;			// Width (x-axis)
	int		y;			// Height (y-axis)
	char	c;			// Character representation
}			t_point;

/* Map structure */
typedef struct s_map
{
	char	**map;		// 2D array representing the map
	int		width;		// Width of the map
	int		height;		// Height of the map
}			t_map;

/* Texture structure */
typedef struct s_tx
{
	mlx_texture_t	*wall;			// Wall texture
	mlx_texture_t	*floor;			// Floor texture
	mlx_texture_t	*coins[5];		// Coin textures (animated)
	mlx_texture_t	*exit;			// Exit texture
	mlx_texture_t	*player;		// Player texture
	mlx_texture_t	*digits[10];	// Digit textures (for move counter)
	mlx_texture_t	*enemies;		// Enemy texture
}					t_tx;

/* Image structure */
typedef struct s_img
{
	mlx_image_t		*wall;			// Wall image
	mlx_image_t		*floor;			// Floor image
	mlx_image_t		*coins[5];		// Coin images (animated)
	mlx_image_t		*exit;			// Exit image
	mlx_image_t		*player;		// Player image
	mlx_image_t		*digits[10];	// Digit images (for move counter)
	mlx_image_t		*enemies;		// Enemy image
}					t_img;

/* Animation structure */
typedef struct s_animation
{
	int		current_frame;		// Current frame of the animation
	int		last_frame;			// Last frame index
	int		frame_count;		// Total number of frames
	int		frame_delay;		// Delay between frames
	int		frame_timer;		// Timer for controlling frame changes
}			t_animation;

/* DDA structure */
typedef struct s_dda
{
	float	dx;					// Distance between two x-axis points
	float	dy;					// Distance between two y-axis points
	long	side_dist_x;		// Distance to the next x-axis side
	long	side_dist_y;		// Distance to the next y-axis side
	float	delta_dist_x;		// Delta distance for x-axis
	float	delta_dist_y;		// Delta distance for y-axis
	int		step_x;				// Step direction for x-axis
	int		step_y;				// Step direction for y-axis
}			t_dda;

/* Main game structure */
typedef struct s_game
{
	t_map			*map;			// Map information
	t_point			*player;		// Player's position
	t_point			*exit;			// Exit position
	t_img			*img;			// Loaded images
	t_tx			*tx;			// Loaded textures (.png)
	int				coins;			// Total coins on the map
	int				moves;			// Move counter
	void			*mlx;			// MLX context
	long			win_len;		// Window width
	long			win_height;		// Window height
	int				is_facing_left;	// Player direction (0: right, 1: left)
	t_animation		coin_anim;		// Coin animation structure
	t_animation		enemy_anim;		// Enemy animation structure
}				t_game;

#endif