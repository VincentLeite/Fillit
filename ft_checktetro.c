/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktetro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:09:35 by mlavanan          #+#    #+#             */
/*   Updated: 2015/12/18 12:58:35 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static int		ft_error(void)
{
	ft_putendl("error");
	return (0);
}

static int		tetroshape(char *tetro)
{
	int i;
	int nbdi;
	int test;

	test = 0;
	nbdi = 0;
	i = 0;
	while (tetro[i] != '\0')
	{
		if (tetro[i] == '#')
		{
			if (ft_islshape(tetro, i, nbdi) == 1)
				return (1);
			if (tetro[i + 4] == '#' && tetro[i + 5] != '#'
				&& tetro[i + 1] != '#')
				test++;
			if (ft_checkforshape(tetro, i, nbdi) != 1)
				return (0);
			nbdi++;
		}
		i++;
	}
	if (test > 1)
		return (0);
	return (1);
}

static int		is_tetro(char *tetro)
{
	int nbbsp;
	int nbdi;
	int nbpo;
	int shape;
	int charok;

	nbbsp = 0;
	nbdi = 0;
	nbpo = 0;
	charok = ft_countallchar(tetro, nbbsp, nbdi, nbpo);
	shape = tetroshape(tetro);
	if (charok != 1)
		return (-27);
	if (shape != 1)
		return (-27);
	else
		return (1);
}

static int		gettetro(char *tab)
{
	char	*tetro;
	int		pos;
	int		valid;
	int		i;

	tetro = malloc((sizeof(char) * 21) + 1);
	pos = 0;
	i = 0;
	valid = 0;
	if (!tetro)
		return (ft_error());
	while (tab[pos] != '\0')
	{
		while (i < 21)
		{
			tetro[i] = tab[pos];
			i++;
			pos++;
		}
		tetro[i] = '\0';
		valid += is_tetro(tetro);
		i = 0;
	}
	return (valid);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		valid;
	char	buf[BUF_SIZE];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (ft_error());
		ret = read(fd, buf, BUF_SIZE);
		valid = ft_checkreadlen(ret);
		buf[ret] = '\0';
		valid += gettetro(buf);
		if (ret > 545)
			return (ft_error());
		if (valid < 0)
			return (ft_error());
		ft_tetro(buf);
		return (0);
	}
	else
		return (ft_error());
}
