/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:22:13 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/07 12:58:35 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	fill(char **map, t_point size, t_point pos, char c)
{
	int	pieces;

	pieces = 0;
	if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y)
		return (0);
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == c
		|| map[pos.y][pos.x] == 'X')
		return (0);
	if (map[pos.y][pos.x] == 'C')
		pieces++;
	map[pos.y][pos.x] = c;
	pieces += fill(map, size, create_point(pos.x + 1, pos.y, c), c);
	pieces += fill(map, size, create_point(pos.x - 1, pos.y, c), c);
	pieces += fill(map, size, create_point(pos.x, pos.y + 1, c), c);
	pieces += fill(map, size, create_point(pos.x, pos.y - 1, c), c);
	return (pieces);
}

int	flood_fill(char **map, int len_x, int len_y)
{
	t_point	size;
	t_point	player;
	int		collected_pieces;

	player = find_player(map);
	size = create_point(len_x, len_y, 0);
	collected_pieces = fill(map, size, player, '2');
	return (collected_pieces);
}

int	is_finish(char **map)
{
	char	**dup_map;
	int		collected_pieces;
	int		exit_accessible;
	int		total_pieces;

	dup_map = ft_map_dup(map);
	if (!dup_map || !*dup_map)
	{
		free_map(dup_map);
		return (0);
	}
	total_pieces = count_pieces(map);
	collected_pieces = flood_fill(dup_map, ft_strlen(dup_map[0]),
			ft_tablen(dup_map));
	exit_accessible = check_exit_accessibility(map);
	free_map(dup_map);
	if (collected_pieces != total_pieces || !exit_accessible)
		return (0);
	return (1);
}
