/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:03:47 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 13:18:55 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	notify_destroy_window(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	free(fract->img);
	free(fract);
	exit(0);
	return (0);
}

void	handle_reset(t_fractal *fract)
{
	clearWindow(fract);
	init_fractal_mandelbrot(fract);
	render_mandelbrot(fract);
}

void	handle_color(t_fractal *fract, int flag)
{
	clearWindow(fract);
	if (flag > 0)
		fract->change_color += 1;
	else if (flag < 0)
		fract->change_color -= 1;
	renderFractal(fract);
}

int	enable_random_color(int keycode, t_fractal *fract)
{
	(void)keycode;
	if (fract->random_color == 0.0)
		fract->random_color = 1.0;
	else
		fract->random_color = 0.0;
	return (0);
}

int	random_color(t_fractal *fract)
{
	if (fract->random_color == 1.0)
	{
		clearWindow(fract);
		fract->change_color += 1;
		renderFractal(fract);
	}
	if (fract->change_color == 100)
		fract->change_color = 0;
	return (0);
}
