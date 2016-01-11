/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:12:21 by vleite            #+#    #+#             */
/*   Updated: 2015/11/26 15:55:13 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words = words + 1;
			while (s[i] != c && s[i] != '\0')
				i = i + 1;
		}
		while (s[i] == c)
			i = i + 1;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	int				words;
	int				i;
	unsigned int	j;
	char			**tab;
	size_t			len;

	words = ft_words(s, c);
	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		len = 0;
		while (s[j] == c)
			j = j + 1;
		while (s[j + len] != c && s[j + len] != '\0')
			len = len + 1;
		tab[i] = ft_strsub(s, j, len);
		i = i + 1;
		j = j + len;
	}
	tab[i] = NULL;
	return (tab);
}
