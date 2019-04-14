/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:34:00 by efedoryc          #+#    #+#             */
/*   Updated: 2016/12/13 22:34:01 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**init_array(char const *str, char c)
{
	size_t	i;
	size_t	count;
	char	**str_array;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	if ((str_array = (char **)malloc(sizeof(char *) * count + 1)) != NULL)
		return (str_array);
	else
		return (NULL);
}

static char		**fill_array(char const *str, char c, char **str_array)
{
	size_t count;
	size_t i;
	size_t wsize;

	count = 0;
	i = 0;
	wsize = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			wsize++;
			if (str[i + 1] == c || str[i + 1] == '\0')
			{
				count++;
				str_array[count - 1] = ft_strsub(str, i - wsize + 1, wsize);
				wsize = 0;
			}
		}
		i++;
	}
	str_array[count] = NULL;
	return (str_array);
}

char			**ft_strsplit(char const *s, char c)
{
	char **str_array;

	if (s == NULL)
		return (NULL);
	if ((str_array = init_array(s, c)) != NULL)
		return (fill_array(s, c, str_array));
	else
		return (NULL);
}
