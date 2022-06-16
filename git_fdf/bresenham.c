/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:51:47 by chorse            #+#    #+#             */
/*   Updated: 2022/03/07 18:42:50 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float	ft_mod(float a)
{
	if (a < 0)
		return (-1 * a);
	else
		return (a);
}

void	ft_isometric(t_dot *start, t_dot *end, t_fdf *data)
{
	start->x = (start->x - start->y) * cos(data->angle_cos);
	start->y = (start->x + start->y) * sin(data->angle_sin) - start->z;
	end->x = (end->x - end->y) * cos(data->angle_cos);
	end->y = (end->x + end->y) * sin(data->angle_sin) - end->z;
}

void	bresenham(t_dot start, t_dot end, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	zoom(&start, &end, data);
	if (data->flag)
		ft_isometric(&start, &end, data);
	shift(&start, &end, data);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	if (start.z < end.z)
		start.color = end.color;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if ((int)start.x < data->scr_x && (int)start.y < data->scr_y
			&& (int)start.x >= 0 && (int)start.y >= 0)
			my_mlx_pixel_put(data, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_bzero(data->addr, data->scr_y * data->scr_x * \
		(data->bits_per_pixel / 8));
	action(data, x, y, data->matrix);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	print_menu(data);
}
