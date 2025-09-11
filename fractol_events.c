/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:57:29 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 13:20:11 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_zoom_in(t_fractal *fract, int flag)
{
	clearWindow(fract);
	if (flag > 0)
	{
		fract->zoom = fract->zoom / ZOOM;
		if (fract->zoom > 1)
			fract->iterations -= 1.00;
	}
	else if (flag < 0)
	{
		fract->zoom = fract->zoom * ZOOM;
		fract->iterations += 1.00;
	}
	renderFractal(fract);
}

void	handle_move(t_fractal *fract, int keycode)
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
	renderFractal(fract);
}

int	handle_events(int keycode, t_fractal *fract)
{
	if (keycode == KEY_UP || keycode == KEY_RIGHT || \
		keycode == KEY_DOWN || keycode == KEY_LEFT)
		handleMove(fract, keycode);
	if (keycode == KEY_ESC)
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

int	handle_mouse_events(int keycode, int x, int y, t_fractal *fract)
{
	(void)x;
	(void)y;
	if (keycode == KEY_MOUSE_UP)
		handleZoomIn(fract, FLAG_NEG);
	if (keycode == KEY_MOUSE_DOWN)
		handleZoomIn(fract, FLAG_POS);
	return (0);
}

void	init_events(t_fractal *fract)
{
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, handleEvents, fract);
	mlx_loop_hook(fract->mlx, RandomColor, fract);
	mlx_hook(fract->mlx_win, ButtonPress, ButtonPressMask,
		handleMouseEvents, fract);
	mlx_hook(fract->mlx_win, DESTROY_NOTIFY, 0, notify_destroyWindow, fract);
}
