/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_cols_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:00:54 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 19:00:58 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	get_map_cols_count(char ***src_map)
{
	size_t count_cols;

	count_cols = 0;
	while (src_map[0][count_cols])
		count_cols++;
	return (count_cols);
}
