/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:16:58 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 13:09:47 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = n * (-1);
		count = count + 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count = count + 1;
	}
	count = count + 1;
	return (count);
}

char			*ft_itoa(int n)
{
	int		count;
	char	*tab;

	if (n == -2147483648)
		return ("-2147483648");
	count = ft_count(n);
	tab = (char *)malloc(sizeof(char) * (count + 1));
	if (!tab)
		return (NULL);
	if (n < 0)
	{
		tab[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		tab[count - 1] = '0';
	while (n != 0)
	{
		count = count - 1;
		tab[count] = ((n % 10) + '0');
		n = n / 10;
	}
	return (tab);
}
