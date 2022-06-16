/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:27:51 by chorse            #+#    #+#             */
/*   Updated: 2022/03/07 19:51:40 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*word_cr(char const *s, int j, char c, char **mass);
static int	ft_len(char const *s, char c);
static int	ft_isspace(char s, char c);
static void	ft_fre(char **mass, int len);

static int	ft_isspace(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_len(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (ft_isspace(s[i], c) && s[i] != '\0')
			i++;
		if (!(ft_isspace(s[i], c)) && s[i] != '\0')
		{
			cnt++;
			while (s[i] != '\0' && !(ft_isspace(s[i], c)))
				i++;
		}
	}
	return (cnt);
}

static char	*word_cr(char const *s, int j, char c, char **mass)
{
	char	*str;
	int		f;
	int		i;

	f = 0;
	i = j;
	while ((s[i] != '\0') && (!(ft_isspace(s[i], c))))
		i++;
	str = malloc(sizeof(char) * ((i - j) + 1));
	if (!str)
	{
		ft_fre(mass, ft_len(s, c));
		return (NULL);
	}
	while (j < i)
	{
		str[f] = s[j];
		f++;
		j++;
	}
	str[f] = '\0';
	return (str);
}

static void	ft_fre(char **mass, int len)
{
	while (len-- >= 0)
		free(mass[len]);
	free(mass);
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	int		i;
	int		j;
	int		inx;

	i = 0;
	inx = 0;
	if (!s)
		return (NULL);
	mass = malloc(sizeof(char *) * (ft_len(s, c) + 1));
	if (!mass)
		return (NULL);
	while (inx < ft_len(s, c))
	{
		while ((s[i] != '\0') && ft_isspace(s[i], c))
			i++;
		j = i;
		while ((s[i] != '\0') && (!(ft_isspace(s[i], c))))
			i++;
		mass[inx++] = word_cr(s, j, c, mass);
		i++;
	}
	mass[inx] = NULL;
	return (mass);
}
