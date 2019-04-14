/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:28:39 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:28:41 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *begin;
	t_list *new;

	if (!lst || (*f) == NULL)
		return (NULL);
	new = (*f)(lst);
	if (!(begin = ft_lstnew(new->content, new->content_size)))
		return (NULL);
	new_list = begin;
	lst = lst->next;
	while (lst)
	{
		new = (*f)(lst);
		if (!(new_list->next = ft_lstnew(new->content, new->content_size)))
			return (NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (begin);
}
