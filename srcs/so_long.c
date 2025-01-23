/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:08:56 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/25 15:08:56 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <MLX42/MLX42.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->map = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->coins = 0;
	game->moves = 0;
	game->img = NULL;
	game->tx = NULL;
	game->win_height = 0;
	game->win_len = 0;
	game->is_facing_left = 0;
}

void	init_malloc(t_game *game)
{
	game->player = malloc(sizeof(t_point));
	if (!game->player)
		ft_error(ERR_MALLOC);
	game->exit = malloc(sizeof(t_point));
	if (!game->exit)
	{
		if (game->player)
			free(game->player);
		ft_error_free_map_data(game->map, ERR_MALLOC);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Usage: ./so_long [map_path]");
	init_game(&game);
	game.map = ft_parsing(av[1]);
	if (!game.map)
		ft_error("Unable to parse the map.");
	game.coins = count_pieces(game.map->map);
	game.win_height = ft_tablen(game.map->map) * IMG_LEN;
	game.win_len = (ft_strlen(game.map->map[0]) - 1) * IMG_LEN;
	game.mlx = mlx_init(game.win_len, game.win_height, "So Long", true);
	if (!game.mlx)
		ft_error("Unable to initialize MLX42.");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_malloc(&game);
	*game.exit = get_pos(game.map->map, 'E');
	*game.player = get_pos(game.map->map, 'P');
	render_map(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	ft_exit(&game);
	return (0);
}
