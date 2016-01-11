/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:07:09 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 18:06:57 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		chr;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	chr = c;
	d = dst;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == chr)
		{
			i = i + 1;
			dst = &d[i];
			return (dst);
		}
		i = i + 1;
	}
	return (NULL);
}
