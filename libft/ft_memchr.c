/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:56:17 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 12:02:11 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*tab;
	void			*p;

	i = 0;
	chr = c;
	p = (void *)s;
	tab = (unsigned char *)s;
	while (i < n)
	{
		if (tab[i] == chr)
			return (&p[i]);
		i = i + 1;
	}
	return (NULL);
}
