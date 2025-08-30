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

void destroyWindow(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	exit(0);
}

void	clearWindow(t_fractal *fract)
{
	free(fract->img);
	init_img(fract);
}

void	handleZoomIn(t_fractal *fract, int flag)
{
	clearWindow(fract);
	if (flag < 0)
	{
		fract->zoom = fract->zoom / ZOOM;
		printf("ZOOM: %f\n", fract->zoom);
		fract->iterations /= 0.5;
	}
	else if (flag > 0)
	{
		fract->zoom = fract->zoom * ZOOM;
		printf("ZOOM: %f\n", fract->zoom);
		fract->iterations *= 0.5;
	}
	render_mandelbrot(fract);
}

void	handleMove(t_fractal *fract, int keycode)
{
	clearWindow(fract);
	if (keycode == KEY_UP)
		fract->y_fract += 0.5;
	else if (keycode == KEY_LEFT)
		fract->x_fract -= 0.5;
	else if (keycode == KEY_DOWN)
		fract->y_fract -= 0.5;
	else if (keycode == KEY_RIGHT)
		fract->x_fract += 0.5;
	render_mandelbrot(fract);
}

int	handleEvents(int keycode, t_fractal *fract)
{
	if (keycode == KEY_UP)
		handleMove(fract, KEY_UP);
	else if (keycode == KEY_LEFT)
		handleMove(fract, KEY_LEFT);
	else if (keycode == KEY_DOWN)
		handleMove(fract, KEY_DOWN);
	else if (keycode == KEY_RIGHT)
		handleMove(fract, KEY_RIGHT);
	else if (keycode == KEY_ESC)
		destroyWindow(fract);
	else if (keycode == KEY_MINUS)
		handleZoomIn(fract, FLAG_POS);
	else if (keycode == KEY_PLUS)
		handleZoomIn(fract, FLAG_NEG);
	return (0);
}

void	init_events(t_fractal *fract)
{
	mlx_hook(fract->mlx_win, 2, 1L << 0, handleEvents, fract);
	mlx_hook(fract->mlx_win, DESTROY_NOTIFY, 0, notify_destroyWindow, fract);
}
