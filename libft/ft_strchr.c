/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:37:11 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 15:36:46 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)s;
	if (dst[i] == c)
		return (&dst[i]);
	while (dst[i] != '\0')
	{
		i = i + 1;
		if (dst[i] == c)
			return (&dst[i]);
	}
	return (NULL);
}
