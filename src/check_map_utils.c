/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 08:31:05 by valentin          #+#    #+#             */
/*   Updated: 2022/09/19 13:58:52 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	passage(t_data *game, int checkscore, int y, int x)
{
	if (checkscore == 1)
		game->tab[((y) * (game->win_width / game->width)) + (x + 1)] += 1;
	if (checkscore == 2)
		game->tab[((y) * (game->win_width / game->width)) + (x + 1)] += 1;
	if (checkscore == 3)
		game->tab[((y) * (game->win_width / game->width)) + (x + 1)] += 1;
	if (checkscore == 4)
		game->tab[((y) * (game->win_width / game->width)) + (x + 1)] += 1;
	return ;
}

int	is_not_wall(t_data *game, char c)
{
	if (c == game->content.exit || c == game->content.floor
		|| c == game->content.collect || c == game->content.player)
		return (1);
	else
		return (0);
}

int	is_not_wall_exit(t_data *game, char c)
{
	if (c == game->content.floor || c == game->content.collect
		|| c == game->content.player)
		return (1);
	else
		return (0);
}

int	not_find_co(void)
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

int	init_score_collect(t_data *game, int y, int x)
{
	int	i;
	int	j;

	i = x - game->x_collect;
	if (i < 0)
		i = i * (-1);
	j = y - game->y_collect;
	if (j < 0)
		j = j * (-1);
	return (ft_sqrt((j * j) + (i * i)));
}
