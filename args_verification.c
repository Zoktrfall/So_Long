#include "so_long.h"

int	args_verification(int argc, char **argv, char ***map)
{
	if (correct_arguments(argc, argv))
		return (1);
	*map = create_map(argv[1]);
	if ((*map)[0] == NULL)
		error_empty(*map);
	if (divided_map(*map))
		error_divided(*map);
	*map = optimization_map(*map);
	if (map_verification(*map))
	{
		free_map(map);
		return (1);
	}
	return (0);
}

int	map_verification(char **map)
{
	if (rectangular_map(map))
		return (error_rectangular());
	if (closed_surrounded(map))
		return (error_walls());
	if (check_c_e_p(map))
		return (error_c_e_p());
	if (valid_way(map))
		return (error_valid_way());
	return (0);
}
