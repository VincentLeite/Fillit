/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:04:41 by mlavanan          #+#    #+#             */
/*   Updated: 2015/12/18 12:57:44 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_countallchar(char *tetro, int nbbsp, int nbdi, int nbpo)
{
	int i;

	i = 0;
	while (tetro[i] != '\0')
	{
		if (i < 20)
		{
			if (tetro[i] == '#')
				nbdi++;
			else if (tetro[i] == '.')
				nbpo++;
			else if (tetro[i] == '\n')
			{
				nbbsp++;
				if ((nbpo + nbdi) % 4 != 0)
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	if (nbdi == 4 && nbpo == 12 && nbbsp == 4)
		return (1);
	return (0);
}

void		ft_cut(char **map, int j)
{
	if (j == 1 && map[0][0] == 'A' && map[0][1] == 'A' && \
		map[1][0] == 'A' && map[1][1] == 'A')
	{
		map[0][2] = '\0';
		map[1][2] = '\0';
		map[2] = NULL;
	}
	else if (map[0][3] == '.' && map[1][3] == '.' && map[2][3] == '.' && \
		map[3][3] == '.' && map[3][2] == '.' && map[3][1] == '.' && \
		map[3][0] == '.')
	{
		map[0][3] = '\0';
		map[1][3] = '\0';
		map[2][3] = '\0';
		map[3] = NULL;
	}
}

void		ft_printmap(char **map, int j)
{
	int i;

	ft_cut(map, j);
	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i = i + 1;
	}
}

char		**ft_maprm(char **map, int i)
{
	int j;
	int k;

	j = 0;
	while (map[j])
	{
		k = 0;
		while (map[j][k] != '\0')
		{
			if (map[j][k] == (i + 'A'))
				map[j][k] = '.';
			k = k + 1;
		}
		j = j + 1;
	}
	return (map);
}

void		ft_reload(char **tmp, char **tetro, int count)
{
	int j;
	int k;

	j = 0;
	while (j < count)
	{
		k = 0;
		while (k < count)
		{
			if (j < 4 && k < 4 && tetro[j][k] == '#')
				tmp[j][k] = '#';
			else
				tmp[j][k] = '.';
			k = k + 1;
		}
		j = j + 1;
	}
}
