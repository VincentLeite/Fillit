/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:38:36 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 12:13:30 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	dst = ft_strcpy(dst, s1);
	if (s2[j] == '\0')
		return (dst);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
		{
			while (s2[j] != '\0' && s1[i + j] == s2[j] & (i + j) < n)
				j = j + 1;
			if (s2[j] == '\0')
				return (&dst[i]);
			j = 0;
		}
		i = i + 1;
	}
	return (NULL);
}
