/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:55:21 by mlavanan          #+#    #+#             */
/*   Updated: 2015/12/10 19:43:16 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_checkreadlen(int ret)
{
	if (ret < 20)
		return (-27);
	if (ret % 20 != 0 && ret < 30)
		return (-27);
	if ((ret - 20) % 21 != 0 && ret > 21)
		return (-27);
	return (0);
}

int		ft_checkforshape(char *tetro, int i, int nbdi)
{
	if (nbdi != 3)
	{
		if (tetro[i + 4] == '#' && tetro[i - 1] != '#' && tetro[i + 5] != '#')
			return (0);
		if (tetro[i + 1] != '#' && tetro[i + 5] != '#' &&
			tetro[i + 4] != '#')
			return (0);
	}
	if (nbdi == 3 && tetro[i - 5] != '#' && tetro[i - 1] != '#')
		return (0);
	return (1);
}

int		ft_islshape(char *tetro, int i, int nbdi)
{
	if (nbdi == 0 && tetro[i + 1] == '#' && tetro[i + 2] == '#' &&
		tetro[i + 5] == '#')
		return (1);
	return (0);
}
