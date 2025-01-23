/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:33:27 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/26 11:33:36 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_exit(char **map, t_point size, t_point pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y)
		return (0);
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == '2')
		return (0);
	if (map[pos.y][pos.x] == 'E')
		return (1);
	map[pos.y][pos.x] = '2';
	if (fill_exit(map, size, create_point(pos.x + 1, pos.y, 0))
		|| fill_exit(map, size, create_point(pos.x - 1, pos.y, 0))
		|| fill_exit(map, size, create_point(pos.x, pos.y + 1, 0))
		|| fill_exit(map, size, create_point(pos.x, pos.y - 1, 0)))
		return (1);
	return (0);
}

int	flood_fill_exit(char **map, int len_x, int len_y)
{
	t_point	size;
	t_point	player;

	player = find_player(map);
	size = create_point(len_x, len_y, 0);
	return (fill_exit(map, size, player));
}

int	check_exit_accessibility(char **map)
{
	char	**dup_map;
	int		exit_found;

	dup_map = ft_map_dup(map);
	if (!dup_map || !*dup_map)
	{
		free_map(dup_map);
		return (0);
	}
	exit_found = flood_fill_exit(dup_map, ft_strlen(dup_map[0]),
			ft_tablen(dup_map));
	free_map(dup_map);
	return (exit_found);
}
