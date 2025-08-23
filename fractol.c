/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:06:08 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 17:17:12 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(void **mlx, void **mlx_win)
{
	*mlx_win = mlx_new_window(*mlx, HEIGHT, WEIGHT, "fract-ol");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	fractol()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, (HEIGHT * 2), (WEIGHT * 2)); 
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_window(&mlx, &mlx_win);

	my_mlx_pixel_put(&img, (HEIGHT / 2), (WEIGHT / 2), 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

int	not_num(char *str, int *count_sign)
{
	int	counter;

	counter = 0;
	while(str[counter])
	{
		if (str[counter] == '-' || str[counter] == '+')
		{
			*count_sign += 1;
			counter++;
		}
		else if (str[counter] > 47 && str[counter] < 58)
			counter++;
		else
			return (1);
	}
	return (0);
}

int	checker_num(char **argv)
{
	int	counter;
	int	count_sign;

	counter = 2;
	while(argv[counter])
	{
		count_sign = 0;
		if (not_num(argv[counter], &count_sign))
			return (1);
		else if (count_sign > 1)
			return (1);
		counter++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "mandelbrot") && argc == 2)
		{}
//			set_mandelbrot();
		else if (!ft_strcmp(argv[1], "julia") && argc == 4)
		{
			if (checker_num(argv))
			{
				printf("Error");
				return (1);
			}
		}
		else
		{
			Error_message();
			return (2);
		}
	}
	else 
		return (1);
	fractol();
	return (0);
}
