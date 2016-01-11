/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:58:18 by vleite            #+#    #+#             */
/*   Updated: 2015/11/28 00:54:56 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *elem;
	t_list *prev_elem;

	new = NULL;
	if (lst)
	{
		new = (*f)(lst);
		prev_elem = new;
		lst = lst->next;
		while (lst)
		{
			elem = (*f)(lst);
			prev_elem->next = elem;
			prev_elem = elem;
			lst = lst->next;
		}
		prev_elem->next = NULL;
	}
	return (new);
}
