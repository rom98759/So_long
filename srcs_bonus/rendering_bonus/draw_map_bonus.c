/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:19:07 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/04 15:05:29 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_index(mlx_image_t *img, int x, int y)
{
	int	i;

	if (!img || !img->instances)
	{
		return (-1);
	}
	i = 0;
	while ((size_t)i < img->count)
	{
		if (img->instances[i].x == x * IMG_LEN
			&& img->instances[i].y == y * IMG_LEN)
			return (i);
		i++;
	}
	return (-1);
}

int	get_index_coins(mlx_image_t **coins, int current_frame, int x, int y)
{
	int	i;

	if (!coins || !coins[current_frame] || !coins[current_frame]->instances)
	{
		return (-1);
	}
	i = 0;
	while ((size_t)i < coins[current_frame]->count)
	{
		if (coins[current_frame]->instances[i].x == x * IMG_LEN
			&& coins[current_frame]->instances[i].y == y * IMG_LEN)
			return (i);
		i++;
	}
	return (-1);
}
