/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:17:58 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 21:18:02 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf(int fd, char *filename)
{
	char		***src_map;
	t_point		**map;
	t_mapsize	*ms;
	t_map		*data;

	malloc_h((ms = (t_mapsize *)malloc(sizeof(t_mapsize))));
	if ((ms->count_rows = get_map_rows_count(fd)) <= 1)
	{
		ft_putstr("Error: Map not valid\n");
		exit(1);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	src_map = read_map(&src_map, ms->count_rows, fd);
	close(fd);
	if ((ms->count_cols = get_map_cols_count(src_map)) <= 1)
	{
		ft_putstr("Error: Map not valid\n");
		exit(1);
	}
	validate_map(src_map, ms->count_cols);
	map = map_standarter(src_map, ms->count_rows, ms->count_cols);
	map_init(&data, map, ms->count_rows, ms->count_cols);
	map_render(data);
	mlx_footer(data);
}
