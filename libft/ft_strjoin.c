/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:26:31 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 15:43:07 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[j] != '\0')
	{
		join[i] = s1[j];
		i = i + 1;
		j = j + 1;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i = i + 1;
		j = j + 1;
	}
	join[i] = '\0';
	return (join);
}
