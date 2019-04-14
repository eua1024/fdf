/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:30:29 by efedoryc          #+#    #+#             */
/*   Updated: 2016/11/21 16:30:32 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1p;
	unsigned char	*s2p;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	i = 0;
	while (s1p[i] != '\0' || s2p[i] != '\0')
	{
		if (s1p[i] == s2p[i])
			i++;
		else
			return (s1p[i] - s2p[i]);
	}
	return (0);
}
