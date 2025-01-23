/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:00:36 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/09 17:01:39 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = -1;
		while (game->map->map[y][++x] != '\0')
		{
			if (game->map->map[y][x] == 'X')
			{
				if (!display_window(game->img->enemies, game, x, y))
					ft_exit_error(game, ERR_DISPLAY);
			}
		}
		y++;
	}
}

static void	replace_enemy(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'S')
				map[y][x] = 'X';
			x++;
		}
		y++;
	}
}

static void	update_enemy_instance(t_game *game, int old_x
	, int old_y, t_point new_pos)
{
	int	index;

	index = get_index(game->img->enemies, old_x, old_y);
	if (index != -1)
	{
		game->img->enemies->instances[index].x = new_pos.x * IMG_LEN;
		game->img->enemies->instances[index].y = new_pos.y * IMG_LEN;
	}
	if (new_pos.x == game->player->x && new_pos.y == game->player->y)
	{
		ft_putstr_fd("\nMOUHAHAHAH you died", 1);
		ft_exit(game);
	}
}

static void	move_enemy(t_game *game, int x, int y)
{
	t_point	next_move;

	next_move = find_next_move(game, x, y);
	if (dda(game, next_move,
			create_point(game->player->x, game->player->y, '0')))
		game->enemy_anim.frame_delay = FRAME_DELAY / 1.8F;
	else
		game->enemy_anim.frame_delay = FRAME_DELAY;
	if (game->coins <= 1)
		game->enemy_anim.frame_delay = FRAME_DELAY / 1.5F;
	if (game->map->map[next_move.y][next_move.x] == '0'
		|| game->map->map[next_move.y][next_move.x] == 'P')
	{
		game->map->map[y][x] = '0';
		game->map->map[next_move.y][next_move.x] = 'S';
		update_enemy_instance(game, x, y,
			create_point(next_move.x, next_move.y, '0'));
	}
}

void	move_enemies_towards_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == 'X')
				move_enemy(game, x, y);
			x++;
		}
		y++;
	}
	replace_enemy(game->map->map);
}
