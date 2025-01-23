/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_draw_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:19:18 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/05 18:40:06 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_load_img(t_img *img)
{
	int	i;

	if (!img->wall || !img->floor || !img->exit
		|| !img->player || !img->enemies)
		return (1);
	i = 0;
	while (i < NB_FRAME)
	{
		if (!img->coins[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_load_tx(t_tx *tx)
{
	int	i;

	if (!tx->wall || !tx->floor || !tx->exit || !tx->player || !tx->enemies)
		return (1);
	i = 0;
	while (i < NB_FRAME)
	{
		if (!tx->coins[i])
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (!tx->digits[i])
			return (1);
		i++;
	}
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
