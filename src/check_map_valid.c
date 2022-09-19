/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:08:29 by valentin          #+#    #+#             */
/*   Updated: 2022/09/19 13:56:13 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_tab_int(t_data *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	game->tab = malloc(sizeof(int) * ((game->win_height / game->height)
				* (game->win_width / game->width) + 1));
	if (!game->tab)
		return (0);
	while (game->map[y] != NULL)
	{
		while (game->map[y][i] != '\0')
		{
			if (is_not_wall(game, game->map[y][i]))
				game->tab[(i + 1) + (y * (game->win_width / game->width))]
					= init_score(game, y, i);
			if (game->map[y][i] == game->content.wall)
				game->tab[(i + 1) + (y * (game->win_width / game->width))] = -1;
			i++;
		}
		i = 0;
		y++;
	}
	return (1);
}

int	best_way(int w, int a, int d, int s)
{
	if (w <= s && w <= a && w <= d && w >= 0)
		return (1);
	else if (s <= w && s <= a && s <= d && s >= 0)
		return (2);
	else if (a <= s && a <= w && a <= d && a >= 0)
		return (3);
	else if (d <= s && d <= a && d <= w && d >= 0)
		return (4);
	else
		return (0);
}

int	check_map_collect(t_data *game)
{
	int	x;
	int	y;
	int	checkscore;

	x = game->x;
	y = game->y;
	init_tab_int_collect(game);
	while (x != game->x_collect || y != game->y_collect)
	{
		checkscore = check_score_collect(game, y, x);
		y += return_y(checkscore);
		x += return_x(checkscore);
		passage(game, checkscore, y, x);
		if (not_find_co() || checkscore == 0)
		{
			free(game->tab);
			return (0);
		}
	}
	free(game->tab);
	return (1);
}

int	check_map_collect_valid(t_data *game)
{
	if (!copy_map(game))
		return (0);
	while (game->count_collect < game->total_collect)
	{
		find_collect(game);
		if (!check_map_collect(game))
		{
			free_map_test(game);
			ft_printf("Collectibles are not all reachable\n");
			return (0);
		}
		else
		{
			game->maptest[game->y_collect][game->x_collect] = '0';
			game->count_collect++;
		}
	}
	game->count_collect = 0;
	free_map_test(game);
	return (1);
}

int	check_map_valid(t_data *game)
{
	int	i;

	i = 0;
	if (check_map_exit_valid(game))
		i++;
	if (check_map_collect_valid(game))
		i++;
	if (i == 2)
	{
		ft_printf("Valid Map\n");
		return (1);
	}
	else
		return (0);
}
