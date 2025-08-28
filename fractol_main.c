/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:06:08 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/26 21:47:20 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol(t_fractal *fractal)
{
//	int *(destWin)(int, t_fractal);
//
//	destWin = destroyWindow;
	init_window(fractal);
	//my_mlx_pixel_put(fractal->img, HEIGHT, WIDTH, RED);
	if(!ft_strcmp(fractal->name_fractal, "mandelbrot"))
		render_mandelbrot(fractal);
/*	else if (!ft_strcmp(fractal->name_fractal, "julia"))
		render_julia(fractal);*/
	init_events(fractal);
	mlx_loop(fractal->mlx);
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

int	check_errors(int argc, char **argv)
{
	if (!ft_strcmp(argv[1], "mandelbrot") && argc == 2)
		return (0);
	else if (!ft_strcmp(argv[1], "julia") && argc == 4)
	{
		if (checker_num(argv))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal fractal;

	if (argc > 1)
	{
		if (check_errors(argc, argv) > 0)
			return (Error_message(1));
		if(!ft_strcmp(argv[1], "mandelbrot"))
			init_fractal_mandelbrot(&fractal);
		else if(!ft_strcmp(argv[1], "julia"))
			init_fractal_julia(&fractal, argv[2], argv[3]);
		else
			return (Error_message(0));
	}
	else 
		return (Error_message(0));
	fractol(&fractal);
	return (0);
}
