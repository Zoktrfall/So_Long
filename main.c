#include "so_long.h"
#include <stdio.h>

int args_verification(int argc, char **argv, t_mapdata *game)
{
	char **map;

	if(correct_arguments(argc, argv))
		return (1);
	map = create_map(argv[1]);
	// int i = 0;
	// while(map[i])
	// {
	// 	printf("%s", map[i]);
	// 	i++;
	// }
	return (0);
}

int main(int argc, char *argv[])
{
	t_mapdata game;

	if(args_verification(argc, argv, &game))
		return (0);
	printf("\n");
	printf("continue\n");
	return 0;
}