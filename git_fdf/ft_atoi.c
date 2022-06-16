/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:25:40 by chorse            #+#    #+#             */
/*   Updated: 2022/03/07 19:38:17 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(int c)
{
	if (c == '\f' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\v' || c == ' ')
		return (c);
	return (0);
}

static int	ft_plus(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && (s[i + 1] == '+' || s[i + 1] == '-'))
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int			min;
	long int	numb;

	min = 1;
	numb = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_plus((char *)str))
		return (0);
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		min *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (numb * min < -2147483648)
			return (0);
		else if (numb > 2147483647)
			return (-1);
		numb = (numb * 10) + *str++ - '0';
	}
	return (numb * min);
}

void	open_fill(char *file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;
	int		y;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return ;
	i = 0;
	y = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matrix[i++], line, y++);
		free(line);
	}
	close(fd);
}

int	hex_to_dec(char *hex, int decimal)
{
	long long	base;
	int			i;

	base = 1;
	i = ft_strlen(hex);
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	return (decimal);
}
