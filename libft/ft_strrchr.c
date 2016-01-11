/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:29:41 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 11:30:42 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	dst = ft_strcpy(dst, s);
	if (dst[i] == c)
		p = (char *)&s[i];
	while (dst[i] != '\0')
	{
		i = i + 1;
		if (dst[i] == c)
			p = (char *)&s[i];
	}
	i = 0;
	while (dst[i] != '\0' && dst[i] != c)
	{
		i = i + 1;
	}
	if (dst[i] == c)
		return (p);
	else
		return (NULL);
}
