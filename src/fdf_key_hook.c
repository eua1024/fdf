/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:47:12 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 18:47:15 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fdf_key_hook_part1(int keycode, t_map *data)
{
	if (keycode == KEY_PLUS)
		data->scale += 1;
	if (keycode == KEY_MINUS && data->scale > 1)
		data->scale -= 1;
	if (keycode == KEY_DIV)
		data->size_z = data->size_z - 0.1;
	if (keycode == KEY_MULT)
		data->size_z = data->size_z + 0.1;
	if (keycode == KEY_ARR_UP)
		data->angle_x--;
	if (keycode == KEY_ARR_DOWN)
		data->angle_x++;
	if (keycode == KEY_ARR_LEFT)
		data->angle_y--;
	if (keycode == KEY_ARR_RIGHT)
		data->angle_y++;
	if (keycode == KEY_1)
		data->angle_z--;
	if (keycode == KEY_2)
		data->angle_z++;
}

static void	fdf_key_hook_part2(int keycode, t_map *data)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_ZERO)
		map_start_state(data, data->count_y, data->count_x);
}

int			fdf_key_hook(int keycode, t_map *data)
{
	fdf_key_hook_part1(keycode, data);
	fdf_key_hook_part2(keycode, data);
	map_render(data);
	return (0);
}
