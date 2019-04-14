/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:32:42 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:32:43 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*str;
	size_t	i;
	char	*sptr;

	if (s == NULL)
		return (NULL);
	sptr = (char *)s;
	len = ft_strlen(sptr);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(sptr[i]);
		i++;
	}
	return (str);
}
