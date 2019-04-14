/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:29:12 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:29:12 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if ((ptr = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
