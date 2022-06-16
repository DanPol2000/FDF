/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:03:09 by chorse            #+#    #+#             */
/*   Updated: 2022/03/08 12:58:42 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(key, data);
	if (key == ZOOM_UP || key == ZOOM_DOWN)
		zoom_k(key, data);
	if (key == ANGLE_COS_DOWN || key == ANGLE_COS_UP || key == ANGLE_SIN_DOWN \
												|| key == ANGLE_SIN_UP)
		angle(key, data);
	if (key == Z_UP || key == Z_DOWN)
		z_scale(key, data);
	if (key == ISO_ON)
		data->flag = 1;
	if (key == ISO_OFF)
		data->flag = 0;
	if (key == RESET)
		first_init(data);
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img);
		ft_free_data_struct(data);
		exit(0);
	}
	draw(data);
	return (0);
}

void	zoom(t_dot *a, t_dot *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	a->z *= (data->z_scale);
	b->x *= data->zoom;
	b->y *= data->zoom;
	b->z *= data->z_scale;
}

void	shift(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}

void	ft_free_data_struct(t_fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2 || file_check(argv[1]) == 1)
		return (0);
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	if (ft_read_file(argv[1], data) == 1)
	{
		free(data);
		return (0);
	}
	first_init(data);
	init_img(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}
