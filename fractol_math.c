/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:29:15 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/26 21:56:07 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_complex(t_complex real, t_complex imagine)
{
	t_complex	sum_result;

	sum_result.re = real.re + imagine.re;
	sum_result.im = real.im + imagine.im;
	return (sum_result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	rst_cmp;

	rst_cmp.re = (z.re * z.re) - (z.im * z.im);
	rst_cmp.im = 2 * z.re * z.im;
	return (rst_cmp);
}

double maping(double x, double in_min, double in_max, double out_max)
{
    return in_min + (x / out_max) * (in_max - in_min);
}

