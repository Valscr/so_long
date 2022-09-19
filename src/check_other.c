/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:12:22 by valentin          #+#    #+#             */
/*   Updated: 2022/09/05 11:12:49 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	counter_collect(t_data *game)
{
	int		i;
	int		y;
	int		count;

	i = 0;
	y = 0;
	count = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][i] != '\0')
		{
			if (game->map[y][i] == game->content.collect)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}

int	check_player(t_data *game)
{
	int		i;
	int		y;
	int		p;

	p = 0;
	i = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][i] != '\0')
		{
			if (game->map[y][i] == game->content.player)
			{
				game->x = i;
				game->y = y;
				p++;
			}
			i++;
		}
		i = 0;
		y++;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	check_content(t_data *game, char content)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][i] != '\0')
		{
			if (game->map[y][i] == content)
				return (0);
			i++;
		}
		i = 0;
		y++;
	}
	return (1);
}
