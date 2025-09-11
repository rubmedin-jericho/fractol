/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_set_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:51:35 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 13:45:09 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_julia(t_fractal *fract, char *arg1, char *arg2)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	init_img(fract);
	fract->name_fractal = "julia";
	fract->x_fract = 0.0;
	fract->y_fract = 0.0;
	fract->scape_var = 4;
	fract->iterations = 42;
	fract->zoom = 1.0;
	fract->change_color = 0.0;
	fract->random_color = 0.0;
	fract->c.re = ft_atof(arg1, 0.0, 0.0, 1);
	fract->c.im = ft_atof(arg2, 0.0, 0.0, 1);
}

static void	handel_pixel_julia(int y, int x, t_fractal *fract)
{
	int	i;
	int	color;

	i = 0;
	fract->z.re = (maping(x, -2, 2, WIDTH) / fract->zoom) + fract->x_fract;
	fract->z.im = (maping(y, 2, -2, HEIGHT) / fract->zoom) + fract->y_fract;
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

void	render_julia(t_fractal *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handel_pixel_julia(y, x, fract);
	}
	mlx_put_image_to_window(fract->mlx,
		fract->mlx_win, fract->img->img_p, 0, 0);
}

void	render_fractal(t_fractal *fract)
{
	if (!ft_strcmp(fract->name_fractal, "mandelbrot"))
		render_mandelbrot(fract);
	else if (!ft_strcmp(fract->name_fractal, "julia"))
		render_julia(fract);
}
