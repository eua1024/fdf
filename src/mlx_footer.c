/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_footer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:02:38 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:02:41 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_footer(t_map *data)
{
	mlx_hook(data->e.win, 2, 5, fdf_key_hook, data);
	mlx_hook(data->e.win, 17, 1L << 17, exit_x, &(data->e));
	mlx_loop(data->e.mlx);
}
