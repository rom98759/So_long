/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:59:41 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/09 17:00:01 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE
		&& keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, 0, -1);
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, 0, 1);
	if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		reverse_player(game, 1);
		move_player(game, -1, 0);
	}
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		reverse_player(game, 0);
		move_player(game, 1, 0);
	}
}

void	loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	animate_coins(game);
	animate_enemies(game);
}

void	animate_coins(t_game *game)
{
	int		prev_frame;

	game->coin_anim.frame_timer++;
	if (game->coin_anim.frame_timer >= game->coin_anim.frame_delay)
	{
		prev_frame = game->coin_anim.current_frame;
		game->coin_anim.current_frame = (game->coin_anim.current_frame + 1)
			% game->coin_anim.frame_count;
		game->coin_anim.last_frame = prev_frame;
		game->coin_anim.frame_timer = 0;
	}
	render_coins(game);
}

void	animate_enemies(t_game *game)
{
	game->enemy_anim.frame_timer++;
	if (game->enemy_anim.frame_timer >= game->enemy_anim.frame_delay)
	{
		move_enemies_towards_player(game);
		game->enemy_anim.frame_timer = 0;
	}
}
