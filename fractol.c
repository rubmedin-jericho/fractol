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

int	checker_num(int	argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while(argv[i])
	{
		j = 0;
		flag = 0;
		while(argv[i][j])
		{
			
			j++;
		}
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "mandelbrot") && argc == 2)
//			set_mandelbrot();
		else if (!ft_strcmp(argv[1], "julia") && argc == 4)
		{
			if (checker_num(argc, argv))
			{

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
