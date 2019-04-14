/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:27:18 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:27:21 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char		*str;
	int			digit;
	int			nsize;
	int			start;
	long int	nn;

	nn = n;
	nsize = ft_nbrsize(nn);
	if ((str = ft_strnew(nsize)) == NULL)
		return (NULL);
	start = 0;
	if (nn < 0)
	{
		nn = -nn;
		start = 1;
		str[0] = '-';
	}
	while (--nsize >= start)
	{
		digit = nn % 10;
		nn /= 10;
		str[nsize] = digit + '0';
	}
	return (str);
}
