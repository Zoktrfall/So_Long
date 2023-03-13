#include "so_long.h"


void    follower_part18(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
				{
					if((game->map)[y_axis - 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis - 1][x_axis] == 'C')
						(game->flags_medus)[monstr.color_medus][1] = 1;
					else
						(game->flags_medus)[monstr.color_medus][1] = 0;
					if((game->flags_medus)[monstr.color_medus][0] == 1)
						monstr.tmp = 'C';
					else
						monstr.tmp = '0';
					(game->map)[y_axis - 1][x_axis] = monstr.medus;
					(game->map)[y_axis][x_axis] = monstr.tmp;
					(game->flags_medus)[monstr.color_medus][0] = (game->flags_medus)[monstr.color_medus][1];
					(game->flags_medus)[monstr.color_medus][1] = 0;
					do_medus(game, monstr, W);
				}


void    follower_part19(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
                {
					if((game->map)[y_axis + 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis + 1][x_axis] == 'C')
						(game->flags_medus)[monstr.color_medus][1] = 1;
					else
						(game->flags_medus)[monstr.color_medus][1] = 0;
					if((game->flags_medus)[monstr.color_medus][0] == 1)
						monstr.tmp = 'C';
					else
						monstr.tmp = '0';
					(game->map)[y_axis + 1][x_axis] = monstr.medus;
					(game->map)[y_axis][x_axis] = monstr.tmp;
					(game->flags_medus)[monstr.color_medus][0] = (game->flags_medus)[monstr.color_medus][1];
					(game->flags_medus)[monstr.color_medus][1] = 0;
					do_medus(game, monstr, S);
				}

void    follower_part20(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
    				{
					if((game->map)[y_axis][x_axis + 1] == 'C')
						(game->flags_medus)[monstr.color_medus][1] = 1;
					else
						(game->flags_medus)[monstr.color_medus][1] = 0;
					if((game->flags_medus)[monstr.color_medus][0] == 1)
						monstr.tmp = 'C';
					else
						monstr.tmp = '0';
					(game->map)[y_axis][x_axis + 1] = monstr.medus;
					(game->map)[y_axis][x_axis] = monstr.tmp;
					(game->flags_medus)[monstr.color_medus][0] = (game->flags_medus)[monstr.color_medus][1];
					(game->flags_medus)[monstr.color_medus][1] = 0;
					do_medus(game, monstr, S);
				}

void    follower_part21(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
				{
					if((game->map)[y_axis + 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis + 1][x_axis] == 'C')
						(game->flags_medus)[monstr.color_medus][1] = 1;
					else
						(game->flags_medus)[monstr.color_medus][1] = 0;
					if((game->flags_medus)[monstr.color_medus][0] == 1)
						monstr.tmp = 'C';
					else
						monstr.tmp = '0';
					(game->map)[y_axis + 1][x_axis] = monstr.medus;	
					(game->map)[y_axis][x_axis] = monstr.tmp;
					(game->flags_medus)[monstr.color_medus][0] = (game->flags_medus)[monstr.color_medus][1];
					(game->flags_medus)[monstr.color_medus][1] = 0;
					do_medus(game, monstr, S);
				}
void    follower_part22(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
				{
					if((game->map)[y_axis - 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis - 1][x_axis] == 'C')
						(game->flags_medus)[monstr.color_medus][1] = 1;
					else
						(game->flags_medus)[monstr.color_medus][1] = 0;
					if((game->flags_medus)[monstr.color_medus][0] == 1)
						monstr.tmp = 'C';
					else
						monstr.tmp = '0';
					(game->map)[y_axis - 1][x_axis] = monstr.medus;
					(game->map)[y_axis][x_axis] = monstr.tmp;
					(game->flags_medus)[monstr.color_medus][0] = (game->flags_medus)[monstr.color_medus][1];
					(game->flags_medus)[monstr.color_medus][1] = 0;
					do_medus(game, monstr, W);
				}
void    follower_part23(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
				{
					if((game->map)[y_axis][x_axis - 1] == 'C')
						(game->flags_medus)[monstr.color_medus][1] = 1;
					else
						(game->flags_medus)[monstr.color_medus][1] = 0;
					if((game->flags_medus)[monstr.color_medus][0] == 1)
						monstr.tmp = 'C';
					else
						monstr.tmp = '0';
					(game->map)[y_axis][x_axis - 1] = monstr.medus;
					(game->map)[y_axis][x_axis] = monstr.tmp;
					do_medus(game, monstr, A);
				}