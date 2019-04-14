/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:25:05 by efedoryc          #+#    #+#             */
/*   Updated: 2017/03/07 21:25:10 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lines	*ft_get_safe(t_lines *list, const int fd)
{
	t_lines *chain;

	chain = list;
	while (chain)
	{
		if (chain->fd == fd)
			return (chain);
		else
			chain = chain->next;
	}
	return (NULL);
}

static void		ft_get_current_safe(t_lines **curr_safe,
				t_lines **safe, const int fd)
{
	if (*safe == NULL)
	{
		*safe = (t_lines *)malloc(sizeof(t_lines));
		(*safe)->rest = ft_strnew(BUFF_SIZE);
		(*safe)->rest_start = (*safe)->rest;
		(*safe)->fd = fd;
		(*safe)->next = NULL;
		*curr_safe = *safe;
	}
	else
	{
		if ((*curr_safe = ft_get_safe(*safe, fd)) == NULL)
		{
			(*safe)->next = (t_lines *)malloc(sizeof(t_lines));
			(*safe)->next->rest = ft_strnew(BUFF_SIZE);
			(*safe)->next->rest_start = (*safe)->next->rest;
			(*safe)->next->fd = fd;
			(*safe)->next->next = NULL;
			*curr_safe = (*safe)->next;
		}
	}
}

static char		*ft_gnl_strjoin(char **line, char *line_trail)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, line_trail);
	free(tmp);
	free(line_trail);
	return (*line);
}

static int		ft_str_handler(char *buf, char **rest, char **line)
{
	char	*line_trail;
	size_t	i;

	line_trail = ft_strnew(BUFF_SIZE);
	ft_bzero(line_trail, BUFF_SIZE + 1);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			(*rest)++;
			ft_gnl_strjoin(line, line_trail);
			return (1);
		}
		else
		{
			line_trail[i] = buf[i];
			i++;
			(*rest)++;
		}
	}
	ft_gnl_strjoin(line, line_trail);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	int				rd;
	static t_lines	*safe;
	t_lines			*curr_safe;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	ft_bzero(buf, BUFF_SIZE + 1);
	*line = ft_strnew(0);
	ft_get_current_safe(&curr_safe, &safe, fd);
	curr_safe->rest_start = curr_safe->rest;
	if (ft_str_handler(curr_safe->rest_start, &(curr_safe->rest), line))
		return (1);
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		if (rd == -1)
			return (-1);
		curr_safe->rest = buf;
		if (ft_str_handler(buf, &(curr_safe->rest), line))
			return (1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (*line[0] != '\0');
}
