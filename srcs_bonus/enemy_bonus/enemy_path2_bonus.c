/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_path2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:05:59 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/09 17:48:49 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	initialize_options(t_point *options, int x, int y)
{
	options[0] = create_point(x, y - 1, '0');
	options[1] = create_point(x, y + 1, '0');
	options[2] = create_point(x - 1, y, '0');
	options[3] = create_point(x + 1, y, '0');
}

static t_point	get_best_move(t_point *options, int **costs,
	t_point best_move, int *min_cost)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (options[i].x >= 0 && options[i].y >= 0
			&& options[i].x < costs[0][0] && options[i].y < costs[0][1])
		{
			if (costs[options[i].y][options[i].x] < *min_cost)
			{
				*min_cost = costs[options[i].y][options[i].x];
				best_move = options[i];
			}
			else if (costs[options[i].y][options[i].x] == *min_cost)
			{
				best_move = options[rand() % 4];
			}
		}
	}
	return (best_move);
}

t_point	find_next_move(t_game *game, int x, int y)
{
	int		**costs;
	t_point	options[4];
	t_point	best_move;
	int		min_cost;

	costs = initialize_cost_map(game);
	if (!costs)
		return (create_point(x, y, '0'));
	flood_fill_costs(game, costs,
		(t_point){game->player->x, game->player->y, '0'}, 0);
	initialize_options(options, x, y);
	min_cost = INT_MAX;
	best_move = get_best_move(options, costs,
			create_point(x, y, '0'), &min_cost);
	free_cost_map(costs, game->map->height);
	return (best_move);
}
