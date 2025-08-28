/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:16:19 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/23 15:22:18 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_fractal *fract)
{
	fract->mlx_win = mlx_new_window(fract->mlx, HEIGHT, WIDTH, fract->name_fractal);
	if((*fract).mlx_win == NULL)
		exit(2);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x *(img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
