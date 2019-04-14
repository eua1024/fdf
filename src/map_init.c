/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:01:25 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:01:28 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_init(t_map **data, t_point **map, size_t count_y, size_t count_x)
{
	malloc_h((*data = (t_map*)malloc(sizeof(t_map))));
	(*data)->map = map;
	(*data)->count_y = count_y;
	(*data)->count_x = count_x;
	map_start_state(*data, (*data)->count_y, (*data)->count_x);
	(*data)->e.mlx = mlx_init();
	(*data)->e.win = mlx_new_window((*data)->e.mlx,
		WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
}
