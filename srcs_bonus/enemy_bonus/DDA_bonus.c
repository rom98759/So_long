/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:35:07 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/09 17:30:02 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_delta_dist(t_dda *data)
{
	if (data->dx == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0 / data->dx);
	if (data->dy == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0 / data->dy);
}

static void	set_step_and_side_dist(t_dda *data, t_point start)
{
	if (data->dx < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (start.x - floor(start.x)) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (ceil(start.x) - start.x) * data->delta_dist_x;
	}
	if (data->dy < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (start.y - floor(start.y)) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (ceil(start.y) - start.y) * data->delta_dist_y;
	}
}

static t_dda	dda_init(t_point start, t_point end)
{
	t_dda	data;

	data.dx = end.x - start.x;
	data.dy = end.y - start.y;
	set_delta_dist(&data);
	set_step_and_side_dist(&data, start);
	return (data);
}

int	dda(t_game *game, t_point start, t_point end)
{
	t_dda	data;
	char	current_tile;

	data = dda_init(start, end);
	while (start.x >= 0 && start.y >= 0
		&& start.x < game->map->width && start.y < game->map->height)
	{
		if (data.side_dist_x < data.side_dist_y)
		{
			data.side_dist_x += data.delta_dist_x;
			start.x += data.step_x;
		}
		else
		{
			data.side_dist_y += data.delta_dist_y;
			start.y += data.step_y;
		}
		current_tile = game->map->map[start.y][start.x];
		if (current_tile == '1')
			return (0);
		if (current_tile == 'P')
			return (1);
	}
	return (0);
}
