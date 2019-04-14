#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efedoryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/06 20:00:13 by efedoryc          #+#    #+#              #
#    Updated: 2017/06/06 20:00:18 by efedoryc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
WWW = -Wall -Wextra -Werror -fPIC
FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit
LIBRARI = libft/libft.a
FDF_PATH = ./src
FILE_SRC = 	addons.c \
			draw_line.c \
			fdf.c \
			fdf_key_hook.c \
			ft_is_hexchar.c \
			get_color.c \
			get_map_cols_count.c \
			get_map_rows_count.c \
			main.c \
			map_clear.c \
			map_draw.c \
			map_init.c \
			map_print_text.c \
			map_render.c \
			map_rotate_x.c \
			map_rotate_y.c \
			map_rotate_z.c \
			map_scale.c \
			map_standarter.c \
			map_start_state.c \
			map_string_put.c \
			mlx_footer.c \
			read_map.c \
			validate_map.c

FULL_SRC = $(patsubst %.c, $(FDF_PATH)/%.c, $(FILE_SRC))
OBJ = $(patsubst %.c, %.o, $(FDF_PATH)/$(FILE_SRC))

.PHONY: all makelib libclean libfclean clean fclean re

all: makelib $(NAME)

makelib:
		@ make -C libft/
libclean:
		@ make -C libft/ clean
libfclean:
		@ make -C libft/ fclean
$(NAME):
		@ gcc -o $(NAME) $(FULL_SRC) $(WWW) $(FLAGS_MLX) $(LIBRARI)

%.o: $(FDF_PATH)/%.c
	@ gcc $(FLAGS) -c -o $@ $<

clean: libclean
		@ rm -f $(OBJ)
fclean: libfclean clean
		@ rm -f $(NAME)
re: fclean all
