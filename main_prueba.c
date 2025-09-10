#include "fractol.h"

int	main()
{
	double result;
	char *str = "123.362";

	result = 0;
	result = ft_atof(str);
	printf("result: %f\n", result);
	return (0);
}
