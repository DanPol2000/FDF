/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:27:21 by chorse            #+#    #+#             */
/*   Updated: 2022/03/06 16:11:35 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	move(int key, t_fdf *data)
{
	if (key == UP)
		data->shift_y -= 50;
	if (key == DOWN)
		data->shift_y += 50;
	if (key == LEFT)
		data->shift_x -= 50;
	if (key == RIGHT)
		data->shift_x += 50;
	return (0);
}

int	zoom_k(int key, t_fdf *data)
{
	if (key == ZOOM_UP)
		data->zoom += 1;
	if (key == ZOOM_DOWN && data->zoom > 0)
		data->zoom -= 1;
	return (0);
}

int	angle(int key, t_fdf *data)
{
	if (key == ANGLE_COS_UP)
		data->angle_cos += 0.01;
	if (key == ANGLE_COS_DOWN)
		data->angle_cos -= 0.01;
	if (key == ANGLE_SIN_UP)
		data->angle_sin += 0.01;
	if (key == ANGLE_SIN_DOWN)
		data->angle_sin -= 0.01;
	return (0);
}

int	z_scale(int key, t_fdf *data)
{
	if (key == Z_UP)
		data->z_scale += 0.1;
	if (key == Z_DOWN)
		data->z_scale -= 0.1;
	return (0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
