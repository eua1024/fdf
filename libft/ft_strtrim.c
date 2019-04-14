/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:35:20 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:35:20 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_witespace(const char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*str;
	char	*res;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	start = 0;
	end = ft_strlen(str);
	while (str[start] != '\0' && is_witespace(str[start]))
		start++;
	if (start == end)
		return (ft_strnew(0));
	end--;
	while (end != 0 && is_witespace(str[end]))
		end--;
	if ((res = ft_strsub(str, start, (end - start + 1))) == NULL)
		return (NULL);
	else
		return (res);
}
