#include "so_long.h"

int	error_c_e_p(void)
{
	write(1, "Error\nIncorrect Map Is Associated With E, P, M, or C!\n", 54);
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

	y_axis = 0;
	x_axis = 0;
	coins = 0;
	medus = 0;
	while (++y_axis < len - 1)
	{
		while (map[y_axis][x_axis] != '\0')
		{
			if (map[y_axis][x_axis] == 'G' || map[y_axis][x_axis] == 'R'
				|| map[y_axis][x_axis] == 'D' || map[y_axis][x_axis] == 'B')
				medus++;
			if (map[y_axis][x_axis] == 'C')
				coins++;
			x_axis++;
		}
		x_axis = 0;
	}
	if (!(coins >= 1 && medus <= 4))
		return (1);
	return (0);
}

int	duplicate_medus(char **map, size_t len, size_t x, size_t y)
{
	size_t	medus_b;
	size_t	medus_r;
	size_t	medus_g;
	size_t	medus_p;

	medus_b = 0;
	medus_g = 0;
	medus_p = 0;
	medus_r = 0;
	while (map[++y])
	{
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'B')
				medus_b++;
			if (map[y][x] == 'G')
				medus_g++;
			if (map[y][x] == 'D')
				medus_p++;
			if (map[y][x] == 'R')
				medus_r++;
		}
		x = -1;
	}
	return (check_medus(medus_b, medus_g, medus_r, medus_p));
}

int	do_check_c_e_p(char **map, size_t len)
{
	if (check_e_p(map, len))
		return (1);
	if (check_c_m(map, len))
		return (1);
	if (duplicate_medus(map, len, -1, -1))
		return (1);
	return (0);
}
