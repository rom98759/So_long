/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:28:17 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/04 11:05:50 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_digit_textures(t_tx *tx)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (tx->digits[i])
		{
			mlx_delete_texture(tx->digits[i]);
			tx->digits[i] = NULL;
		}
		i++;
	}
}

void	free_coins_textures(t_tx *tx)
{
	int	i;

	i = 0;
	while (i < NB_FRAME)
	{
		if (tx->coins[i])
		{
			mlx_delete_texture(tx->coins[i]);
			tx->coins[i] = NULL;
		}
		i++;
	}
}

void	free_img_digits(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->img->digits[i])
			mlx_delete_image(game->mlx, game->img->digits[i]);
		i++;
	}
}

void	free_img_coins(t_game *game)
{
	int	i;

	i = 0;
	while (i < NB_FRAME)
	{
		if (game->img->coins[i])
			mlx_delete_image(game->mlx, game->img->coins[i]);
		i++;
	}
}
