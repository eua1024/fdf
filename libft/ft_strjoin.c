/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:32:30 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:32:30 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1ptr;
	char	*s2ptr;
	char	*str;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1ptr = (char *)s1;
	s2ptr = (char *)s2;
	if ((str = ft_strnew(ft_strlen(s1ptr) + ft_strlen(s2ptr))) == NULL)
		return (NULL);
	i = 0;
	while (*s1ptr != '\0')
	{
		str[i++] = *s1ptr;
		s1ptr++;
	}
	while (*s2ptr != '\0')
	{
		str[i++] = *s2ptr;
		s2ptr++;
	}
	return (str);
}
