/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:57:29 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/27 18:57:38 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	notify_destroyWindow(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	exit(0);
	return (0);
}

void	handleZoomIn(t_fractal *fract, int flag)
{
	clearWindow(fract); if (flag > 0)
	{
		fract->zoom = fract->zoom / ZOOM;
		if(fract->zoom > 1)
			fract->iterations -= 1.00;
	}
	else if (flag < 0)
	{
		fract->zoom = fract->zoom * ZOOM;
		fract->iterations += 1.00;
	}
	render_mandelbrot(fract);
}

void	handleMove(t_fractal *fract, int keycode)
{
	clearWindow(fract);
	if (keycode == KEY_UP)
		fract->y_fract += (0.5 / fract->zoom);
	if (keycode == KEY_LEFT)
		fract->x_fract -= (0.5 / fract->zoom);
	if (keycode == KEY_DOWN)
		fract->y_fract -= (0.5 / fract->zoom);
	if (keycode == KEY_RIGHT)
		fract->x_fract += (0.5 / fract->zoom);
	render_mandelbrot(fract);
}

void	handleReset(t_fractal *fract)
{
	clearWindow(fract);
	init_fractal_mandelbrot(fract);
	render_mandelbrot(fract);
}

void	handleColor(t_fractal *fract, int flag)
{
	clearWindow(fract);
	if (flag > 0)
		fract->change_color += 1;
	else if (flag < 0)
		fract->change_color -= 1;
	render_mandelbrot(fract);
}

int	 enableRandomColor(int keycode, t_fractal *fract)
{
	(void)keycode;
	if (fract->img->random_color == 0.0)
		fract->img->random_color = 1.0;
	else
		fract->img->random_color = 0.0;
	return (0);
}

int	RandomColor(t_fractal *fract)
{
	if(fract->img->random_color == 1.0)
	{
		clearWindow(fract);
		fract->change_color += 1;
		render_mandelbrot(fract);
	}
	if(fract->change_color == 100)
		fract->change_color = 0;
	return (0);
}

int	handleEvents(int keycode, t_fractal *fract)
{
	if (keycode == KEY_UP || keycode == KEY_RIGHT || \
		keycode == KEY_DOWN || keycode == KEY_LEFT)
		handleMove(fract, keycode);
	else if (keycode == KEY_ESC)
		destroyWindow(fract);
	else if (keycode == KEY_MINUS)
		handleZoomIn(fract, FLAG_POS);
	else if (keycode == KEY_PLUS)
		handleZoomIn(fract, FLAG_NEG);
	if (keycode == KEY_R && \
		!ft_strcmp(fract->name_fractal, "mandelbrot"))
		handleReset(fract);
	if (keycode == KEY_E)
		handleColor(fract, 1);
	if (keycode == KEY_Q)
		handleColor(fract, -1);
	if (keycode == KEY_W)
		enableRandomColor(keycode, fract);
	return (0);
}

void	init_events(t_fractal *fract)
{
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, handleEvents, fract);
	mlx_loop_hook(fract->mlx, RandomColor, fract);
	mlx_hook(fract->mlx_win, DESTROY_NOTIFY, 0, notify_destroyWindow, fract);
}
