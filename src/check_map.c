/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 00:39:33 by valentin          #+#    #+#             */
/*   Updated: 2022/09/05 06:32:53 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_rect(t_data *game)
{
	int	i;
	int	j;

	j = 1;
	if (game->map == NULL)
	{
		ft_printf("Error\nMap file not found\n");
		return (1);
	}
	i = ft_strlen(game->map[0]);
	while (game->map[j] != NULL)
	{
		if (ft_strlen(game->map[j]) != i)
		{
			ft_printf("Error\nMap not rectangular\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_first_line(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (check_first_line(game))
		return (1);
	while (game->map[j])
	{
		if (game->map[j][0] != '1'
		|| game->map[j][ft_strlen(game->map[j]) - 1] != '1')
			return (1);
		j++;
	}
	j--;
	while (game->map[j][i])
	{
		if (game->map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_data *game)
{
	if (check_map_rect(game))
		return (1);
	if (check_wall(game))
	{
		ft_printf("Error\nMap not close\n");
		return (1);
	}
	if (check_content(game, 'P')
		|| check_content(game, 'C')
		/*|| check_content(game, '0')*/
		|| check_content(game, 'E'))
	{
		ft_printf("Error\nPlayer, collectible(s) or exit is missing on map\n");
		return (1);
	}	
	return (0);
}

int	check_element(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] != 'P' && game->map[y][x] != 'C'
				&& game->map[y][x] != 'E' && game->map[y][x] != '0'
					&& game->map[y][x] != '1' )
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
