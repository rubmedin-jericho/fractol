/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:57:29 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:32:23 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_zoom_in(t_fractal *fract, int flag)
{
	clear_window(fract);
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
	render_fractal(fract);
}

void	handle_move(t_fractal *fract, int keycode)
{
	clear_window(fract);
	if (keycode == KEY_UP)
		fract->y_fract += (0.5 / fract->zoom);
	if (keycode == KEY_LEFT)
		fract->x_fract -= (0.5 / fract->zoom);
	if (keycode == KEY_DOWN)
		fract->y_fract -= (0.5 / fract->zoom);
	if (keycode == KEY_RIGHT)
		fract->x_fract += (0.5 / fract->zoom);
	render_fractal(fract);
}

int	handle_events(int keycode, t_fractal *fract)
{
	if (keycode == KEY_UP || keycode == KEY_RIGHT || \
		keycode == KEY_DOWN || keycode == KEY_LEFT)
		handle_move(fract, keycode);
	if (keycode == KEY_ESC)
		destroy_window(fract);
	else if (keycode == KEY_MINUS)
		handle_zoom_in(fract, FLAG_POS);
	else if (keycode == KEY_PLUS)
		handle_zoom_in(fract, FLAG_NEG);
	if (keycode == KEY_R && \
		!ft_strcmp(fract->name_fractal, "mandelbrot"))
		handle_reset(fract);
	if (keycode == KEY_E)
		handle_color(fract, 1);
	if (keycode == KEY_Q)
		handle_color(fract, -1);
	if (keycode == KEY_W)
		enable_random_color(keycode, fract);
	return (0);
}

int	handle_mouse_events(int keycode, int x, int y, t_fractal *fract)
{
	(void)x;
	(void)y;
	if (keycode == KEY_MOUSE_UP)
		handle_zoom_in(fract, FLAG_NEG);
	if (keycode == KEY_MOUSE_DOWN)
		handle_zoom_in(fract, FLAG_POS);
	return (0);
}

void	init_events(t_fractal *fract)
{
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, handle_events, fract);
	mlx_loop_hook(fract->mlx, random_color, fract);
	mlx_hook(fract->mlx_win, ButtonPress, ButtonPressMask,
		handle_mouse_events, fract);
	mlx_hook(fract->mlx_win, DESTROY_NOTIFY, 0, notify_destroy_window, fract);
}
