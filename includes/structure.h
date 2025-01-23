/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:42:03 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/26 11:45:41 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <MLX42/MLX42.h>

typedef struct s_point
{
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
	char		c;				// c : Char
}				t_point;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct s_tx
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*coins;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}					t_tx;

typedef struct s_img
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*coins;
	mlx_image_t		*exit;
	mlx_image_t		*player;
}					t_img;

typedef struct s_game
{
	t_map		*map;			// La carte
	t_point		*player;		// Le joueur
	t_point		*exit;			// L'exit
	t_img		*img;
	t_tx		*tx;
	int			coins;	// Les coins
	int			moves;			// Compteur de mouvements
	void		*mlx;			// Contexte MLX
	long		win_len;		// Taille de la fenêtre
	long		win_height;
	int			is_facing_left; // 0 : facing right, 1 : facing left
}				t_game;

#endif