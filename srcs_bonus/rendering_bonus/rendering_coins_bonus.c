/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_coins_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:44:57 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/28 16:16:59 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	disable_all_coin_instances(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < NB_FRAME)
	{
		j = 0;
		if (!game->img->coins[i])
			ft_exit_error(game, "Coin images not initialized properly.");
		if (!game->img->coins[i]->instances)
			ft_exit_error(game, "Coin instances not initialized properly.");
		while (j < game->img->coins[i]->count)
		{
			game->img->coins[i]->instances[j].enabled = false;
			j++;
		}
		i++;
	}
}

void	enable_visible_coins(t_game *game)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == 'C')
			{
				index = get_index_coins(game->img->coins,
						game->coin_anim.current_frame, x, y);
				if (index != -1)
					game->img->coins[game->coin_anim.current_frame]
						->instances[index].enabled = true;
			}
			x++;
		}
		y++;
	}
}

void	load_img_coins(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < NB_FRAME)
	{
		game->img->coins[i] = mlx_texture_to_image(game->mlx,
				game->tx->coins[i]);
		if (!game->img->coins[i]->instances)
		{
			game->img->coins[i]->instances = malloc(sizeof(mlx_instance_t)
					* NB_FRAME);
			if (!game->img->coins[i]->instances)
				ft_exit_error(game, ERR_MALLOC);
			j = 0;
			while (j < NB_FRAME)
			{
				game->img->coins[i]->instances[j].enabled = 0;
				j++;
			}
		}
		i++;
	}
}

void	display_coins(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NB_FRAME)
	{
		if (!display_window(game->img->coins[i], game, x, y))
			ft_exit_error(game, ERR_DISPLAY);
		i++;
	}
}

void	render_coins(t_game *game)
{
	disable_all_coin_instances(game);
	enable_visible_coins(game);
}
