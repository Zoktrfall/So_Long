#include "so_long.h"

int	error_c_e_p(void)
{
	write(1, "Error\nIncorrect Map Is Associated With E, P, or C!\n", 51);
	return (1);
}

int	check_e_p(char **map, size_t len)
{
	size_t	y_axis;
	size_t	x_axis;
	size_t	exit;
	size_t	player;

	y_axis = 1;
	x_axis = 0;
	exit = 0;
	player = 0;
	while (y_axis < len - 1)
	{
		while (map[y_axis][x_axis] != '\0')
		{
			if (map[y_axis][x_axis] == 'E')
				exit++;
			if (map[y_axis][x_axis] == 'P')
				player++;
			x_axis++;
		}
		x_axis = 0;
		y_axis++;
	}
	if (exit == 1 && player == 1)
		return (0);
	return (1);
}

int	check_c_m(char **map, size_t len)
{
	size_t	y_axis;
	size_t	x_axis;
	size_t	coins;
	size_t	medus;

	y_axis = 1;
	x_axis = 0;
	coins = 0;
	medus = 0;
	while (y_axis < len - 1)
	{
		while (map[y_axis][x_axis] != '\0')
		{
			if (map[y_axis][x_axis] == 'M')
				medus++;
			if (map[y_axis][x_axis] == 'C')
				coins++;
			x_axis++;
		}
		x_axis = 0;
		y_axis++;
	}
	if (!(coins >= 1 && medus <= 6))
		return (1);
	return (0);
}

int	do_check_c_e_p(char **map, size_t len)
{
	if (check_e_p(map, len))
		return (1);
	if (check_c_m(map, len))
		return (1);
	return (0);
}
