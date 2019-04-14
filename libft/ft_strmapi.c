/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:32:50 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:32:50 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[i] = f(i, sptr[i]);
		i++;
	}
	return (str);
}
