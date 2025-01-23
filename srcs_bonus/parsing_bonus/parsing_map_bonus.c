/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:19:25 by rcaillie          #+#    #+#             */
/*   Updated: 2025/01/23 19:20:14 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_map(char **map)
{
	if (!map || !*map)
		return (0);
	if (!check_wall(map))
	{
		return (0);
	}
	if (!check_valid_char(map))
	{
		return (0);
	}
	if (check_too_large(map))
	{
		return (0);
	}
	if (!is_finish(map))
	{
		return (0);
	}
	return (1);
}

static int	check_path(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".ber", 4))
		return (0);
	return (1);
}

t_map	*ft_parsing(char *path)
{
	t_map	*map_data;
	char	**map;

	if (!check_path(path))
		ft_error("File invalide, not in .ber");
	map = open_map(path);
	if (!is_valid_map(map))
		ft_error_free(map);
	map_data = malloc(sizeof(t_map));
	if (!map_data)
		ft_error_free(map);
	map_data->map = map;
	map_data->width = get_map_width(map);
	map_data->height = get_map_height(map);
	return (map_data);
}
