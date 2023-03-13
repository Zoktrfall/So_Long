#include "so_long.h"

void	follower_part14(t_gamedata *game, t_follower monstr, \
				int x_axis, int y_axis)
{
	if ((game->map)[y_axis][x_axis - 1] == 'P')
	{
		game->game_over = 1;
		return ;
	}
	if ((game->map)[y_axis][x_axis - 1] == 'C')
		(game->flags_medus)[monstr.color_medus][1] = 1;
	else
		(game->flags_medus)[monstr.color_medus][1] = 0;
	if ((game->flags_medus)[monstr.color_medus][0] == 1)
		monstr.tmp = 'C';
	else
		monstr.tmp = '0';
	(game->map)[y_axis][x_axis - 1] = monstr.medus;
	(game->map)[y_axis][x_axis] = monstr.tmp;
	(game->flags_medus)[monstr.color_medus][0] = \
		(game->flags_medus)[monstr.color_medus][1];
	(game->flags_medus)[monstr.color_medus][1] = 0;
	do_medus(game, monstr, A);
}

void	follower_part15(t_gamedata *game, t_follower monstr, \
				int x_axis, int y_axis)
{
	if (ft_if_else(game, x_axis, y_axis - 1))
		follower_part18(game, monstr, x_axis, y_axis);
	else if (ft_if_else(game, x_axis, y_axis + 1))
		follower_part19(game, monstr, x_axis, y_axis);
	else if (ft_if_else(game, x_axis + 1, y_axis))
		follower_part20(game, monstr, x_axis, y_axis);
}

void	follower_part16(t_gamedata *game, t_follower monstr, \
				int x_axis, int y_axis)
{
	if ((game->map)[y_axis][x_axis + 1] == 'P')
	{	
		game->game_over = 1;
		return ;
	}
	if ((game->map)[y_axis][x_axis + 1] == 'C')
		(game->flags_medus)[monstr.color_medus][1] = 1;
	else
		(game->flags_medus)[monstr.color_medus][1] = 0;
	if ((game->flags_medus)[monstr.color_medus][0] == 1)
		monstr.tmp = 'C';
	else
		monstr.tmp = '0';
	(game->map)[y_axis][x_axis + 1] = monstr.medus;
	(game->map)[y_axis][x_axis] = monstr.tmp;
	(game->flags_medus)[monstr.color_medus][0] = \
		(game->flags_medus)[monstr.color_medus][1];
	(game->flags_medus)[monstr.color_medus][1] = 0;
	do_medus(game, monstr, D);
}

void	follower_part17(t_gamedata *game, t_follower monstr, \
				int x_axis, int y_axis)
{
	if (ft_if_else(game, x_axis, y_axis + 1))
		follower_part21(game, monstr, x_axis, y_axis);
	else if (ft_if_else(game, x_axis, y_axis - 1))
		follower_part22(game, monstr, x_axis, y_axis);
	else if (ft_if_else(game, x_axis - 1, y_axis))
		follower_part23(game, monstr, x_axis, y_axis);
}
