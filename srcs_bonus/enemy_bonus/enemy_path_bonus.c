/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:04:14 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:49 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill_costs(t_game *game, int **costs, t_point p, int cost)
{
	if (p.x < 0 || p.y < 0 || p.x >= game->map->width
		|| p.y >= game->map->height)
		return ;
	if (game->map->map[p.y][p.x] == '1' || game->map->map[p.y][p.x] == 'E'
		|| game->map->map[p.y][p.x] == 'C')
		return ;
	if (costs[p.y][p.x] <= cost)
		return ;
	costs[p.y][p.x] = cost;
	flood_fill_costs(game, costs, (t_point){p.x + 1, p.y, '0'}, cost + 1);
	flood_fill_costs(game, costs, (t_point){p.x - 1, p.y, '0'}, cost + 1);
	flood_fill_costs(game, costs, (t_point){p.x, p.y + 1, '0'}, cost + 1);
	flood_fill_costs(game, costs, (t_point){p.x, p.y - 1, '0'}, cost + 1);
}

int	**initialize_cost_map(t_game *game)
{
	int	**costs;
	int	i;

	costs = malloc(sizeof(int *) * game->map->height);
	if (!costs)
		return (NULL);
	i = 0;
	while (i < game->map->height)
	{
		costs[i] = malloc(sizeof(int) * game->map->width);
		if (!costs[i])
		{
			while (--i >= 0)
				free(costs[i]);
			free(costs);
			return (NULL);
		}
		ft_memset(costs[i], 127, sizeof(int) * game->map->width);
		i++;
	}
	return (costs);
}

void	free_cost_map(int **costs, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(costs[i++]);
	free(costs);
}
