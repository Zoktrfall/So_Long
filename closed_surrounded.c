#include "so_long.h"

int	error_walls(void)
{
	write(1, "Error\nYour Map Is Not Surrounded By Walls\n", 42);
	return (1);
}

int	first_y(char *str)
{
	size_t	x_axis;

	x_axis = 0;
	while (str[x_axis] != '\0')
	{
		if (str[x_axis] == '1' || (str[x_axis] == '\n'
				&& str[x_axis + 1] == '\0'))
			x_axis++;
		else
			return (1);
	}
	return (0);
}

int	last_y(char **str)
{
	size_t	y_axis;
	size_t	x_axis;

	y_axis = 0;
	x_axis = 0;
	while (str[y_axis])
		y_axis++;
	--y_axis;
	while (str[y_axis][x_axis] != '\0')
	{
		if (str[y_axis][x_axis] == '1' || (str[y_axis][x_axis] == '\n'
			&& str[y_axis][x_axis + 1] == '\0'))
			x_axis++;
		else
			return (1);
	}
	return (0);
}

int	first_last_x(char *str)
{
	size_t	i;

	i = 1;
	if (str[0] != '1')
		return (1);
	while (str[i] != '\0')
		i++;
	if (str[i - 2] != '1')
		return (1);
	return (0);
}

int	closed_surrounded(char **map)
{
	size_t	y_axis;
	size_t	x_axis;
	size_t	len;

	y_axis = 1;
	x_axis = 0;
	len = 0;
	if (first_y(map[0]) || last_y(map))
		return (1);
	while (map[len])
		len++;
	while (y_axis < len - 1)
	{
		if (first_last_x(map[y_axis]))
			return (1);
		y_axis++;
	}
	return (0);
}
