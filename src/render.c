/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:14:21 by vescaffr          #+#    #+#             */
/*   Updated: 2022/09/19 13:32:36 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extern_wall(t_data *game, int y, int x)
{
	int	i;

	i = 0;
	if (y == 0)
		return (1);
	while (game->map[i] != NULL)
		i++;
	if (y == i - 1)
		return (1);
	if (x == 0)
		return (1);
	if (x == ft_strlen(game->map[y]) - 1)
		return (1);
	return (0);
}

void	render_back(t_data *game)
{
	int		i;
	int		y;

	y = 0;
	while (game->map[y] != NULL)
	{	
		i = 0;
		while (game->map[y][i] != '\0')
		{
			if (!check_extern_wall(game, y, i) && game->map[y][i]
				== game->content.wall && (i != game->x || y != game->y))
				print_img(game, game->img_wall, i, y);
			if (check_extern_wall(game, y, i) && game->map[y][i]
				== game->content.wall && (i != game->x || y != game->y))
				print_img(game, game->img_wallback, i, y);
			if (((game->map[y][i] == game->content.floor))
				&& (i != game->x || y != game->y))
				print_img(game, game->img_floor, i, y);
			if (game->map[y][i] == game->content.exit
				&& (i != game->x || y != game->y))
				print_img(game, game->img_exit, i, y);
			i++;
		}		
		y++;
	}
}

int	render_player(t_data *game)
{
	print_img(game, game->img_player, game->x, game->y);
	return (0);
}

int	render_collect(t_data *game)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][i] != '\0')
		{
			if (game->map[y][i] == game->content.collect
			&& (i != game->x || y != game->y))
				print_img(game, game->img_collect, i, y);
			if (game->map[game->y][game->x] == game->content.collect)
			{
					game->map[game->y][game->x] = game->content.floor;
					game->count_collect += 1;
			}
			i++;
		}
		i = 0;
		y++;
	}
	return (0);
}

/*int	render_count(t_data *game)
{
	int		x;
	int		y;
	char	*str;

	x = (game->width * 2) + (game->width / 2);
	y = game->window_height + 40;
	render_rect(game);
	if (game->count > 0)
	{
		str = ft_itoa(game->count);
		mlx_string_put(game->mlx, game->mlx_win, x, y, 0xFF0000, str);
		free(str);
	}
	return (0);
}*/

int	render_next_frame(t_data *game)
{
	render_back(game);
	render_player(game);
	render_collect(game);
	render_counter(game);
	return (0);
}
