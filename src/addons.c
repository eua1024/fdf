/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addons.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:46:18 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 18:46:31 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	ft_pow(size_t number, int pow)
{
	if (pow == 0)
		return (1);
	return (number * ft_pow(number, pow - 1));
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	malloc_h(void *msize)
{
	if (msize == NULL)
	{
		perror("Error");
		exit(1);
	}
}

float	ncos(int angle)
{
	return (cos(angle * RAD * ROTATE_SPEED));
}

float	nsin(int angle)
{
	return (sin(angle * RAD * ROTATE_SPEED));
}
