/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:47:02 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 12:49:08 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = (char *)s1;
	if (s2[j] == '\0')
		return (dst);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			while (s2[j] != '\0' && s1[i + j] == s2[j])
				j = j + 1;
			if (s2[j] == '\0')
				return (&dst[i]);
			j = 0;
		}
		i = i + 1;
	}
	return (NULL);
}
