/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:22:49 by valentin          #+#    #+#             */
/*   Updated: 2022/08/21 18:03:13 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_img(t_data *game, void *imgg, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->mlx_win, imgg, game->width * x, game->height * y);
	return (0);
}
