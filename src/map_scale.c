/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:02:18 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:02:19 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_scale(t_map *data)
{
	size_t y;
	size_t x;

	y = 0;
	while (y < data->count_y)
	{
		x = 0;
		while (x < data->count_x)
		{
			data->map[y][x].ny = (data->map[y][x].sy * data->scale)
				+ (CENTER_HEIGHT - round(data->count_y / 2) * data->scale);
			data->map[y][x].nx = (data->map[y][x].sx * data->scale)
				+ (CENTER_WIDTH - round(data->count_x / 2) * data->scale);
			data->map[y][x].nz = (data->map[y][x].sz)
				* data->scale * data->size_z;
			x++;
		}
		y++;
	}
}
