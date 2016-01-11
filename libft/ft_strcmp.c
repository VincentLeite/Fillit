/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:11:54 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 18:43:30 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i = i + 1;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}
