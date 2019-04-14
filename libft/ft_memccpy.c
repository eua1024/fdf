/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:22:12 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/02 17:22:14 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;
	size_t			i;

	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		if (srcptr[i] == (unsigned char)c)
		{
			dstptr[i] = srcptr[i];
			return (&dstptr[i + 1]);
		}
		i++;
	}
	return (NULL);
}
