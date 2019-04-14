/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:25:46 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 21:25:48 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_start_state(t_map *data, size_t count_y, size_t count_x)
{
	if ((WIN_WIDTH / count_x) < (WIN_HEIGHT / count_y))
		data->scale = WIN_WIDTH / count_x * 0.9;
	else
		data->scale = WIN_HEIGHT / count_y * 0.9;
	data->angle_x = ANGLE_X;
	data->angle_y = ANGLE_Y;
	data->angle_z = ANGLE_Z;
	data->size_z = SIZE_Z;
}
