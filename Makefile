CC = cc
MLX_DIR = mlx_linux
MLX_LIB = mlx_linux/libmlx_Linux.a
CFLAGS = -Wall -Wextra -Werror -g -Imlx_liux -Imlx_linux -O3
MLXFLAGS = -Lmlx_Linux -L/usr/lib
LIBS = mlx_linux/libmlx_Linux.a -lXext -lX11 -lm -lz
NAME = fractol
HEADER = fractol.h
SRCS = fractol_main.c \
	   fractol_utils.c \
	   fractol_mlx.c \
	   fractol_set_julia.c \
	   fractol_set_mandelbrot.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) $(MlXFLAGS) $(LIBS) -o $(NAME)
	
$(MLX_LIB):
	make -C ./mlx_linux

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
