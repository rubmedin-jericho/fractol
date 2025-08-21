#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>

# include <stdio.h>

# define HEIGHT 1000
# define WEIGHT 1000

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int ft_strcmp(const char *s1, const char *s2);
void	Error_message();

#endif
