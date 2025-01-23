/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:46:04 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/28 17:20:21 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x + x;
	new_y = game->player->y + y;
	if (game->map->map[new_y][new_x] == '1')
		return ;
	else if (game->map->map[new_y][new_x] == 'C')
		handle_coins(game, new_x, new_y);
	else if (game->map->map[new_y][new_x] == 'E')
	{
		handle_exit(game, new_x, new_y);
		return ;
	}
	update_player_position(game, new_x, new_y);
}

void	print_moves(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (game->map->map[game->player->y][game->player->x] != 'E')
		game->map->map[game->player->y][game->player->x] = '0';
	game->player->x = new_x;
	game->player->y = new_y;
	game->img->player->instances[0].x = new_x * IMG_LEN;
	game->img->player->instances[0].y = new_y * IMG_LEN;
	game->moves++;
	print_moves(game);
}

void	handle_coins(t_game *game, int x, int y)
{
	int	index;

	game->map->map[y][x] = '0';
	index = get_index(game->img->coins, x, y);
	if (index != -1)
		game->img->coins->instances[index].enabled = false;
	game->coins--;
}

void	handle_exit(t_game *game, int new_x, int new_y)
{
	if (game->coins == 0)
	{
		game->moves++;
		print_moves(game);
		mlx_close_window(game->mlx);
	}
	else
	{
		update_player_position(game, new_x, new_y);
		game->img->exit->instances[0].x = new_x * IMG_LEN;
		game->img->exit->instances[0].y = new_y * IMG_LEN;
	}
}
