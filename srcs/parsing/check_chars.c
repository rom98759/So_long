/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:55:33 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/22 20:55:33 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_tile(char c)
{
	return (c == '0' || c == '1' \
		|| c == 'P' || c == 'E' || c == 'C');
}

static int	update_counts(char c, int *player, int *has_exit, int *collect)
{
	if (c == 'P')
	{
		if (*player)
			return (0);
		*player = 1;
	}
	else if (c == 'E')
	{
		if (*has_exit)
			return (0);
		*has_exit = 1;
	}
	else if (c == 'C')
		*collect = 1;
	else if (!is_valid_tile(c))
		return (0);
	return (1);
}

int	check_valid_char(char **map)
{
	int	y;
	int	x;
	int	player;
	int	exit;
	int	collect;

	player = 0;
	exit = 0;
	collect = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (!update_counts(map[y][x], &player, &exit, &collect))
				return (0);
			x++;
		}
		y++;
	}
	return (player && exit && collect);
}
