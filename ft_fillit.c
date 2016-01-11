/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:42:36 by vleite            #+#    #+#             */
/*   Updated: 2015/12/18 12:38:37 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static void		ft_addpoint(char **map, int n, int i)
{
	int k;

	k = 0;
	while (k < (n + 1))
	{
		map[i][k] = '.';
		k = k + 1;
	}
}

void			ft_remap(char ***tetro, char **map, int i, int j)
{
	int n;

	i = 0;
	n = ft_strlen(map[0]);
	free(map);
	map = (char **)malloc(sizeof(char *) * (n + 2));
	map[n + 1] = NULL;
	while (i < (n + 1))
	{
		map[i] = (char *)malloc(sizeof(char) * (n + 2));
		map[i][n + 1] = '\0';
		i = i + 1;
	}
	i = 0;
	while (map[i] != NULL)
	{
		ft_addpoint(map, n, i);
		i = i + 1;
	}
	i = 0;
	ft_map(tetro, map, i, j);
}

int				ft_checkmap(char ***tetro, char **map, char ***tmp, int i)
{
	int		j;
	int		k;

	j = 0;
	while (map[j] != NULL)
	{
		k = 0;
		while (map[j][k] != '\0')
		{
			if (map[j][k] == (i + 'A'))
			{
				map = ft_maprm(map, i);
				return (ft_tmpmodif(tetro, map, tmp, i));
				k = k + 1;
			}
			if (tmp[i][j][k] == '#' && map[j][k] != '.')
				return (ft_tmpmodif(tetro, map, tmp, i));
			k = k + 1;
		}
		j = j + 1;
	}
	map = ft_mapcpy(map, tmp, i);
	return (1);
}

void			ft_map(char ***tetro, char **map, int i, int j)
{
	char	***tmp;
	int		count;

	count = 0;
	tmp = (char ***)malloc(sizeof(char **) * (j + 1));
	tmp[j] = NULL;
	while (map[count])
		count = count + 1;
	tmp = ft_malloctmp(tmp, count, j);
	ft_cpy(tmp, tetro, count, j);
	while (tetro[i] && i >= 0)
	{
		if (ft_checkmap(tetro, map, tmp, i))
			i = i + 1;
		else
		{
			ft_reload(tmp[i], tetro[i], count);
			i = i - 1;
		}
	}
	free(tmp);
	if (i < 0)
		ft_remap(tetro, map, i, j);
	else
		ft_printmap(map, j);
}

void			ft_fillit(char ***tetro, int i, int j, int count)
{
	char	**map;
	int		k;

	map = (char **)malloc(sizeof(char *) * 5);
	map[4] = NULL;
	while (i < 4)
	{
		map[i] = (char *)malloc(sizeof(char) * 5);
		map[i][4] = '\0';
		i = i + 1;
	}
	while (map[j] != NULL)
	{
		k = 0;
		while (k < 4)
		{
			map[j][k] = '.';
			k = k + 1;
		}
		j = j + 1;
	}
	i = 0;
	j = 0;
	ft_map(tetro, map, i, count);
}
