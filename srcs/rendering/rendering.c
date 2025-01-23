/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:10:51 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/25 17:00:49 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_window(mlx_image_t *img, t_game *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx, img, x * IMG_LEN, y * IMG_LEN) < 0)
		return (0);
	return (1);
}

int	load_tx(t_game *game)
{
	game->tx->wall = mlx_load_png("./textures/wall.png");
	game->tx->floor = mlx_load_png("./textures/floor.png");
	game->tx->coins = mlx_load_png("./textures/coins.png");
	game->tx->exit = mlx_load_png("./textures/exit.png");
	game->tx->player = mlx_load_png("./textures/player.png");
	if (check_load_tx(game->tx))
		ft_exit_error(game, ERR_TX_LOAD);
	return (1);
}

int	load_img(t_game *game)
{
	game->img->wall = mlx_texture_to_image(game->mlx, game->tx->wall);
	game->img->floor = mlx_texture_to_image(game->mlx, game->tx->floor);
	game->img->coins = mlx_texture_to_image(game->mlx, game->tx->coins);
	game->img->exit = mlx_texture_to_image(game->mlx, game->tx->exit);
	game->img->player = mlx_texture_to_image(game->mlx, game->tx->player);
	if (check_load_img(game->img))
		ft_exit_error(game, ERR_IMG_LOAD);
	return (1);
}

void	char_display(t_game *game, t_point p)
{
	if (p.c == '1')
	{
		if (!display_window(game->img->wall, game, p.x, p.y))
			ft_exit_error(game, ERR_DISPLAY);
	}
	else if (p.c == '0' || p.c == 'C' || p.c == 'P' || p.c == 'E')
	{
		if (!display_window(game->img->floor, game, p.x, p.y))
			ft_exit_error(game, ERR_DISPLAY);
	}
	if (p.c == 'E')
	{
		if (!display_window(game->img->exit, game, p.x, p.y))
			ft_exit_error(game, ERR_DISPLAY);
	}
	if (p.c == 'C')
	{
		if (!display_window(game->img->coins, game, p.x, p.y))
			ft_exit_error(game, ERR_DISPLAY);
	}
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	t_point	tmp;

	init_texture(game);
	load_tx(game);
	load_img(game);
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = -1;
		while (game->map->map[y][++x] != '\0')
			char_display(game, create_point(x, y, game->map->map[y][x]));
		y++;
	}
	tmp = get_pos(game->map->map, 'E');
	if (!display_window(game->img->exit, game, tmp.x, tmp.y))
		ft_exit_error(game, ERR_DISPLAY);
	tmp = find_player(game->map->map);
	if (!display_window(game->img->player, game, tmp.x, tmp.y))
		ft_exit_error(game, ERR_DISPLAY);
}
