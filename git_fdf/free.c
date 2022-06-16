/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:40:23 by chorse            #+#    #+#             */
/*   Updated: 2022/03/08 12:42:51 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}

void	free_matrix(t_dot **matrix, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
