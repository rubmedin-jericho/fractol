/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:30:46 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:47:53 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_img(t_fractal *fract)
{
	fract->img = malloc(sizeof(t_img));
	if (!fract->img)
		exit(1);
	(*fract).img->img_p = mlx_new_image(fract->mlx, HEIGHT, WIDTH);
	(*fract).img->addr = mlx_get_data_addr((*fract).img->img_p, \
			&(*fract).img->bits_per_pixel, &(*fract).img->line_length, \
			&(*fract).img->endian);
}

void	destroy_window(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	exit(0);
}

void	clear_window(t_fractal *fract)
{
	if (fract->img)
	{
		if (fract->img->img_p)
			mlx_destroy_image(fract->mlx, fract->img->img_p);
		free(fract->img);
		fract->img = NULL;
	}
	init_img(fract);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	error_message(void)
{
	size_t	ret;

	ret = write(2, "./fractol mandelbrot\n./fractol julia 0.279 0\n", 46);
	return (ret);
}
