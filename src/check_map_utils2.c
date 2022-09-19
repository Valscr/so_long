/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 08:34:03 by valentin          #+#    #+#             */
/*   Updated: 2022/09/05 09:00:26 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	return (i);
}

int	return_y(int checkscore)
{
	int	i;

	i = 0;
	if (checkscore == 1)
		i--;
	if (checkscore == 2)
		i++;
	return (i);
}

int	return_x(int checkscore)
{
	int	i;

	i = 0;
	if (checkscore == 3)
		i--;
	if (checkscore == 4)
		i++;
	return (i);
}

void	free_map_test(t_data *game)
{
	int	i;

	i = 0;
	while (game->maptest[i])
		free(game->maptest[i++]);
	free(game->maptest);
}

/*int rand()
{
	static int i;

	i = i * 0x343fd + 0x269ec3;
	i = (i>>16)&0x7fff;
	if (i % 2 == 0)
		return (1);
	else
		return (0);
}*/