/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:44:01 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 17:50:40 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_end(char *dst)
{
	int i;

	i = 0;
	while (dst[i] != '\0')
		i = i + 1;
	i = i - 1;
	while (dst[i] == ' ' || dst[i] == '\n' || dst[i] == '\t')
		i = i - 1;
	i = i + 1;
	dst[i] = '\0';
	return (dst);
}

static char	const	*ft_start(char const *s, int i)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i = i + 1;
	return (&s[i]);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	char	*dst;

	i = 0;
	s = ft_start(s, i);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i = i + 1;
	}
	dst[i] = '\0';
	dst = ft_end(dst);
	return (dst);
}
