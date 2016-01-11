/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupleft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:43:48 by mlavanan          #+#    #+#             */
/*   Updated: 2015/12/08 15:01:01 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static char		**ft_up(char **mtetro)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (mtetro[i] != NULL)
	{
		while (mtetro[i][j] != '\0')
		{
			if (mtetro[i][j] == '#')
			{
				mtetro[i - 1][j] = '#';
				mtetro[i][j] = '.';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (mtetro);
}

static char		**ft_left(char **mtetro)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (mtetro[i] != NULL)
	{
		while (mtetro[i][j] != '\0')
		{
			if (mtetro[i][j] == '#')
			{
				mtetro[i][j - 1] = '#';
				mtetro[i][j] = '.';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (mtetro);
}

char			**ft_setup(char **mtetro)
{
	int i;
	int j;
	int istop;

	i = 0;
	j = 0;
	istop = 0;
	while (!istop)
	{
		while (mtetro[i][j] != '\0')
		{
			if (mtetro[i][j] == '#')
				istop = 1;
			j++;
		}
		if (!istop)
			mtetro = ft_up(mtetro);
		j = 0;
	}
	return (mtetro);
}

char			**ft_setleft(char **mtetro)
{
	int i;
	int j;
	int isleft;

	i = 0;
	j = 0;
	isleft = 0;
	while (!isleft)
	{
		while (mtetro[i] != NULL)
		{
			if (mtetro[i][j] == '#')
				isleft = 1;
			i++;
		}
		if (!isleft)
			ft_left(mtetro);
		i = 0;
	}
	return (mtetro);
}

char			**ft_setupleft(char **mtetro)
{
	mtetro = ft_setup(mtetro);
	mtetro = ft_setleft(mtetro);
	return (mtetro);
}
