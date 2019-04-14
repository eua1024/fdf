/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:28:26 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:28:27 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *next;

	if (lst != NULL)
	{
		next = lst->next;
		while (next != NULL)
		{
			next = lst->next;
			(*f)(lst);
			lst = next;
		}
	}
}
