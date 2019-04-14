/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:01:33 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:01:35 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_print_text(t_map *data)
{
	map_string_put(20, "/, * - size z", data);
	map_string_put(40, "-, + - scale", data);
	map_string_put(60, "up, down - rotate by x", data);
	map_string_put(80, "left, right - rotate by y", data);
	map_string_put(100, "1, 2 - rotate by z", data);
	map_string_put(120, "0 - to start state", data);
}
