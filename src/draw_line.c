/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:46:43 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 18:46:45 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_currline *cline, t_map *data)
{
	t_dline dline;

	dline.dx = abs(cline->x_end - cline->x_start);
	dline.sx = cline->x_start < cline->x_end ? 1 : -1;
	dline.dy = -abs(cline->y_end - cline->y_start);
	dline.sy = cline->y_start < cline->y_end ? 1 : -1;
	dline.err = dline.dx + dline.dy;
	while (1)
	{
		mlx_pixel_put(data->e.mlx, data->e.win, cline->x_start,
			cline->y_start, cline->color);
		if (cline->x_start == cline->x_end && cline->y_start == cline->y_end)
			break ;
		dline.err2 = 2 * dline.err;
		if (dline.err2 > dline.dy)
		{
			dline.err += dline.dy;
			cline->x_start += dline.sx;
		}
		if (dline.err2 < dline.dx)
		{
			dline.err += dline.dx;
			cline->y_start += dline.sy;
		}
	}
}
