#include "so_long.h"

void	error_empty(char **map)
{
	write(1, "Error\nYour File Is Empty\n", 25);
	free_map(&map);
	exit(0);
}

void	error_divided(char **map)
{
	write(1, "Error\nYour Map Is Divided\n", 26);
	free_map(&map);
	exit(0);
}

int	divided_map(char **map)
{
	size_t	flag;
	size_t	start;

	start = 0;
	flag = 0;
	while (unprinted(map[start]))
		start++;
	while (map[start])
	{
		if (!unprinted(map[start]))
			start++;
		else
			break ;
	}
	while (map[start])
	{
		if (unprinted(map[start]))
			start++;
		else
			break ;
	}
	if (map[start] != NULL)
		return (1);
	return (0);
}
