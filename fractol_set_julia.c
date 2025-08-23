/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_set_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:51:35 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/23 18:52:04 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_julia(t_fractal *fract, char *arg1, char *arg2)
{
	(void)arg1;
	(void)arg2;
	fract->mlx = mlx_init();
	fract->img = malloc(sizeof(t_img));
	(*fract).img->img_p = mlx_new_image(fract->mlx, (HEIGHT * 2), (WEIGHT * 2));
	(*fract).img->addr = mlx_get_data_addr((*fract).img->img_p, \
			&(*fract).img->bits_per_pixel, &(*fract).img->line_length, \
			&(*fract).img->endian);
	fract->name_fractal = "julia";
}
