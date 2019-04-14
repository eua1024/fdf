/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:05:34 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/01 20:05:37 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;
	size_t i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	if (dstlen >= size)
		return (srclen + size);
	else
	{
		i = 0;
		while (src[i] != '\0' && i < (size - dstlen - 1))
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
		return (dstlen + srclen);
	}
}
