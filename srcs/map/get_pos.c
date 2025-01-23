/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:11:35 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/22 13:20:41 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	find_player(char **map)
{
	t_point	pos;

	pos = get_pos(map, 'P');
	return (pos);
}

t_point	get_pos(char **map, char c)
{
	t_point	pos;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				pos.x = x;
				pos.y = y;
				pos.c = c;
				return (pos);
			}
			x++;
		}
		y++;
	}
	pos.x = -1;
	pos.y = -1;
	pos.c = 0;
	return (pos);
}

t_point	create_point(int x, int y, char c)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.c = c;
	return (point);
}
