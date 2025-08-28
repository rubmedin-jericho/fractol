/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:57:29 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/27 18:57:38 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_events(t_fractal *fract)
{
	mlx_hook(fract->mlx_win, 2, 1L << 0, event_destroyWindow, fract);
	mlx_hook(fract->mlx_win, DESTROY_NOTIFY, 0, notify_destroyWindow, fract);
}

int	event_destroyWindow(int keycode, t_fractal *fract)
{
	if(keycode == KEY_ESC)
	{
		mlx_destroy_window(fract->mlx, fract->mlx_win);
		exit(0);
	}
	return (0);
}

int	notify_destroyWindow(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->mlx_win);
	exit(0);
	return (0);
}

/*int	handleZoomIn(int	keycode, t_fractal *fract)
{
	return (0);
}
*/


