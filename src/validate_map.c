/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:22:48 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 23:22:51 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	validate_map(char ***src_map, size_t count_cols)
{
	size_t	curr_cols_count;
	size_t	y;

	if (count_cols == 0)
	{
		ft_putstr("Error: Map not valid\n");
		exit(1);
	}
	else
	{
		y = 0;
		while (src_map[y])
		{
			curr_cols_count = 0;
			while (src_map[y][curr_cols_count])
				curr_cols_count++;
			if (curr_cols_count != count_cols)
			{
				ft_putstr("Error: Map not valid\n");
				exit(1);
			}
			y++;
		}
	}
}
