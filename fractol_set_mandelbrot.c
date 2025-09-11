/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_set_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:52:17 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:27:49 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_mandelbrot(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	init_img(fract);
	fract->name_fractal = "mandelbrot";
	fract->x_fract = 0.0;
	fract->y_fract = 0.0;
	fract->scape_var = 4;
	fract->iterations = 42;
	fract->zoom = 1.0;
	fract->change_color = 0.0;
	fract->random_color = 0.0;
}

static void	handel_pixel_mandelbrot(int y, int x, t_fractal *fract)
{
	int	i;
	int	color;

	i = 0;
	fract->z.re = 0.0;
	fract->z.im = 0.0;
	fract->c.re = (maping(x, -2, 2, WIDTH) / fract->zoom) + fract->x_fract;
	fract->c.im = (maping(y, 2, -2, HEIGHT) / fract->zoom) + fract->y_fract;
	while (i < fract->iterations)
	{
		fract->z = sum_complex(square_complex(fract->z), fract->c);
		if ((fract->z.re * fract->z.re) + (fract->z.im * fract->z.im)
			> fract->scape_var)
		{
			color = maping(i, BLACK, RED, (42 + fract->change_color));
			my_mlx_pixel_put(fract->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(fract->img, x, y, BLACK);
}

void	render_mandelbrot(t_fractal *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handel_pixel_mandelbrot(y, x, fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win,
		fract->img->img_p, 0, 0);
}
