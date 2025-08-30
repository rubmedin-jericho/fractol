#ifndef FRACTOL_H
# define FRACTOL_H

//librerias
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
//libreria para borrar
# include <stdio.h>

//resolution
# define HEIGHT 1000
# define WIDTH 1000
//colors
# define RED 0x00FF0000
# define BLACK 0x000000
# define WHITE 0xFFFFFF
//teclas
# define ON_KEYDOWN  2
# define ON_KEYUP  3
# define ON_MOUSEDOWN  4
# define ON_MOUSEUP  5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE  12
# define DESTROY_NOTIFY  17
# define KEY_ESC 65307
# define KEY_MINUS 45
# define KEY_PLUS 61
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define FLAG_POS 1
# define FLAG_NEG -1
# define ZOOM 1.1

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

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
	char		*name_fractal;
	t_complex	z;
	t_complex	c;
	double		zoom;
	int			iterations;
	int			scape_var;

	//CENTER_OF_FRACTAL_IN_COMPLEX_MAP
	double		x_fract;
	double		y_fract;


	//WINDOW_FRACTAL
	void		*mlx;
	void		*mlx_win;

	//IMG_FRACTAL
	t_img		*img;
}				t_fractal;



void		init_img(t_fractal *fract);
int 		ft_strcmp(const char *s1, const char *s2);
int			Error_message(int flag);
void		init_window(t_fractal *fract);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		init_fractal_julia(t_fractal *fract, char *arg1, char *arg2);
void		init_fractal_mandelbrot(t_fractal *fractal);
int			event_destroyWindow(int keycode, t_fractal *fract);
void		init_events(t_fractal *fract);
int			notify_destroyWindow(t_fractal *fract);
void		render_mandelbrot(t_fractal *fract);
double		maping(double num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex real, t_complex imagine);
t_complex	square_complex(t_complex z);
//int			handleZoomIn(int keycode, t_fractal *fract);
#endif
