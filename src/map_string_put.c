/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_string_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:46:07 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/06 19:46:10 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_string_put(size_t y, char *string, t_map *data)
{
	mlx_string_put(data->e.mlx, data->e.win, 20, y, 0x00FFFFFFF, string);
}
