/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:15:51 by vescaffr          #+#    #+#             */
/*   Updated: 2022/09/19 13:57:23 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <X11/keysym.h> 
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct cnt_s
{
	char	player;
	char	wall;
	char	floor;
	char	collect;
	char	exit;
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
}				t_cnt;

typedef struct s_data
{	
	void	*mlx;
	void	*mlx_win;
	void	*img_player;
	void	*img_wall;
	void	*img_wallback;
	void	*img_floor;
	void	*img_collect;
	void	*img_exit;
	int		width;
	int		height;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
	int		*tab;
	char	**map;
	char	**maptest;
	int		win_width;
	int		win_height;
	int		x_collect;
	int		y_collect;
	int		count_collect;
	int		total_collect;
	int		win;
	int		count;
	t_cnt	content;
}				t_data;

void	check_win(t_data *game);
int		end(t_data *game);
int		mykey_hook(int keycode, t_data *game);
void	set_content(t_data *game);
int		check_player(t_data *game);
int		counter_collect(t_data *game);
void	set_parametre(t_data *game);
int		set_map(char **str, t_data *game);
int		print_img(t_data *game, void *imgg, int x, int y);
void	render_back(t_data *game);
int		render_player(t_data *game);
int		render_collect(t_data *game);
int		render_next_frame(t_data *game);
void	render_top(t_data *game);
void	render_right(t_data *game);
void	render_left(t_data *game);
void	render_down(t_data *game);
int		render_count(t_data *game);
void	set_data(t_data *game);
int		window_size(t_data *game);
size_t	ft_strlen1(char *s);
int		check_end(char *dest);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_cut_dest(char *dest);
char	*new_save(char *dest);
char	*get_next(char *save, int fd);
char	*get_next_line(int fd);
int		check_map(t_data *game);
int		check_wall(t_data *game);
int		check_map_rect(t_data *game);
int		check_first_line(t_data *game);
int		check_content(t_data *game, char content);
int		check_element(t_data *game);
void	parse_map(int fd, t_data *game);
void	free_map(t_data *game);
int		check_file(t_data *game);
int		render_rect(t_data *game);
void	print_numb(t_data *game, int i, int j);
void	render_counter(t_data *game);
int		check_exit(t_data *game);
int		check_exit_error(t_data *game);
int		check_map_valid(t_data *game);
void	free_map_test(t_data *game);
int		check_score(t_data *game, int y, int x);
int		init_score(t_data *game, int y, int x);
int		init_score_collect(t_data *game, int y, int x);
int		init_tab_int(t_data *game);
int		best_way(int w, int a, int d, int s);
int		check_map_collect(t_data *game);
int		check_map_collect_valid(t_data *game);
int		check_map_exit_valid(t_data *game);
int		init_tab_int_collect(t_data *game);
int		check_score_collect(t_data *game, int y, int x);
int		copy_map(t_data *game);
void	find_collect(t_data *game);
int		not_find(void);
int		not_find_co(void);
void	passage(t_data *game, int checkscore, int y, int x);
int		is_not_wall(t_data *game, char c);
int		is_not_wall_exit(t_data *game, char c);
int		ft_sqrt(int nb);
int		return_y(int checkscore);
int		return_x(int checkscore);

#endif