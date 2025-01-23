/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:59:55 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/28 16:19:53 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_line(char *line)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_borders(char **map, int tablen)
{
	int	i;
	int	row_len;

	i = 1;
	while (i < tablen - 1)
	{
		row_len = ft_strlen(map[i]) - 1;
		if (row_len == 0 || map[i][0] != '1' || map[i][row_len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_size(char **map)
{
	size_t	first_len;
	size_t	current_len;
	int		i;

	i = 0;
	first_len = ft_strlen(map[0]);
	if (map[0][first_len - 1] == '\n')
		first_len--;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (map[i][current_len - 1] == '\n')
			current_len--;
		if (current_len != first_len)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **map)
{
	int	tablen;

	tablen = ft_tablen(map);
	if (!map || tablen == 0)
		return (0);
	if (!check_line(map[0]))
		return (0);
	if (!check_line(map[tablen - 1]))
		return (0);
	if (!check_borders(map, tablen))
		return (0);
	if (!check_size(map))
		return (0);
	return (1);
}
