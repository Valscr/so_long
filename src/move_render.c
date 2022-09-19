/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:22:05 by vescaffr          #+#    #+#             */
/*   Updated: 2022/08/21 21:40:16 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mykey_hook(int keycode, t_data *game)
{	
	if (keycode == XK_Escape)
		end(game);
	if (keycode == XK_w)
		render_top(game);
	if (keycode == XK_d)
		render_right(game);
	if (keycode == XK_a)
		render_left(game);
	if (keycode == XK_s)
		render_down(game);
	return (0);
}

void	render_top(t_data *game)
{
	if (game->total_collect == game->count_collect
		&& game->map[(game->y) - 1][game->x] == game->content.exit)
		game->win += 1;
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "./images/ptop.xpm", &game->width, &game->height);
	if (game->map[(game->y) - 1][game->x] != game->content.wall
		&& game->map[(game->y) - 1][game->x] != game->content.exit)
	{
		ft_printf("%d\n", ++game->count);
		print_img(game, game->img_floor, game->x, game->y);
		game->y -= 1;
		render_next_frame(game);
	}
	check_win(game);
}

void	render_right(t_data *game)
{
	if (game->total_collect == game->count_collect
		&& game->map[game->y][(game->x) + 1] == game->content.exit)
		game->win += 1;
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "./images/pright.xpm",
			&game->width, &game->height);
	if (game->map[game->y][(game->x) + 1] != game->content.wall
		&& game->map[game->y][(game->x) + 1] != game->content.exit)
	{
		ft_printf("%d\n", ++game->count);
		print_img(game, game->img_floor, game->x, game->y);
		game->x += 1;
		render_next_frame(game);
	}
	check_win(game);
}

void	render_left(t_data *game)
{
	if (game->total_collect == game->count_collect
		&& game->map[game->y][(game->x) - 1] == game->content.exit)
			game->win += 1;
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "./images/pleft.xpm", &game->width, &game->height);
	if (game->map[game->y][(game->x) - 1] != game->content.wall
		&& game->map[game->y][(game->x) - 1] != game->content.exit)
	{	
		ft_printf("%d\n", ++game->count);
		print_img(game, game->img_floor, game->x, game->y);
		game->x -= 1;
		render_next_frame(game);
	}
	check_win(game);
}

void	render_down(t_data *game)
{
	if (game->total_collect == game->count_collect
		&& game->map[(game->y) + 1][game->x] == game->content.exit)
		game->win += 1;
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "./images/pdown.xpm", &game->width, &game->height);
	if (game->map[(game->y) + 1][game->x] != game->content.wall
		&& game->map[(game->y) + 1][game->x] != game->content.exit)
	{
		ft_printf("%d\n", ++game->count);
		print_img(game, game->img_floor, game->x, game->y);
		game->y += 1;
		render_next_frame(game);
	}
	check_win(game);
}
