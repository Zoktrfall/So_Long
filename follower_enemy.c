#include "so_long.h"

void    follower_part1(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
{
	if(monstr.x > 0)
		follower_part4(game, monstr, x_axis, y_axis);
	else if (monstr.x < 0)
		follower_part5(game, monstr, x_axis, y_axis);
}

void    follower_part2(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
{
	if(ft_if_else(game, x_axis, y_axis - 1))
		follower_part6(game, monstr, x_axis, y_axis);
	else if(monstr.x > 0)
		follower_part7(game, monstr, x_axis, y_axis);
	else if (monstr.x < 0)
		follower_part8(game, monstr, x_axis, y_axis);
	else if (ft_if_else(game, x_axis, y_axis + 1))
		follower_part9(game, monstr, x_axis, y_axis);
}

void    follower_part3(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
{
	if(ft_if_else(game, x_axis, y_axis + 1))
		follower_part10(game, monstr, x_axis, y_axis);
	else if(monstr.x > 0)
		follower_part11(game, monstr, x_axis, y_axis);
	else if (monstr.x < 0)
		follower_part12(game, monstr, x_axis, y_axis);
	else if(ft_if_else(game, x_axis, y_axis - 1))
		follower_part13(game, monstr, x_axis, y_axis);
}