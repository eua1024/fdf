/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:46:57 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 18:47:02 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		if (((fd = open(argv[1], O_RDONLY)) < 0) || read(fd, 0, 0) == -1)
		{
			perror("Error");
			close(fd);
			return (0);
		}
		fdf(fd, argv[1]);
	}
	else
	{
		ft_putstr("usage: ./fdf [target to map]\n");
	}
	return (0);
}
