/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:13:34 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 15:56:38 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tron;

	i = 0;
	tron = (char *)malloc(sizeof(char) * (len + 1));
	if (tron)
	{
		while (i < len)
		{
			tron[i] = s[start];
			i = i + 1;
			start = start + 1;
		}
		tron[i] = '\0';
		return (tron);
	}
	else
		return (NULL);
}
