/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:11:05 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 11:04:41 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*dest2;

	i = 0;
	dest1 = (char *)s1;
	dest2 = (char *)s2;
	while (i < n)
	{
		if (dest1[i] != dest2[i])
			return ((unsigned char)dest1[i] - (unsigned char)dest2[i]);
		i = i + 1;
	}
	return (0);
}
