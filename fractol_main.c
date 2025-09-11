/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:06:08 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:59:01 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol(t_fractal *fractal)
{
	init_window(fractal);
	if (!ft_strcmp(fractal->name_fractal, "mandelbrot"))
		render_mandelbrot(fractal);
	else if (!ft_strcmp(fractal->name_fractal, "julia"))
		render_julia(fractal);
	init_events(fractal);
	mlx_loop(fractal->mlx);
	return (0);
}

int	not_num(char *str, int *count_sign, int *count_dot)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == '.')
		{
			*count_dot += 1;
			counter++;
		}
		else if (str[counter] == '-' || str[counter] == '+')
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
	int	count_dot;

	counter = 2;
	while (argv[counter])
	{
		count_sign = 0;
		count_dot = 0;
		if (not_num(argv[counter], &count_sign, &count_dot))
			return (1);
		else if (count_sign > 1 || count_dot > 1)
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
	t_fractal	fractal;

	if (argc > 1)
	{
		if (check_errors(argc, argv) > 0)
			return (error_message());
		if (!ft_strcmp(argv[1], "mandelbrot"))
			init_fractal_mandelbrot(&fractal);
		else if (!ft_strcmp(argv[1], "julia"))
			init_fractal_julia(&fractal, argv[2], argv[3]);
		else
			return (error_message());
	}
	else
		return (error_message());
	if (!fractol(&fractal))
		return (1);
	return (0);
}
