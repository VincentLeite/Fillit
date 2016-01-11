/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:11:21 by vleite            #+#    #+#             */
/*   Updated: 2015/12/10 11:48:54 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static void		ft_cpyagain(char ***tmp, char ***tetro, int *tab, int len)
{
	int k;

	k = 0;
	while (k < len)
	{
		if (tab[1] < 4 && k < 4)
		{
			if (tetro[tab[0]][tab[1]][k] == '#')
				tmp[tab[0]][tab[1]][k] = '#';
			else
				tmp[tab[0]][tab[1]][k] = '.';
		}
		else
			tmp[tab[0]][tab[1]][k] = '.';
		k = k + 1;
	}
}

char			***ft_malloctmp(char ***tmp, int count, int j)
{
	int i;
	int n;
	int k;

	i = 0;
	while (i < j)
	{
		n = 0;
		tmp[i] = (char **)malloc(sizeof(char *) * (count + 1));
		tmp[i][count] = NULL;
		while (n < count)
		{
			k = 0;
			tmp[i][n] = (char *)malloc(sizeof(char) * (count + 1));
			tmp[i][n][count] = '\0';
			n = n + 1;
		}
		i = i + 1;
	}
	return (tmp);
}

void			ft_cpy(char ***tmp, char ***tetro, int len, int count)
{
	int tab[2];

	tab[0] = 0;
	while (tab[0] < count)
	{
		tab[1] = 0;
		while (tab[1] < len)
		{
			ft_cpyagain(tmp, tetro, tab, len);
			tab[1] = tab[1] + 1;
		}
		tab[0] = tab[0] + 1;
	}
}

char			**ft_mapcpy(char **map, char ***tmp, int i)
{
	int j;
	int k;

	j = 0;
	while (map[j] != NULL)
	{
		k = 0;
		while (map[j][k] != '\0')
		{
			if (tmp[i][j][k] == '#')
				map[j][k] = ('A' + i);
			k = k + 1;
		}
		j = j + 1;
	}
	return (map);
}

int				ft_tmpmodif(char ***tetro, char **map, char ***tmp, int i)
{
	size_t j;
	size_t k;

	j = 0;
	k = 0;
	while (j < ft_strlen(map[0]))
	{
		if (tmp[i][j][ft_strlen(map[0]) - 1] == '#')
			k = 1;
		j = j + 1;
	}
	if (k == 0)
	{
		tmp = ft_moveright(tmp, map[0], i);
		return (ft_checkmap(tetro, map, tmp, i));
	}
	k = 0;
	while (k < ft_strlen(map[0]))
	{
		if (tmp[i][ft_strlen(map[0]) - 1][k] == '#')
			return (0);
		k = k + 1;
	}
	tmp = ft_movedown(tmp, tetro, map[0], i);
	return (ft_checkmap(tetro, map, tmp, i));
}
