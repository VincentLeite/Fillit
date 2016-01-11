/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:55:41 by vleite            #+#    #+#             */
/*   Updated: 2015/12/09 10:40:58 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	**ft_re(char **tmp, char **tetro, int i)
{
	int j;
	int k;

	j = 0;
	while (tetro[j] != NULL)
	{
		k = 0;
		while (tetro[j][k] != '\0')
		{
			if (tetro[j][k] == '#')
				tmp[i][k] = '#';
			k = k + 1;
		}
		j = j + 1;
		i = i + 1;
	}
	return (tmp);
}

char	**ft_recpy(char **tmp, char **tetro, int i, int j)
{
	int k;

	i = 0;
	while (tmp[i][j] != '#')
	{
		if (tmp[i][j] == '\0')
		{
			i = i + 1;
			j = 0;
		}
		j = j + 1;
	}
	j = 0;
	while (tmp[j] != NULL)
	{
		k = 0;
		while (tmp[j][k] != '\0')
		{
			tmp[j][k] = '.';
			k = k + 1;
		}
		j = j + 1;
	}
	return (ft_re(tmp, tetro, i));
}

char	***ft_moveright(char ***tmp, char *map, int i)
{
	int j;
	int k;

	j = (ft_strlen(map) - 1);
	while (j >= 0)
	{
		k = (ft_strlen(map) - 1);
		while (k >= 0)
		{
			if (tmp[i][j][k] == '#')
			{
				tmp[i][j][k + 1] = '#';
				tmp[i][j][k] = '.';
			}
			k = k - 1;
		}
		j = j - 1;
	}
	return (tmp);
}

char	***ft_movedown(char ***tmp, char ***tetro, char *map, int i)
{
	int j;
	int k;

	j = 0;
	tmp[i] = ft_recpy(tmp[i], tetro[i], i, j);
	j = (ft_strlen(map) - 1);
	while (j >= 0)
	{
		k = (ft_strlen(map) - 1);
		while (k >= 0)
		{
			if (tmp[i][j][k] == '#')
			{
				tmp[i][j + 1][k] = '#';
				tmp[i][j][k] = '.';
			}
			k = k - 1;
		}
		j = j - 1;
	}
	return (tmp);
}
