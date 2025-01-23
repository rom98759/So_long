/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:32:12 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/26 11:41:28 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_index(mlx_image_t *image, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		if (image->instances[i].x == x * IMG_LEN
			&& image->instances[i].y == y * IMG_LEN)
			break ;
		else
			i++;
	}
	return (i);
}
