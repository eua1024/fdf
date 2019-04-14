/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:02:55 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:02:58 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	***read_map(char ****src_map, size_t count_rows, int fd)
{
	int		gnl;
	char	*line;
	size_t	i;

	malloc_h((*src_map = (char ***)malloc(sizeof(char **) * count_rows + 1)));
	i = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
		malloc_h(((*src_map)[i] = ft_strsplit(line, ' ')));
		i++;
	}
	(*src_map)[count_rows] = NULL;
	ft_strdel(&line);
	return (*src_map);
}
