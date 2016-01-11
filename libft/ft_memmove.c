/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:52:47 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 15:24:30 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;
	char		*inter;

	i = 0;
	d = dst;
	s = src;
	inter = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		inter[i] = s[i];
		i = i + 1;
	}
	inter[i] = '\0';
	i = 0;
	while (i < len)
	{
		d[i] = inter[i];
		i = i + 1;
	}
	free(inter);
	return (dst);
}
