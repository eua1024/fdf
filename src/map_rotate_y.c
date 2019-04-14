/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:02:02 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:02:04 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_rotate_y(t_map *data)
{
	size_t	y;
	size_t	x;
	int		sx;
	int		sz;

	y = 0;
	while (y < data->count_y)
	{
		x = 0;
		while (x < data->count_x)
		{
			sx = data->map[y][x].nx;
			sz = data->map[y][x].nz;
			data->map[y][x].nx = round(CENTER_WIDTH
				+ (sx - CENTER_WIDTH) * ncos(data->angle_y)
				+ sz * nsin(data->angle_y));
			data->map[y][x].nz = round(CENTER_WIDTH
				+ (-sx - CENTER_WIDTH) * nsin(data->angle_y)
				+ sz * ncos(data->angle_y));
			x++;
		}
		y++;
	}
}
