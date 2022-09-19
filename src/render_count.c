/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:35:59 by valentin          #+#    #+#             */
/*   Updated: 2022/09/19 13:44:01 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_numb(t_data *game, int i, int j)
{
	int	a;

	a = game->win_height / game->height;
	if (i == 0)
		print_img(game, game->content.img0, j, a);
	if (i == 1)
		print_img(game, game->content.img1, j, a);
	if (i == 2)
		print_img(game, game->content.img2, j, a);
	if (i == 3)
		print_img(game, game->content.img3, j, a);
	if (i == 4)
		print_img(game, game->content.img4, j, a);
	if (i == 5)
		print_img(game, game->content.img5, j, a);
	if (i == 6)
		print_img(game, game->content.img6, j, a);
	if (i == 7)
		print_img(game, game->content.img7, j, a);
	if (i == 8)
		print_img(game, game->content.img8, j, a);
	if (i == 9)
		print_img(game, game->content.img9, j, a);
	return ;
}

void	render_counter(t_data *game)
{
	int		i;
	int		j;
	char	*s;

	i = game->count;
	s = ft_itoa(i);
	j = ft_strlen(s);
	free(s);
	while (i >= 10)
	{
		print_numb(game, (i % 10), j--);
			i = i / 10;
	}
	print_numb(game, i, j);
	return ;
}
