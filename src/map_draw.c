/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:01:16 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:01:19 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	map_draw_hor_line(t_map *data, t_currline *cl, size_t x, size_t y)
{
	cl->x_start = data->map[y][x].nx;
	cl->y_start = data->map[y][x].ny;
	cl->x_end = data->map[y][x + 1].nx;
	cl->y_end = data->map[y][x + 1].ny;
	cl->color = data->map[y][x].color;
	draw_line(cl, data);
}

static void	map_draw_vert_line(t_map *data, t_currline *cl, size_t x, size_t y)
{
	cl->x_start = data->map[y][x].nx;
	cl->y_start = data->map[y][x].ny;
	cl->x_end = data->map[y + 1][x].nx;
	cl->y_end = data->map[y + 1][x].ny;
	cl->color = data->map[y][x].color;
	draw_line(cl, data);
}

static void	map_draw_hor_endline(t_map *data, t_currline *cl)
{
	size_t y;
	size_t x;

	x = 0;
	y = data->count_y - 1;
	while (x < data->count_x - 1)
	{
		cl->x_start = data->map[y][x].nx;
		cl->y_start = data->map[y][x].ny;
		cl->x_end = data->map[y][x + 1].nx;
		cl->y_end = data->map[y][x + 1].ny;
		cl->color = data->map[y][x].color;
		draw_line(cl, data);
		x++;
	}
}

static void	map_draw_vert_endline(t_map *data, t_currline *cl)
{
	size_t y;
	size_t x;

	x = data->count_x - 1;
	y = 0;
	while (y < data->count_y - 1)
	{
		cl->x_start = data->map[y][x].nx;
		cl->y_start = data->map[y][x].ny;
		cl->x_end = data->map[y + 1][x].nx;
		cl->y_end = data->map[y + 1][x].ny;
		cl->color = data->map[y][x].color;
		draw_line(cl, data);
		y++;
	}
}

void		map_draw(t_map *data)
{
	size_t		y;
	size_t		x;
	t_currline	*cl;

	malloc_h((cl = (t_currline *)malloc(sizeof(t_currline))));
	y = 0;
	while (y < data->count_y - 1)
	{
		x = 0;
		while (x < data->count_x - 1)
		{
			map_draw_hor_line(data, cl, x, y);
			map_draw_vert_line(data, cl, x, y);
			x++;
		}
		y++;
	}
	map_draw_vert_endline(data, cl);
	map_draw_hor_endline(data, cl);
}
