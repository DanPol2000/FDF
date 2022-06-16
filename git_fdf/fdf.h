/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:08:05 by chorse            #+#    #+#             */
/*   Updated: 2022/03/08 12:43:05 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define WIDTH			1800
# define HEIGHT			1000

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define ZOOM_UP		24
# define ZOOM_DOWN		27
# define ANGLE_COS_DOWN	1
# define ANGLE_COS_UP	0
# define ANGLE_SIN_DOWN	2
# define ANGLE_SIN_UP	3
# define Z_UP			13
# define Z_DOWN			12
# define ISO_ON			18
# define ISO_OFF		19
# define RESET			48

typedef struct s_dot
{
	float	x;
	float	y;
	int		z;
	int		color;
}		t_dot;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		zoom;
	t_dot	**matrix;
	int		color;
	double	angle_cos;
	double	angle_sin;
	double	z_scale;
	int		flag;
	int		shift_x;
	int		shift_y;
	int		scr_x;
	int		scr_y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx_ptr;
	void	*win_ptr;
}		t_fdf;

int		ft_get_height(char *file);
int		ft_get_width(char *file);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char	*str);
int		ft_read_file(char *file_name, t_fdf *data);
void	bresenham(t_dot start, t_dot end, t_fdf *data);
void	first_init(t_fdf *data);
void	draw(t_fdf *data);
void	print_menu(t_fdf *data);
int		move(int key, t_fdf *data);
int		zoom_k(int key, t_fdf *data);
int		angle(int key, t_fdf *data);
int		z_scale(int key, t_fdf *data);
void	ft_free_data_struct(t_fdf *data);
int		file_check(char *file_name);
void	get_color(t_dot *p, char *z);
void	init_img(t_fdf *data);
void	shift(t_dot *start, t_dot *end, t_fdf *data);
void	zoom(t_dot *a, t_dot *b, t_fdf *data);
void	fill_matrix(t_dot *matrix, char *line, int y);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	ft_bzero(void *str, size_t n);
void	action(t_fdf *data, int x, int y, t_dot **matrix);
void	open_fill(char *file, t_fdf *data);
void	ft_free(char **arr);
int		hex_to_dec(char *hex, int decimal);
int		check_color(char *str);
void	free_matrix(t_dot **matrix, int length);

#endif
