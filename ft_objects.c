#include "so_long.h"

size_t count_coins(char **map, size_t len)
{
	size_t	y_axis;
	size_t	x_axis;
	size_t	coints;

	y_axis = 1;
	x_axis = 0;
	coints = 0;
	while(y_axis < len - 1)
	{
		while(map[y_axis][x_axis] != '\0')
		{
			if(map[y_axis][x_axis] == 'C')
				coints++;
			x_axis++;
		}
		x_axis = 0;
		y_axis++;
	}
	return (coints);
}

size_t	count_enemies(char **map, size_t len)
{
	size_t	y_axis;
	size_t	x_axis;
	size_t	enemies;

	y_axis = 1;
	x_axis = 0;
	enemies = 0;
	while(y_axis < len - 1)
	{
		while(map[y_axis][x_axis] != '\0')
		{
			if(map[y_axis][x_axis] == 'M')
				enemies++;
			x_axis++;
		}
		x_axis = 0;
		y_axis++;
	}
	return (enemies);
}

void	player_position(char **map, t_player *play)
{
	(*play).x = 0;
	(*play).y = 0;
	while(map[(*play).y][(*play).y])
	{	
		while(map[(*play).y][(*play).x] != '\0')
		{
			if(map[(*play).y][(*play).x] == 'P')
				break;
			((*play).x)++;
		}
		if(map[(*play).y][(*play).x] == 'P')
			break;
		((*play).x) = 0;
		((*play).y)++;
	}
}
