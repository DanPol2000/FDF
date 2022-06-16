/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:44:52 by chorse            #+#    #+#             */
/*   Updated: 2022/03/08 12:12:26 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	file_check(char *file_name)
{
	int	i;
	int	size;

	size = ft_strlen(file_name);
	i = size - 4;
	if (file_name[i++] != '.')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	if (file_name[i++] != 'd')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	return (0);
}

void	get_color(t_dot *matrix, char *z)
{
	matrix->z = ft_atoi(z);
	if (matrix->z <= -7)
		matrix->color = 0x78ab78;
	if (matrix->z > -7)
		matrix->color = 0xCAFFCA;
	if (matrix->z > -5)
		matrix->color = 0xACFFAC;
	if (matrix->z > -3)
		matrix->color = 0x97FF97;
	if (matrix->z > -1)
		matrix->color = 0x5CFF5C;
	if (matrix->z == 0)
		matrix->color = 0x00CC00;
	if (matrix->z > 1)
		matrix->color = 0x00A300;
	if (matrix->z > 3)
		matrix->color = 0x008200;
	if (matrix->z > 5)
		matrix->color = 0x006800;
	if (matrix->z > 7)
		matrix->color = 0xA30000;
	if (matrix->z > 9)
		matrix->color = 0xCC0000;
}

void	init_img(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1800, 1000, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, data->scr_x, data->scr_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
										&data->line_length, &data->endian);
}
