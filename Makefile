#CC = cc
CC = gcc
MLX_DIR = mlx_linux
MLX_LIB = mlx_linux/libmlx_Linux.a
#CFLAGS = -Wall -Wextra -Werror -g -Imlx_liux -Imlx_linux -O3
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -funroll-loops -flto -fomit-frame-pointer
MLXFLAGS = -Lmlx_Linux -L/usr/lib
LIBS = mlx_linux/libmlx_Linux.a -lXext -lX11 -lm -lz
NAME = fractol
HEADER = fractol.h
SRCS = fractol_main.c \
	   fractol_utils.c \
	   fractol_mlx.c \
	   fractol_set_julia.c \
	   fractol_math.c \
	   fractol_events.c \
	   fractol_utils_2.c \
	   fractol_events_2.c \
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
