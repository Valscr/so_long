/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:17:34 by vescaffr          #+#    #+#             */
/*   Updated: 2022/09/19 13:56:28 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_data(t_data *game)
{
	game->win_height = 0;
	game->win_width = 0;
	game->win = 0;
	game->count = 0;
	game->count_collect = 0;
	game->total_collect = 0;
	game->width = 50;
	game->height = 50;
	game->x = 0;
	game->y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->maptest = NULL;
}

void	set_content(t_data *game)
{
	game->content.player = 'P';
	game->content.wall = '1';
	game->content.floor = '0';
	game->content.collect = 'C';
	game->content.exit = 'E';
}

int	window_size(t_data *game)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][i] != '\0')
			i++;
		game->win_width = i * game->width;
		i = 0;
		y++;
	}
	game->win_height = y * game->height;
	if (y > 29 || i > 59)
		return (0);
	return (1);
}

void	set_img_count(t_data *game)
{
	game->content.img0 = mlx_xpm_file_to_image
		(game->mlx, "./images/0.xpm", &game->width, &game->height);
	game->content.img1 = mlx_xpm_file_to_image
		(game->mlx, "./images/1.xpm", &game->width, &game->height);
	game->content.img2 = mlx_xpm_file_to_image
		(game->mlx, "./images/2.xpm", &game->width, &game->height);
	game->content.img3 = mlx_xpm_file_to_image
		(game->mlx, "./images/3.xpm", &game->width, &game->height);
	game->content.img4 = mlx_xpm_file_to_image
		(game->mlx, "./images/4.xpm", &game->width, &game->height);
	game->content.img5 = mlx_xpm_file_to_image
		(game->mlx, "./images/5.xpm", &game->width, &game->height);
	game->content.img6 = mlx_xpm_file_to_image
		(game->mlx, "./images/6.xpm", &game->width, &game->height);
	game->content.img7 = mlx_xpm_file_to_image
		(game->mlx, "./images/7.xpm", &game->width, &game->height);
	game->content.img8 = mlx_xpm_file_to_image
		(game->mlx, "./images/8.xpm", &game->width, &game->height);
	game->content.img9 = mlx_xpm_file_to_image
		(game->mlx, "./images/9.xpm", &game->width, &game->height);
}

void	set_parametre(t_data *game)
{	
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "./images/pright.xpm",
			&game->width, &game->height);
	game->img_wallback = mlx_xpm_file_to_image
		(game->mlx, "./images/wall2.xpm", &game->width, &game->height);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "./images/wallback1.xpm", &game->width, &game->height);
	game->img_floor = mlx_xpm_file_to_image
		(game->mlx, "./images/floor.xpm", &game->width, &game->height);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, "./images/compoundv.xpm", &game->width, &game->height);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "./images/exit.xpm", &game->width, &game->height);
	set_img_count(game);
}
