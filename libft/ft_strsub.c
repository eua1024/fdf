/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:34:44 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:34:45 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((str = ft_strnew(len)) != NULL)
	{
		i = 0;
		while (len > 0)
		{
			str[i] = s[start + i];
			i++;
			len--;
		}
		return (str);
	}
	else
	{
		return (NULL);
	}
}
