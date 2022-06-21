/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:21:55 by vescaffr          #+#    #+#             */
/*   Updated: 2022/06/21 16:57:06 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	test(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}

int	main(void)
{
	test();
}