#include "so_long.h"

int ft_if_else(t_gamedata *game, int x_axis, int y_axis)
{
    if((game->map)[y_axis][x_axis] != '1' 
        && (game->map)[y_axis][x_axis] != 'G' 
        && (game->map)[y_axis][x_axis] != 'R' 
        && (game->map)[y_axis][x_axis] != 'E' 
        && (game->map)[y_axis][x_axis] != 'B' 
        && (game->map)[y_axis][x_axis] != 'D')
        return (1);
    return (0);
}

int	ft_strcmp_min(char str1, char str2)
{
	if(str1 - str2 == 0)
		return (1);
	return (0);
}