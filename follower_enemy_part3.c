#include "so_long.h"

void    follower_part14(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
			{
				if((game->map)[y_axis][x_axis - 1] == 'P')
				{
					game->game_over = 1;
					return ;
				} 
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
				(game->flags_medus)[monstr.color_medus][0] = (game->flags_medus)[monstr.color_medus][1];
				(game->flags_medus)[monstr.color_medus][1] = 0;
				if(monstr.color_medus == 0)
					game->medus_gamepath_green = A;
				else if(monstr.color_medus == 1)
					game->medus_gamepath_red = A;
				else if(monstr.color_medus == 2)
					game->medus_gamepath_blue = A;
				else if(monstr.color_medus == 3)
					game->medus_gamepath_purple = A;
			}

void    follower_part15(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
            {
				if((game->map)[y_axis - 1][x_axis] != '1' && (game->map)[y_axis - 1][x_axis] != 'G' && (game->map)[y_axis - 1][x_axis] != 'R'
				&& (game->map)[y_axis - 1][x_axis] != 'E' && (game->map)[y_axis - 1][x_axis] != 'D' && (game->map)[y_axis - 1][x_axis] != 'B')
                    follower_part18(game, monstr, x_axis, y_axis);
				else if((game->map)[y_axis + 1][x_axis] != '1' && (game->map)[y_axis + 1][x_axis] != 'E' && (game->map)[y_axis + 1][x_axis] != 'D'
				&& (game->map)[y_axis + 1][x_axis] != 'G' && (game->map)[y_axis + 1][x_axis] != 'R' && (game->map)[y_axis + 1][x_axis] != 'B')
                    follower_part19(game, monstr, x_axis, y_axis);
				else if((game->map)[y_axis][x_axis + 1] != '1' && (game->map)[y_axis][x_axis + 1] != 'R' && (game->map)[y_axis][x_axis + 1] != 'G'
				&& (game->map)[y_axis][x_axis + 1] != 'E' && (game->map)[y_axis][x_axis + 1] != 'B' && (game->map)[y_axis][x_axis + 1] != 'D')
                    follower_part20(game, monstr, x_axis, y_axis);
			}

void    follower_part16(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)

			{
				if((game->map)[y_axis][x_axis + 1] == 'P')
				{	
					game->game_over = 1;
					return ;
				}
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
					if(monstr.color_medus == 0)
						game->medus_gamepath_green = D;
					else if(monstr.color_medus == 1)
						game->medus_gamepath_red = D;
					else if(monstr.color_medus == 2)
						game->medus_gamepath_blue = D;
					else if(monstr.color_medus == 3)
						game->medus_gamepath_purple = D;
			}


void    follower_part17(t_gamedata *game, t_follower monstr, int x_axis, int y_axis)
{
				if((game->map)[y_axis + 1][x_axis] != '1' && (game->map)[y_axis + 1][x_axis] != 'B' && (game->map)[y_axis + 1][x_axis] != 'R'
				&& (game->map)[y_axis + 1][x_axis] != 'G' && (game->map)[y_axis + 1][x_axis] != 'E' && (game->map)[y_axis + 1][x_axis] != 'D')
                    follower_part21(game, monstr, x_axis, y_axis);
				else if((game->map)[y_axis - 1][x_axis] != '1' && (game->map)[y_axis - 1][x_axis] != 'B' && (game->map)[y_axis - 1][x_axis] != 'R'
				&& (game->map)[y_axis - 1][x_axis] != 'G' && (game->map)[y_axis - 1][x_axis] != 'E' && (game->map)[y_axis - 1][x_axis] != 'D')
                    follower_part22(game, monstr, x_axis, y_axis);
				else if((game->map)[y_axis][x_axis - 1] != '1' && (game->map)[y_axis][x_axis - 1] != 'G' && (game->map)[y_axis][x_axis - 1] != 'R'
				&& (game->map)[y_axis][x_axis - 1] != 'E' && (game->map)[y_axis][x_axis - 1] != 'B' && (game->map)[y_axis][x_axis - 1] != 'D')
                    follower_part23(game, monstr ,x_axis, y_axis);
			}