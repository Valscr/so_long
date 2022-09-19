/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:17:18 by valentin          #+#    #+#             */
/*   Updated: 2022/08/22 00:45:49 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_map(char **str, t_data *game)
{
	int	fd;

	fd = 0;
	game->map = NULL;
	if (ft_strnstr(str[1], ".ber", 100) == 0)
	{
		ft_printf("Error\nNo correct format map finded (.ber)\n");
		return (1);
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			parse_map(fd, game);
	}
	if (check_file(game))
		return (1);
	if (check_map(game))
	{
		free_map(game);
		return (1);
	}
	return (0);
}

int	check_file(t_data *game)
{
	if (game->map == NULL)
	{
		ft_printf("Error\nMap file not found\n");
		return (1);
	}
	return (0);
}

void	parse_map(int fd, t_data *game)
{
	char	*str;

	str = get_next_line(fd);
	if (str == 0)
	{
		ft_printf("Empty file\nYour map must contain 1, C, P, 0 and E\n");
		exit(0);
	}
	game->map = ft_split(str, '\n');
	if (check_element(game))
	{
		free(str);
		free_map(game);
		ft_printf("Error\nYour map must contain only 1, C, P, 0 and E\n");
		exit(0);
	}
	free(str);
}
