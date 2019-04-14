/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:39:55 by efedoryc          #+#    #+#             */
/*   Updated: 2016/11/21 18:39:58 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			i;
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	i = 0;
	while (srcptr[i] != '\0' && i < len)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	while (i != len)
	{
		dstptr[i] = '\0';
		i++;
	}
	return ((char *)dstptr);
}
