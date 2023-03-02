#include "so_long.h"

int error_rectangular(char **map)
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

int	map_verification(char **map)
{
	if (rectangular_map(map))
		return (error_rectangular(map));
	return (0);
}

int	args_verification(int argc, char **argv, t_mapdata *game)
{
	char	**map;

	if (correct_arguments(argc, argv))
		return (1);
	map = create_map(argv[1]);
	if (map_verification(map))
	{
		free_map(&map);
		return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_mapdata game;

	if(args_verification(argc, argv, &game))
		return (0);
	printf("continue\n");
	return 0;
}
