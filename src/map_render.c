/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:01:41 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:01:43 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_render(t_map *data)
{
	map_clear(data);
	map_scale(data);
	map_rotate_x(data);
	map_rotate_y(data);
	map_rotate_z(data);
	map_draw(data);
	map_print_text(data);
}
