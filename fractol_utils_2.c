/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:45:53 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/11 13:46:45 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str, double fraction, double nbr, int div)
{
	int	sign;
	int	limit;

	limit = 0;
	sign = 1;
	if (*str++ == '-')
		sign = -1;
	while (*str >= '0' && *str <= '9')
		nbr = (nbr * 10) + (*str++ - '0');
	if (*str == '.')
	{
		while (*++str >= '0' && *str <= '9' && limit++ < 6)
		{
			fraction = fraction * 10 + (*str++ - '0');
			div *= 10;
		}
		nbr += fraction / div;
	}
	return (nbr * sign);
}
