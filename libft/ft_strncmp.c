/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:40:02 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 18:55:08 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && j < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i = i + 1;
		j = j + 1;
	}
	if (j == n)
		return (0);
	if (s1[i] == '\0' && s2[i] != '\0')
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}
