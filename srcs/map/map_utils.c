/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:18:47 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/26 13:12:18 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_dup(char **map)
{
	char	**new_map;
	int		len_y;
	int		y;

	len_y = ft_tablen(map);
	new_map = malloc((len_y + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	y = 0;
	while (y < len_y)
	{
		new_map[y] = ft_strdup(map[y]);
		if (!new_map[y])
		{
			while (y-- > 0)
				free(new_map[y]);
			free(new_map);
			return (NULL);
		}
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

int	count_pieces(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_OPEN);
	return (fd);
}

static void	append_line_to_map(char ***map, size_t *map_size, char *line)
{
	*map = ft_realloc(*map, sizeof(char *) * (*map_size + 1),
			sizeof(char *) * (*map_size + 2));
	if (!*map)
	{
		free(line);
		ft_error(ERR_MALLOC);
	}
	(*map)[*map_size] = line;
	(*map_size)++;
	(*map)[*map_size] = NULL;
}

char	**open_map(char *path)
{
	int		fd;
	char	*line;
	char	**map;
	size_t	map_size;

	fd = open_file(path);
	map = malloc(sizeof(char *));
	if (!map)
	{
		close(fd);
		ft_error(ERR_MALLOC);
	}
	map[0] = NULL;
	map_size = 0;
	line = get_next_line(fd);
	while (line)
	{
		append_line_to_map(&map, &map_size, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
