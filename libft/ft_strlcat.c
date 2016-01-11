/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:39:46 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 16:23:06 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (i > size)
		i = size;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i = i + 1;
		j = j + 1;
	}
	while (src[j] != '\0')
	{
		i = i + 1;
		j = j + 1;
	}
	return (i);
}
