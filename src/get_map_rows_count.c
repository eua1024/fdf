/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_rows_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:01:04 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:01:06 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	get_map_rows_count(int fd)
{
	size_t	count_rows;
	int		gnl;
	char	*line;

	count_rows = 0;
	while ((gnl = get_next_line(fd, &line)))
		count_rows++;
	return (count_rows);
}
