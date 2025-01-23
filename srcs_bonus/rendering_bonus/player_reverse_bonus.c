/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_reverse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:19:00 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/28 16:19:03 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	swap_pixels(uint8_t *a, uint8_t *b)
{
	uint8_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	reverse_row(uint8_t *pixels, uint32_t width, uint32_t y)
{
	uint32_t	x;
	uint32_t	opposite_x;
	uint32_t	channel;

	x = 0;
	while (x < width / 2)
	{
		opposite_x = width - x - 1;
		channel = 0;
		while (channel < 4)
		{
			swap_pixels(
				&pixels[(y * width + x) * 4 + channel],
				&pixels[(y * width + opposite_x) * 4 + channel]
				);
			channel++;
		}
		x++;
	}
}

void	reverse_image_horizontal(mlx_texture_t *texture)
{
	uint32_t	y;

	if (!texture || !texture->pixels)
		return ;
	y = 0;
	while (y < texture->height)
	{
		reverse_row(texture->pixels, texture->width, y);
		y++;
	}
}

void	reverse_player(t_game *game, int facing_left)
{
	if (game->is_facing_left == facing_left)
		return ;
	game->is_facing_left = facing_left;
	reverse_image_horizontal(game->tx->player);
	mlx_delete_image(game->mlx, game->img->player);
	game->img->player = mlx_texture_to_image(game->mlx, game->tx->player);
	mlx_image_to_window(game->mlx, game->img->player,
		game->player->x * IMG_LEN, game->player->y * IMG_LEN);
}
