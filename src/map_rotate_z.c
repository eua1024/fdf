/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:02:08 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:02:11 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_rotate_z(t_map *data)
{
	size_t	y;
	size_t	x;
	int		sx;
	int		sy;

	y = 0;
	while (y < data->count_y)
	{
		x = 0;
		while (x < data->count_x)
		{
			sx = data->map[y][x].nx;
			sy = data->map[y][x].ny;
			data->map[y][x].nx = round(CENTER_WIDTH
				+ (sx - CENTER_WIDTH) * ncos(data->angle_z)
				- (sy - CENTER_HEIGHT) * nsin(data->angle_z));
			data->map[y][x].ny = round(CENTER_HEIGHT
				+ (sx - CENTER_WIDTH) * nsin(data->angle_z)
				+ (sy - CENTER_HEIGHT) * ncos(data->angle_z));
			x++;
		}
		y++;
	}
}
