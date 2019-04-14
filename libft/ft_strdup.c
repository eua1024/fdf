/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:58:33 by efedoryc          #+#    #+#             */
/*   Updated: 2016/11/22 17:58:36 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		count;
	char	*dest;

	count = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * count + 1);
	if (dest == 0)
		return (0);
	else
		ft_strcpy(dest, s1);
	return (dest);
}
