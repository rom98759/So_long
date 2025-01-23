/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_too_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:12:54 by rcaillie          #+#    #+#             */
/*   Updated: 2025/01/23 19:21:23 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_too_large(char **map)
{
	int	width;
	int	height;

	width = get_map_width(map);
	height = get_map_height(map);
	ft_printf("width: %d, height: %d\n", width, height);
	if (width > 150 || height > 150)
	{
		ft_error("Map trop grande, max 150x150");
		return (1);
	}
	return (0);
}
