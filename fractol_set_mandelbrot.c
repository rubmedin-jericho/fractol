/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_set_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:52:17 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/23 18:52:26 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_mandelbrot(t_fractal *fract)
{
	fract->mlx = mlx_init();
	init_img(fract);
	fract->name_fractal = "mandelbrot";
	fract->x_fract = 0.0;
	fract->y_fract = 0.0;
	fract->scape_var = 4;
	fract->iterations = 42;
	fract->zoom = 1.0;
	
}

static void	handelPixel(int y, int x, t_fractal *fract)
{
	int	i;

	i = 0;
	int	color;
double x_mapped = maping(x, -2, 2, WIDTH);
double y_mapped = maping(y, -2, 2, HEIGHT);

fract->c.re = fract->x_fract + (x_mapped - fract->x_fract) / fract->zoom;
fract->c.im = fract->y_fract + (y_mapped - fract->y_fract) / fract->zoom;
	fract->z.re = 0.0;
	fract->z.im = 0.0;
//	fract->c.re = (maping( x, -2, 2, WIDTH) * fract->zoom) + fract->x_fract;
//	fract->c.im = (maping( y, 2, -2, HEIGHT) * fract->zoom) + fract->y_fract;
	while(i < fract->iterations)
	{
		fract->z = sum_complex(square_complex(fract->z),fract->c);
		if ((fract->z.re * fract->z.re) + (fract->z.im * fract->z.im) > fract->scape_var)
		{
			color = maping(i, BLACK, WHITE, fract->iterations);
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
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
			handelPixel(y, x, fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->img->img_p, 0, 0);
}
