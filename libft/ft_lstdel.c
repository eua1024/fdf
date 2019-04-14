/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:28:00 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:28:01 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	list = *alst;
	if (list && del)
	{
		while (list)
		{
			(*del)(list->content, list->content_size);
			free(list);
			list = list->next;
		}
	}
	*alst = NULL;
}
