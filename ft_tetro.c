/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:04:50 by vleite            #+#    #+#             */
/*   Updated: 2015/12/09 10:41:57 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void		ft_maketetro(char ***tetro, char *str, int i, int j)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] == '.' || str[n] == '#')
		{
			tetro[i][j][k] = str[n];
			k = k + 1;
		}
		if (str[n] == '\n' && str[n + 1] != '\n' && str[n - 1] != '\n')
		{
			j = j + 1;
			k = 0;
		}
		if (str[n] == '\n' && str[n + 1] == '\n')
		{
			i = i + 1;
			j = 0;
			k = 0;
		}
		n = n + 1;
	}
}

char		***ft_malloctetro(char ***tetro, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		tetro[i] = (char **)malloc(sizeof(char *) * 5);
		tetro[i][4] = NULL;
		while (j < 4)
		{
			tetro[i][j] = (char *)malloc(sizeof(char) * 5);
			tetro[i][j][4] = '\0';
			j = j + 1;
		}
		i = i + 1;
	}
	return (tetro);
}

int			ft_counttetro(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			count = count + 1;
		i = i + 1;
	}
	return (count);
}

void		ft_tetro(char *str)
{
	char	***tetro;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = ft_counttetro(str);
	tetro = (char ***)malloc(sizeof(char **) * (count + 1));
	tetro[count] = NULL;
	tetro = ft_malloctetro(tetro, count);
	ft_maketetro(tetro, str, i, j);
	while (tetro[i])
	{
		ft_setupleft(tetro[i]);
		i++;
	}
	i = 0;
	ft_fillit(tetro, i, j, count);
}
