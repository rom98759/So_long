/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:30:07 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/25 15:34:05 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_load_img(t_img *img)
{
	if (!img->wall || !img->coins || !img->floor || !img->exit || !img->player)
		return (1);
	return (0);
}

int	check_load_tx(t_tx *tx)
{
	if (!tx->wall || !tx->coins || !tx->floor || !tx->exit || !tx->player)
		return (1);
	return (0);
}

void	init_texture(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		ft_exit_error(game, ERR_MALLOC);
	ft_bzero(game->img, sizeof(t_img));
	game->tx = malloc(sizeof(t_tx));
	if (!game->tx)
	{
		free(game->img);
		ft_exit_error(game, ERR_MALLOC);
	}
	ft_bzero(game->tx, sizeof(t_tx));
}
