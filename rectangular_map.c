#include "so_long.h"

int	error_rectangular(void)
{
	write(1, "The Map Is Not Rectangular\n", 27);
	return (1);
}

int	rectangular_map(char **map)
{
	size_t	y_axis;
	size_t	x_axis;
	size_t	len;

	y_axis = 0;
	x_axis = 0;
	len = ft_strlen(map[0]);
	while (map[y_axis] != NULL)
		y_axis++;
	if (y_axis < 3)
		return (1);
	y_axis = 0;
	while (map[y_axis])
	{
		while (map[y_axis][x_axis] != '\0')
			x_axis++;
		if (map[y_axis][x_axis - 1] != '\n')
			x_axis++;
		if (x_axis != len)
			return (1);
		x_axis = 0;
		y_axis++;
	}
	return (0);
}
