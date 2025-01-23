/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:04:44 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/09 16:09:25 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_data(t_map *map)
{
	if (!map)
		return ;
	free_map(map->map);
	free(map);
}

void	free_tx(t_tx *tx, t_game *game)
{
	free_coins_textures(tx);
	free_digit_textures(tx);
	if (tx->wall)
		mlx_delete_texture(tx->wall);
	if (tx->floor)
		mlx_delete_texture(tx->floor);
	if (tx->exit)
		mlx_delete_texture(tx->exit);
	if (tx->player)
		mlx_delete_texture(tx->player);
	if (tx->enemies)
		mlx_delete_texture(tx->enemies);
	free(game->tx);
}

void	free_img(t_img *img, t_game *game)
{
	free_img_coins(game);
	free_img_digits(game);
	if (img->wall)
		mlx_delete_image(game->mlx, img->wall);
	if (img->floor)
		mlx_delete_image(game->mlx, img->floor);
	if (img->exit)
		mlx_delete_image(game->mlx, img->exit);
	if (img->player)
		mlx_delete_image(game->mlx, img->player);
	free(img);
}

void	ft_exit(t_game *game)
{
	ft_putendl_fd("\nExiting...", 1);
	if (game->map)
		free_map_data(game->map);
	if (game->player)
		free(game->player);
	if (game->exit)
		free(game->exit);
	if (game->img)
		free_img(game->img, game);
	if (game->tx)
		free_tx(game->tx, game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(0);
}
