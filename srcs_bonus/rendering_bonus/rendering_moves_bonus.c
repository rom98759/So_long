/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_moves_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:36:51 by rcaillie          #+#    #+#             */
/*   Updated: 2024/12/09 14:36:38 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_img_digits(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < 10)
	{
		game->img->digits[i] = mlx_texture_to_image(game->mlx,
				game->tx->digits[i]);
		if (!game->img->digits[i])
			ft_exit_error(game, ERR_IMG_LOAD);
		if (!game->img->digits[i]->instances)
		{
			game->img->digits[i]->instances = malloc(sizeof(mlx_instance_t)
					* NB_FRAME);
			if (!game->img->digits[i]->instances)
				ft_exit_error(game, ERR_MALLOC);
			j = 0;
			while (j < NB_FRAME)
			{
				game->img->digits[i]->instances[j].enabled = 0;
				j++;
			}
		}
		i++;
	}
}

static void	delete_all_digits_digits(t_game *game)
{
	free_img_digits(game);
	load_img_digits(game);
}

void	render_move_counter(t_game *game)
{
	char		*moves_str;
	int			len;
	int			i;
	int			x_pos;
	int			digit;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		ft_exit_error(game, ERR_MOVES);
	len = ft_strlen(moves_str);
	x_pos = 0;
	i = 0;
	delete_all_digits_digits(game);
	while (i < len)
	{
		digit = moves_str[i] - '0';
		if (digit >= 0 && digit <= 9)
		{
			mlx_image_to_window(game->mlx, game->img->digits[digit], x_pos, 0);
			x_pos += IMG_LEN;
		}
		i++;
	}
	free(moves_str);
}
