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

int ft_strcmp(const char *s1, const char *s2)
{
    int i;
    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }
    return s1[i] - s2[i];
}

void	Error_message()
{
	write(2, "\nError parameters try:\n--------------------------------------\
---\n|					|\n|	./fractol mandelbrot		|\n\
|		or			|\n|	./fractol julia (num) (num)	|\n\
|					|\n--------------\
---------------------------\n", 191);
}
