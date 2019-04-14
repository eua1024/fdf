/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:29:25 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:29:25 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*strptr;
	size_t			i;

	strptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*strptr == (unsigned char)c)
			return (strptr);
		strptr++;
		i++;
	}
	return (NULL);
}
