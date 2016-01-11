/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:26:53 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 10:31:18 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_count(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i = i + 1;
	while (str[i] >= '0' && str[i] <= '9')
		i = i + 1;
	i = i - 1;
	return (i);
}

static const char	*ft_check_space(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
	str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
	{
		i = i + 1;
	}
	str = &str[i];
	return (str);
}

int					ft_atoi(const char *str)
{
	int i;
	int nbr;
	int coef;

	str = ft_check_space(str);
	i = ft_count(str);
	nbr = 0;
	coef = 1;
	while (i >= 0)
	{
		if (str[i] == '-')
		{
			nbr = nbr * (-1);
			return (nbr);
		}
		if (str[i] == '+')
			return (nbr);
		nbr = nbr + (coef * (str[i] - '0'));
		coef = coef * 10;
		i = i - 1;
	}
	return (nbr);
}
