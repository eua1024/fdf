/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_standarter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:02:27 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:02:30 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	tree_zero(int *one, int *two, int *three)
{
	*one = 0;
	*two = 0;
	*three = 0;
}

t_point		**map_standarter(char ***src_map, size_t count_rows,
	size_t count_cols)
{
	t_point	**map;
	size_t	x;
	size_t	y;

	malloc_h((map = (t_point **)malloc(sizeof(t_point *) * count_rows)));
	y = 0;
	while (src_map[y])
	{
		malloc_h((map[y] = (t_point *)malloc(sizeof(t_point) * count_cols)));
		x = 0;
		while (src_map[y][x])
		{
			map[y][x].sx = x;
			map[y][x].sy = y;
			map[y][x].char_z = src_map[y][x];
			map[y][x].sz = ft_atoi(src_map[y][x]);
			map[y][x].color = get_color(map[y][x].char_z);
			tree_zero(&map[y][x].nx, &map[y][x].ny, &map[y][x].nz);
			x++;
		}
		y++;
	}
	map[count_rows] = NULL;
	return (map);
}
