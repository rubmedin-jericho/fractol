/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:30:46 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 16:21:18 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



double	ft_atof(const char *str, double fraction, double nbr, int div)
{
	int	sign;
	int	limit;

	limit = 0;
	sign = 1;
	if(*str++ == '-')
		sign = -1;
	while(*str >= '0' && *str <= '9')
		nbr = (nbr * 10) + (*str++ - '0');
	if(*str == '.')
	{
		while(*++str >= '0' && *str <= '9' && limit++ < 6)
		{
			fraction = fraction * 10 + (*str++ - '0');
			div *= 10;
		}
		nbr += fraction / div;
	}
	return (nbr * sign);
}

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

void destroyWindow(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	exit(0);
}

void	clearWindow(t_fractal *fract)
{
    if (fract->img)
    {
        if (fract->img->img_p)
            mlx_destroy_image(fract->mlx, fract->img->img_p);
        free(fract->img);
        fract->img = NULL; // ← buena práctica
    }
    init_img(fract);
}

int	ft_strcmp(const char *s1, const char *s2)
{
    int i;
    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return s1[i] - s2[i];
}

int	Error_message(int flag)
{
	ssize_t ret;
	if (flag == 0)
	{
		ret = write(2, "Error parameters try:\n--------------------------------------\
---\n|					|\n|	./fractol mandelbrot		|\n\
|		or			|\n|	./fractol julia (num) (num)	|\n\
|					|\n--------------\
---------------------------\n", 191);
	}
	else if (flag == 1)
	{
		ret = write(2, "--------------------------------------\
---\n|					|	\n|	Syntax parameter error		|\n\
|					|\n--------------\
---------------------------\n", 130);
	}
	(void)ret;
	return (1);
}
