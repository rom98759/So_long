/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:08:34 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/28 17:15:06 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_error_free(char **map)
{
	if (map)
		free_map(map);
	ft_error(ERR_MAP);
}

void	ft_error_free_map_data(t_map *map_data, char *str)
{
	if (map_data)
		free_map_data(map_data);
	ft_error(str);
}

void	ft_exit_error(t_game *game, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	ft_exit(game);
}
