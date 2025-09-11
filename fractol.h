/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:51:42 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:48:20 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*librerias*/
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include <stdio.h>
/*resolution*/
# define HEIGHT 1080
# define WIDTH 1080
/*colors*/
# define RED 0x00FF0000
# define BLACK 0x000000
# define WHITE 0xFFFFFF
/*teclas*/
# define DESTROY_NOTIFY  17
# define KEY_ESC 65307
# define KEY_MINUS 45
# define KEY_PLUS 61
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_R 114
# define FLAG_POS 1
# define FLAG_NEG -1
# define ZOOM 1.1
# define KEY_E 101
# define KEY_Q 113
# define KEY_W 119
# define KEY_MOUSE_UP 4
# define KEY_MOUSE_DOWN 5

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
	/*MATH_FRACTAL*/
	char		*name_fractal;
	t_complex	z;
	t_complex	c;
	double		zoom;
	int			iterations;
	int			scape_var;
	double		change_color;
	double		random_color;

	/*JULIA PARAMETERS*/
	t_complex	complex_jul;

	/*CENTER_OF_FRACTAL_IN_COMPLEX_MAP*/
	double		x_fract;
	double		y_fract;

	/*WINDOW_FRACTAL*/
	void		*mlx;
	void		*mlx_win;

	/*IMG_FRACTAL*/
	t_img		*img;
}				t_fractal;

void		render_fractal(t_fractal *fract);
double		ft_atof(const char *str, double fraction, double nbr, int div);
void		init_img(t_fractal *fract);
int			ft_strcmp(const char *s1, const char *s2);
int			error_message(void);
void		init_window(t_fractal *fract);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*SETS*/
void		init_fractal_julia(t_fractal *fract, char *arg1, char *arg2);
void		init_fractal_mandelbrot(t_fractal *fractal);
void		render_mandelbrot(t_fractal *fract);
void		render_julia(t_fractal *fract);

/*MATH*/
double		maping(double num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex real, t_complex imagine);
t_complex	square_complex(t_complex z);
void		clear_window(t_fractal *fract);
void		destroy_window(t_fractal *fract);

/*COLORS*/
int			enable_random_color(int keycode, t_fractal *fract);
int			random_color(t_fractal *fract);
void		handle_color(t_fractal *fract, int flag);

/*EVENTS*/
int			event_destroy_window(int keycode, t_fractal *fract);
void		init_events(t_fractal *fract);
int			handle_events(int keycode, t_fractal *fract);
void		handle_reset(t_fractal *fract);
void		handle_move(t_fractal *fract, int keycode);
void		handle_zoomIn(t_fractal *fract, int flag);
int			handle_mouse_events(int keycode, int x, int y, t_fractal *fract);
int			notify_destroy_window(t_fractal *fract);
#endif
