#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# define HEIGHT 1000
# define WEIGHT 1000
# define RED 0x00FF0000

typedef struct s_img 
{
	void	*img_p;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	//MATH_FRACTAL
	char	*name_fractal;
	int		x;
	int		y;
	//WINDOW_FRACTAL
	void	*mlx;
	void	*mlx_win;
	//IMG_FRACTAL
	t_img	*img;
}			t_fractal;

int ft_strcmp(const char *s1, const char *s2);
int	Error_message(int flag);
void	init_window(t_fractal *fract);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_fractal_julia(t_fractal *fract, char *arg1, char *arg2);
void	init_fractal_mandelbrot(t_fractal *fractal);
#endif
