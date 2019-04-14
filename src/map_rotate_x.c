/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:01:53 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:01:56 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_rotate_x(t_map *data)
{
	size_t	y;
	size_t	x;
	int		sy;
	int		sz;

	y = 0;
	while (y < data->count_y)
	{
		x = 0;
		while (x < data->count_x)
		{
			sy = data->map[y][x].ny;
			sz = data->map[y][x].nz;
			data->map[y][x].ny = round(CENTER_HEIGHT
				+ (sy - CENTER_HEIGHT) * ncos(data->angle_x)
				+ sz * nsin(data->angle_x));
			data->map[y][x].nz = round(-(sy - CENTER_HEIGHT)
				* nsin(data->angle_x) + sz * ncos(data->angle_x));
			x++;
		}
		y++;
	}
}
