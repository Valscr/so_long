/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:14:09 by vescaffr          #+#    #+#             */
/*   Updated: 2022/09/19 13:41:57 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_wallback);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->content.img0);
	mlx_destroy_image(game->mlx, game->content.img1);
	mlx_destroy_image(game->mlx, game->content.img2);
	mlx_destroy_image(game->mlx, game->content.img3);
	mlx_destroy_image(game->mlx, game->content.img4);
	mlx_destroy_image(game->mlx, game->content.img5);
	mlx_destroy_image(game->mlx, game->content.img6);
	mlx_destroy_image(game->mlx, game->content.img7);
	mlx_destroy_image(game->mlx, game->content.img8);
	mlx_destroy_image(game->mlx, game->content.img9);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	exit(0);
	return (0);
}

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

void	check_win(t_data *game)
{
	if (game->win == 1)
	{
		ft_printf("YOU WIN !!! Your score is %d\n", game->count);
		end(game);
	}
}

void	init(t_data *game)
{
	game->mlx = mlx_init();
	set_data(game);
	set_content(game);
	set_parametre(game);
	if (!window_size(game))
	{
		ft_printf("Error\nMap too big!\n");
		game->mlx_win = mlx_new_window(game->mlx,
				game->win_width, game->win_height
				+ game->height, "SO_LONG");
		end(game);
	}
	game->mlx_win = mlx_new_window(game->mlx,
			game->win_width, game->win_height + game->height, "SO_LONG");
	if (!check_player(game))
	{
		ft_printf("Error\nYou need ONE Player on map !\n");
		end(game);
	}
	game->total_collect = counter_collect(game);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		ft_printf("Error\nThis program needs one argument .ber\n");
		return (0);
	}
	if (set_map(argv, &game))
		return (0);
	else
	{
		init(&game);
		if (!check_map_valid(&game))
		{
			ft_printf("Error\nYou can't win on this map !\n");
			end(&game);
		}
		render_next_frame(&game);
		mlx_hook(game.mlx_win, KeyRelease, KeyReleaseMask, mykey_hook, &game);
		mlx_hook(game.mlx_win, 17, 0, end, &game);
		mlx_loop(game.mlx);
	}
}
