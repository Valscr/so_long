/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:02:43 by valentin          #+#    #+#             */
/*   Updated: 2022/09/19 13:43:08 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_rect(t_data *game)
{
	int	i;
	int	j;

	i = game->win_height;
	while (i < game->win_width)
	{
		j = (game->width * 2);
		while (j < (game->width * 3))
			mlx_pixel_put(game->mlx, game->mlx_win, j++, i, 0x00000000);
		++i;
	}
	return (0);
}

int	not_find(void)
{
	static int	i;

	i++;
	if (i > 50000)
	{
		i = 0;
		return (1);
	}
	else
		return (0);
}
