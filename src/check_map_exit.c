/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 08:22:33 by valentin          #+#    #+#             */
/*   Updated: 2022/09/19 13:43:02 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_exit(t_data *game)
{
	int	i;
	int	y;
	int	f;

	i = 0;
	y = 0;
	f = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][i] != '\0')
		{
			if (game->map[y][i] == game->content.exit)
			{
				game->exit_x = i;
				game->exit_y = y;
				f++;
			}
			i++;
		}
		i = 0;
		y++;
	}
	if (f != 1)
		return (0);
	return (1);
}

int	init_score(t_data *game, int y, int x)
{
	int	i;
	int	j;

	i = x - game->exit_x;
	if (i < 0)
		i = i * (-1);
	j = y - game->exit_y;
	if (j < 0)
		j = j * (-1);
	return (ft_sqrt((j * j) + (i * i)));
}

int	check_score(t_data *game, int y, int x)
{
	int	w;
	int	a;
	int	d;
	int	s;

	w = 10000;
	a = 10000;
	d = 10000;
	s = 10000;
	if (is_not_wall(game, game->map[y - 1][x]))
		w = game->tab[((y - 1) * (game->win_width / game->width)) + (x + 1)];
	if (is_not_wall(game, game->map[y + 1][x]))
		s = game->tab[((y + 1) * (game->win_width / game->width)) + (x + 1)];
	if (is_not_wall(game, game->map[y][x - 1]))
		a = game->tab[((y) * (game->win_width / game->width)) + x];
	if (is_not_wall(game, game->map[y][x + 1]))
		d = game->tab[((y) * (game->win_width / game->width)) + (x + 2)];
	return (best_way(w, a, d, s));
}

int	check_exit_error(t_data *game)
{
	if (!check_exit(game))
	{
		ft_printf("You must have ONE Exit on the map !\n");
		return (0);
	}
	else
		return (1);
}

int	check_map_exit_valid(t_data *game)
{
	int	x;
	int	y;
	int	checkscore;

	x = game->x;
	y = game->y;
	if (!check_exit_error(game))
		return (0);
	init_tab_int(game);
	while (x != game->exit_x || y != game->exit_y)
	{
		checkscore = check_score(game, y, x);
		y += return_y(checkscore);
		x += return_x(checkscore);
		passage(game, checkscore, y, x);
		if (not_find() || check_score(game, y, x) == 0)
		{
			ft_printf("Exit is not reachable\n");
			free(game->tab);
			return (0);
		}
	}
	free(game->tab);
	return (1);
}
