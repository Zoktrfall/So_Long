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
		if((game->map)[y_axis - 1][x_axis] != '1' && (game->map)[y_axis - 1][x_axis] != 'G' && (game->map)[y_axis - 1][x_axis] != 'R'
		&& (game->map)[y_axis - 1][x_axis] != 'E' && (game->map)[y_axis - 1][x_axis] != 'B' && (game->map)[y_axis - 1][x_axis] != 'D')
			follower_part6(game, monstr, x_axis, y_axis);
		else if(monstr.x > 0)
			follower_part7(game, monstr, x_axis, y_axis);
		else if (monstr.x < 0)
			follower_part8(game, monstr, x_axis, y_axis);
		else if ((game->map)[y_axis + 1][x_axis] != '1' && (game->map)[y_axis + 1][x_axis] != 'G' && (game->map)[y_axis + 1][x_axis] != 'R'
		&& (game->map)[y_axis + 1][x_axis] != 'E' && (game->map)[y_axis + 1][x_axis] != 'B' && (game->map)[y_axis + 1][x_axis] != 'D')
			follower_part9(game, monstr, x_axis, y_axis);
	}

void    follower_part3(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
	{
		if((game->map)[y_axis + 1][x_axis] != '1' && (game->map)[y_axis + 1][x_axis] != 'G' && (game->map)[y_axis + 1][x_axis] != 'R'
		&& (game->map)[y_axis + 1][x_axis] != 'E' && (game->map)[y_axis + 1][x_axis] != 'B' && (game->map)[y_axis + 1][x_axis] != 'D')
			follower_part10(game, monstr, x_axis, y_axis);
		else if(monstr.x > 0)
			follower_part11(game, monstr, x_axis, y_axis);
		else if (monstr.x < 0)
			follower_part12(game, monstr, x_axis, y_axis);
		else if((game->map)[y_axis - 1][x_axis] != '1' && (game->map)[y_axis - 1][x_axis] != 'G' && (game->map)[y_axis - 1][x_axis] != 'R'
		&& (game->map)[y_axis - 1][x_axis] != 'E' && (game->map)[y_axis - 1][x_axis] != 'B' && (game->map)[y_axis - 1][x_axis] != 'D')
			follower_part13(game, monstr, x_axis, y_axis);
	}