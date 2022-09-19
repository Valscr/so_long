/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_collect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 08:27:01 by valentin          #+#    #+#             */
/*   Updated: 2022/09/19 13:54:55 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_tab_int_collect(t_data *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	game->tab = malloc(sizeof(int) * ((game->win_height / game->height)
				* (game->win_width / game->width) + 1));
	if (!game->tab)
		return (0);
	while (game->maptest[y] != NULL)
	{
		while (game->maptest[y][i] != '\0')
		{
			if (is_not_wall(game, game->maptest[y][i]))
				game->tab[(i + 1) + ((y) * (game->win_width / game->width))]
					= init_score_collect(game, y, i);
			if (game->maptest[y][i] == game->content.wall)
				game->tab[(i + 1) + (y * (game->win_width / game->width))] = -1;
			i++;
		}
		i = 0;
		y++;
	}
	return (1);
}

int	check_score_collect(t_data *game, int y, int x)
{
	int	w;
	int	a;
	int	d;
	int	s;

	w = 10000;
	a = 10000;
	d = 10000;
	s = 10000;
	if (is_not_wall_exit(game, game->maptest[y - 1][x]))
		w = game->tab[((y - 1) * (game->win_width / game->width)) + (x + 1)];
	if (is_not_wall_exit(game, game->maptest[y + 1][x]))
		s = game->tab[((y + 1) * (game->win_width / game->width)) + (x + 1)];
	if (is_not_wall_exit(game, game->maptest[y][x - 1]))
		a = game->tab[((y) * (game->win_width / game->width)) + x];
	if (is_not_wall_exit(game, game->maptest[y][x + 1]))
		d = game->tab[((y) * (game->win_width / game->width)) + (x + 2)];
	return (best_way(w, a, d, s));
}

int	copy_map(t_data *game)
{
	int		x;
	int		y;
	int		d;

	y = 0;
	d = 0;
	while (game->map[d] != NULL)
		d++;
	game->maptest = malloc(sizeof(char *) * (d + 1));
	while (game->map[y] != NULL)
	{
		x = 0;
		game->maptest[y] = malloc(sizeof(char) * (ft_strlen(game->map[y]) + 1));
		if (!game->maptest[y] || !game->maptest)
			return (0);
		while (game->map[y][x] != '\0')
		{
			game->maptest[y][x] = game->map[y][x];
			x++;
		}
		game->maptest[y][x] = '\0';
		y++;
	}
	game->maptest[y] = NULL;
	return (1);
}

void	find_collect(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->maptest[y] != NULL)
	{
		while (game->maptest[y][x] != '\0')
		{
			if (game->maptest[y][x] == 'C')
			{
				game->x_collect = x;
				game->y_collect = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}
