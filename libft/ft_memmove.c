/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:38:40 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/02 22:38:42 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(dstptr, srcptr, len);
	else
		while (len--)
			dstptr[len] = srcptr[len];
	return (dstptr);
}
