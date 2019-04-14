/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:52:17 by efedoryc          #+#    #+#             */
/*   Updated: 2017/06/02 18:52:20 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		upper_case_and_valid(char **str, size_t *end_index)
{
	while ((*str)[*end_index])
	{
		(*str)[*end_index] = ft_toupper((*str)[*end_index]);
		if (!ft_is_hexchar((*str)[*end_index]))
		{
			ft_putstr("Error: Color in map not valid\n");
			exit(1);
		}
		(*end_index)++;
	}
}

static size_t	str_to_intcolor(char *str, size_t end_index)
{
	size_t	color;
	size_t	pow;

	pow = 0;
	end_index--;
	color = 0;
	while (str[end_index] != 'x')
	{
		if (ft_isdigit(str[end_index]))
			color += (str[end_index] - 48) * ft_pow(16, pow);
		if (str[end_index] >= 'A' && str[end_index] <= 'F')
			color += (str[end_index] - 55) * ft_pow(16, pow);
		pow++;
		end_index--;
	}
	return (color);
}

size_t			get_color(char *raw_text)
{
	char	*color_text;
	size_t	end_index;

	color_text = ft_strstr(raw_text, ",0x");
	if (color_text)
	{
		color_text = color_text + 3;
		end_index = 0;
		upper_case_and_valid(&color_text, &end_index);
		return (str_to_intcolor(color_text, end_index));
	}
	else
	{
		return (0x00FFFFFF);
	}
}
