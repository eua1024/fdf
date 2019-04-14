/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:32:24 by efedoryc          #+#    #+#             */
/*   Updated: 2017/03/13 19:32:26 by efedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libft/libft.h"

# define PI 3.14159265358979323846
# define RAD PI / 180

# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_DIV 75
# define KEY_MULT 67

# define KEY_ARR_LEFT 123
# define KEY_ARR_RIGHT 124
# define KEY_ARR_UP 126
# define KEY_ARR_DOWN 125
# define KEY_ZERO 82
# define KEY_1 83
# define KEY_2 84

# define WIN_TITLE "mlx42"
# define WIN_WIDTH 1300
# define WIN_HEIGHT 1000

# define START_POINT_Y 200
# define START_POINT_X 200

# define ANGLE_X -37
# define ANGLE_Y -34
# define ANGLE_Z 39
# define SIZE_Z 0.1
# define ROTATE_SPEED 1

# define CENTER_WIDTH round(WIN_WIDTH / 2)
# define CENTER_HEIGHT round(WIN_HEIGHT / 2)

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_point
{
	int			sx;
	int			sy;
	char		*char_z;
	int			sz;
	size_t		color;
	int			nx;
	int			ny;
	int			nz;
}				t_point;

typedef struct	s_dline
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			err2;
}				t_dline;

typedef struct	s_currline
{
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
	size_t		color;
}				t_currline;

typedef struct	s_mapsize
{
	size_t		count_rows;
	size_t		count_cols;
}				t_mapsize;

typedef struct	s_map
{
	t_point		**map;
	size_t		count_x;
	size_t		count_y;
	int			scale;
	int			angle_y;
	int			angle_x;
	int			angle_z;
	float		size_z;
	int			rotate_speed;
	t_env		e;
}				t_map;

void			fdf(int fd, char *filename);
char			***read_map(char ****src_map, size_t count_rows, int fd);
t_point			**map_standarter(char ***src_map, size_t count_rows, \
	size_t	count_cols);
size_t			get_map_rows_count(int fd);
size_t			get_map_cols_count(char ***src_map);
void			validate_map(char ***src_map, size_t count_cols);
void			map_string_put(size_t y, char *string, t_map *data);
void			map_init(t_map **data, t_point **map, size_t count_y, \
	size_t count_x);
void			map_start_state(t_map *data, size_t count_y, size_t count_x);
void			map_scale(t_map *data);
void			map_draw(t_map *data);
void			map_rotate_y(t_map *data);
void			map_rotate_x(t_map *data);
void			map_rotate_z(t_map *data);
void			map_print_text(t_map *data);
void			map_clear(t_map *data);
void			map_render(t_map *data);
void			draw_line(t_currline *cline, t_map *data);
size_t			ft_pow(size_t number, int pow);
int				exit_x(void *par);
int				mouse_hook(int button, int x, int y, t_env *e);
int				ft_is_hexchar(char c);
void			malloc_h(void *msize);
float			ncos(int angle);
float			nsin(int angle);
size_t			get_color(char *raw_text);
int				fdf_key_hook(int keycode, t_map *data);
void			mlx_footer(t_map *data);

#endif
