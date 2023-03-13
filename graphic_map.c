#include "so_long.h"

void	map_traversal(char *map, size_t y_axis, t_gamedata *game)
{
	size_t	x_axis;

	x_axis = -1;
	while (map[++x_axis] != '\0')
	{
		if (map[x_axis] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.walls, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.coins, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.portal, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.black, x_axis * SIZE, y_axis * SIZE);
	}
}

int	refresh_image(t_gamedata *game)
{
	ft_position(game->map, &(game->player), 'P');
	if (game->gamepath == S && game->game_over != 1)
		pacman_down(game);
	else if (game->gamepath == W && game->game_over != 1)
		pacman_up(game);
	else if (game->gamepath == A && game->game_over != 1)
		pacman_left(game);
	else if (game->gamepath == D && game->game_over != 1)
		pacman_right(game);
	else if (game->game_over != 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.pac_man.pac_closed, \
		game->player.x * SIZE, game->player.y * SIZE);
	return (0);
}

int	ft_strcmp(char str1, char str2)
{
	if(str1 - str2 == 0)
		return (1);
	return (0);
}

void enemy_motion(t_gamedata *game, int y_axis, int x_axis, char medus)
{
	int		x;
	int		y;
	int 	color_medus;
	char	tmp;

	x = x_axis - game->player.x;
	y = y_axis - game->player.y;
	tmp = '0';
	if(ft_strcmp(medus, 'G'))
		color_medus = 0;
	else if(ft_strcmp(medus, 'R'))
		color_medus = 1;
	else if(ft_strcmp(medus, 'B'))
		color_medus = 2;
	else if(ft_strcmp(medus, 'D'))
		color_medus = 3;
	if(y == 0)
	{
		if(x > 0)
		{
			if((game->map)[y_axis][x_axis - 1] != '1' && (game->map)[y_axis][x_axis - 1] != 'E' && (game->map)[y_axis][x_axis - 1] != 'B'
				&& (game->map)[y_axis][x_axis - 1] != 'G' && (game->map)[y_axis][x_axis - 1] != 'D' && (game->map)[y_axis][x_axis - 1] != 'R')
			{
				if((game->map)[y_axis][x_axis - 1] == 'P')
				{
					game->game_over = 1;
					return ;
				} 
				if((game->map)[y_axis][x_axis - 1] == 'C')
					(game->flags_medus)[color_medus][1] = 1;
				else
					(game->flags_medus)[color_medus][1] = 0;
				if((game->flags_medus)[color_medus][0] == 1)
					tmp = 'C';
				else
					tmp = '0';
				(game->map)[y_axis][x_axis - 1] = medus;
				(game->map)[y_axis][x_axis] = tmp;
				(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
				(game->flags_medus)[color_medus][1] = 0;
				if(color_medus == 0)
					game->medus_gamepath_green = A;
				else if(color_medus == 2)
					game->medus_gamepath_blue = A;
			}
			else if((game->map)[y_axis][x_axis - 1] == '1' && (game->map)[y_axis][x_axis - 1] == 'E' && (game->map)[y_axis][x_axis - 1] == 'G'
			&& (game->map)[y_axis][x_axis - 1] == 'B' && (game->map)[y_axis][x_axis - 1] == 'D' && (game->map)[y_axis][x_axis - 1] == 'R')
			{
				if((game->map)[y_axis - 1][x_axis] != '1' && (game->map)[y_axis - 1][x_axis] != 'G' && (game->map)[y_axis - 1][x_axis] != 'R'
				&& (game->map)[y_axis - 1][x_axis] != 'E' && (game->map)[y_axis - 1][x_axis] != 'D' && (game->map)[y_axis - 1][x_axis] != 'B')
				{
					if((game->map)[y_axis - 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis - 1][x_axis] == 'C')
						(game->flags_medus)[color_medus][1] = 1;
					else
						(game->flags_medus)[color_medus][1] = 0;
					if((game->flags_medus)[color_medus][0] == 1)
						tmp = 'C';
					else
						tmp = '0';
					(game->map)[y_axis - 1][x_axis] = medus;
					(game->map)[y_axis][x_axis] = tmp;
					(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
					(game->flags_medus)[color_medus][1] = 0;
					if(color_medus == 0)
						game->medus_gamepath_green = W;
					else if(color_medus == 2)
						game->medus_gamepath_blue = W;
				}
				else if((game->map)[y_axis + 1][x_axis] != '1' && (game->map)[y_axis + 1][x_axis] != 'E' && (game->map)[y_axis + 1][x_axis] != 'D'
				&& (game->map)[y_axis + 1][x_axis] != 'G' && (game->map)[y_axis + 1][x_axis] != 'R' && (game->map)[y_axis + 1][x_axis] != 'B')
				{
					if((game->map)[y_axis + 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis + 1][x_axis] == 'C')
						(game->flags_medus)[color_medus][1] = 1;
					else
						(game->flags_medus)[color_medus][1] = 0;
					if((game->flags_medus)[color_medus][0] == 1)
						tmp = 'C';
					else
						tmp = '0';
					(game->map)[y_axis + 1][x_axis] = medus;
					(game->map)[y_axis][x_axis] = tmp;
					(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
					(game->flags_medus)[color_medus][1] = 0;
					if(color_medus == 0) 
						game->medus_gamepath_green = S;
					else if(color_medus == 2)
						game->medus_gamepath_blue = S;
				}
				// else if((game->map)[y_axis][x_axis + 1] != '1')
				// {
				// 	(game->map)[y_axis][x_axis + 1] = medus;
				// 	(game->map)[y_axis][x_axis] = '0';
				// 	game->medus_gamepath_green = D;
				// }
			}
		}
		else if (x < 0)
		{
			if((game->map)[y_axis][x_axis + 1] != '1' && (game->map)[y_axis][x_axis + 1] != '1' && (game->map)[y_axis][x_axis + 1] != 'R'
			&& (game->map)[y_axis][x_axis + 1] != 'G' && (game->map)[y_axis][x_axis + 1] != 'E' && (game->map)[y_axis][x_axis + 1] != 'D')
			{
				if((game->map)[y_axis][x_axis + 1] == 'P')
				{	
					game->game_over = 1;
					return ;
				}
				if((game->map)[y_axis][x_axis + 1] == 'C')
					(game->flags_medus)[color_medus][1] = 1;
				else
					(game->flags_medus)[color_medus][1] = 0;
				if((game->flags_medus)[color_medus][0] == 1)
					tmp = 'C';
				else
					tmp = '0';
				(game->map)[y_axis][x_axis + 1] = medus;
				(game->map)[y_axis][x_axis] = tmp;
				(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
				(game->flags_medus)[color_medus][1] = 0;
				if(color_medus == 0)
					game->medus_gamepath_green = D;
				else if(color_medus == 2)
					game->medus_gamepath_blue = D;
			}
			else if((game->map)[y_axis][x_axis + 1] == '1' && (game->map)[y_axis][x_axis + 1] == 'B' && (game->map)[y_axis][x_axis + 1] == 'R'
			&& (game->map)[y_axis][x_axis + 1] == 'G' && (game->map)[y_axis][x_axis + 1] == 'E' && (game->map)[y_axis][x_axis + 1] == 'D')
			{
				if((game->map)[y_axis + 1][x_axis] != '1' && (game->map)[y_axis + 1][x_axis] != 'B' && (game->map)[y_axis + 1][x_axis] != 'R'
				&& (game->map)[y_axis + 1][x_axis] != 'G' && (game->map)[y_axis + 1][x_axis] != 'E' && (game->map)[y_axis + 1][x_axis] != 'D')
				{
					if((game->map)[y_axis + 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis + 1][x_axis] == 'C')
						(game->flags_medus)[color_medus][1] = 1;
					else
						(game->flags_medus)[color_medus][1] = 0;
					if((game->flags_medus)[color_medus][0] == 1)
						tmp = 'C';
					else
						tmp = '0';
					(game->map)[y_axis + 1][x_axis] = medus;	
					(game->map)[y_axis][x_axis] = tmp;
					(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
					(game->flags_medus)[color_medus][1] = 0;
					if(color_medus == 0)
						game->medus_gamepath_green = S;
					else if(color_medus == 2)
						game->medus_gamepath_blue = S;
				}
				else if((game->map)[y_axis - 1][x_axis] != '1' && (game->map)[y_axis - 1][x_axis] != 'B' && (game->map)[y_axis - 1][x_axis] != 'R'
				&& (game->map)[y_axis - 1][x_axis] != 'G' && (game->map)[y_axis - 1][x_axis] != 'E' && (game->map)[y_axis - 1][x_axis] != 'D')
				{
					if((game->map)[y_axis - 1][x_axis] == 'P')
					{	
						game->game_over = 1;
						return ;
					}
					if((game->map)[y_axis - 1][x_axis] == 'C')
						(game->flags_medus)[color_medus][1] = 1;
					else
						(game->flags_medus)[color_medus][1] = 0;
					if((game->flags_medus)[color_medus][0] == 1)
						tmp = 'C';
					else
						tmp = '0';
					(game->map)[y_axis - 1][x_axis] = medus;
					(game->map)[y_axis][x_axis] = tmp;
					(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
					(game->flags_medus)[color_medus][1] = 0;
					if(color_medus == 0)
						game->medus_gamepath_green = W;
					else if (color_medus == 2)
						game->medus_gamepath_blue = W;
				}
				// else if((game->map)[y_axis][x_axis - 1] != '1')
				// {
				// 	(game->map)[y_axis][x_axis - 1] = medus;
				// 	(game->map)[y_axis][x_axis] = '0';
				// 	game->medus_gamepath_green = A;
				// }
			}
		}
	}
	else if(y > 0)
	{
		if((game->map)[y_axis - 1][x_axis] != '1' && (game->map)[y_axis - 1][x_axis] != 'G' && (game->map)[y_axis - 1][x_axis] != 'R'
		&& (game->map)[y_axis - 1][x_axis] != 'E' && (game->map)[y_axis - 1][x_axis] != 'B' && (game->map)[y_axis - 1][x_axis] != 'D')
		{
			if((game->map)[y_axis - 1][x_axis] == 'P')
			{	
				game->game_over = 1;
				return ;
			}
			if((game->map)[y_axis - 1][x_axis] == 'C')
				(game->flags_medus)[color_medus][1] = 1;
			else
				(game->flags_medus)[color_medus][1] = 0;
			if((game->flags_medus)[color_medus][0] == 1)
				tmp = 'C';
			else
				tmp = '0';
			(game->map)[y_axis - 1][x_axis] = medus;
			(game->map)[y_axis][x_axis] = tmp;
			(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
			(game->flags_medus)[color_medus][1] = 0;
			if(color_medus == 0)
				game->medus_gamepath_green = W;
			else if(color_medus == 2)
				game->medus_gamepath_blue = W;
		}
		else if(x > 0)
		{
			if((game->map)[y_axis][x_axis - 1] != '1' && (game->map)[y_axis][x_axis - 1] != 'G' && (game->map)[y_axis][x_axis - 1] != 'R'
			&& (game->map)[y_axis][x_axis - 1] != 'E' && (game->map)[y_axis][x_axis - 1] != 'B' && (game->map)[y_axis][x_axis - 1] != 'D')
			{
				if((game->map)[y_axis][x_axis - 1] == 'P')
				{	
					game->game_over = 1;
					return ;
				}
				if((game->map)[y_axis][x_axis - 1] == 'C')
					(game->flags_medus)[color_medus][1] = 1;
				else
					(game->flags_medus)[color_medus][1] = 0;
				if((game->flags_medus)[color_medus][0] == 1)
					tmp = 'C';
				else
					tmp = '0';
				(game->map)[y_axis][x_axis - 1] = medus;
				(game->map)[y_axis][x_axis] = tmp;
				(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
				(game->flags_medus)[color_medus][1] = 0;
				if(color_medus == 0)
					game->medus_gamepath_green = A;
				else if (color_medus == 2)
					game->medus_gamepath_blue = A;
			}
		}
		else if (x < 0)
		{
			if((game->map)[y_axis][x_axis + 1] != '1' && (game->map)[y_axis][x_axis + 1] != 'G' && (game->map)[y_axis][x_axis + 1] != 'R'
			&& (game->map)[y_axis][x_axis + 1] != 'E' && (game->map)[y_axis][x_axis + 1] != 'B' && (game->map)[y_axis][x_axis + 1] != 'D')
			{
				if((game->map)[y_axis][x_axis + 1] == 'P')
				{	
					game->game_over = 1;
					return ;
				}
				if((game->map)[y_axis][x_axis + 1] == 'C')
					(game->flags_medus)[color_medus][1] = 1;
				else
					(game->flags_medus)[color_medus][1] = 0;
				if((game->flags_medus)[color_medus][0] == 1)
					tmp = 'C';
				else
					tmp = '0';
				(game->map)[y_axis][x_axis + 1] = medus;
				(game->map)[y_axis][x_axis] = tmp;
				(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
				(game->flags_medus)[color_medus][1] = 0;
				if(color_medus == 0)
					game->medus_gamepath_green = D;
				else if(color_medus == 2)
					game->medus_gamepath_blue = D;
			}
		}
		// else if ((game->map)[y_axis + 1][x_axis] != '1')
		// {
		// 	(game->map)[y_axis + 1][x_axis] = medus;
		// 	(game->map)[y_axis][x_axis] = '0';
		// 	game->medus_gamepath_green = S;
		// }
	}
	else if (y < 0)
	{
		if((game->map)[y_axis + 1][x_axis] != '1' && (game->map)[y_axis + 1][x_axis] != 'G' && (game->map)[y_axis + 1][x_axis] != 'R'
		&& (game->map)[y_axis + 1][x_axis] != 'E' && (game->map)[y_axis + 1][x_axis] != 'B' && (game->map)[y_axis + 1][x_axis] != 'D')
		{
			if((game->map)[y_axis + 1][x_axis] == 'P')
			{
				game->game_over = 1;
				return ;
			}
			if((game->map)[y_axis + 1][x_axis] == 'C')
				(game->flags_medus)[color_medus][1] = 1;
			else
				(game->flags_medus)[color_medus][1] = 0;
			if((game->flags_medus)[color_medus][0] == 1)
				tmp = 'C';
			else
				tmp = '0';
			(game->map)[y_axis + 1][x_axis] = medus;
			(game->map)[y_axis][x_axis] = tmp;
			(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
			(game->flags_medus)[color_medus][1] = 0;
			if(color_medus == 0)
				game->medus_gamepath_green = S;
			else if (color_medus == 2)
				game->medus_gamepath_blue = S;
		}
		else if(x > 0)
		{
			if((game->map)[y_axis][x_axis - 1] != '1' && (game->map)[y_axis][x_axis - 1] != 'B' && (game->map)[y_axis][x_axis - 1] != 'R'
			&& (game->map)[y_axis][x_axis - 1] != 'E' && (game->map)[y_axis][x_axis - 1] != 'G' && (game->map)[y_axis][x_axis - 1] != 'D')
			{
				if((game->map)[y_axis][x_axis - 1] == 'P')
				{
					game->game_over = 1;
					return ;
				}
				if((game->map)[y_axis][x_axis - 1] == 'C')
					(game->flags_medus)[color_medus][1] = 1;
				else
					(game->flags_medus)[color_medus][1] = 0;
				if((game->flags_medus)[color_medus][0] == 1)
					tmp = 'C';
				else
					tmp = '0';
				(game->map)[y_axis][x_axis - 1] = medus;
				(game->map)[y_axis][x_axis] = tmp;
				(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
				(game->flags_medus)[color_medus][1] = 0;
				if(color_medus == 0)
					game->medus_gamepath_green = A;
				else if(color_medus == 2)
					game->medus_gamepath_blue = A;
			}
		}
		else if (x < 0)
		{
			if((game->map)[y_axis][x_axis + 1] != '1' && (game->map)[y_axis][x_axis + 1] != 'G' && (game->map)[y_axis][x_axis + 1] != 'R'
			&& (game->map)[y_axis][x_axis + 1] != 'E' && (game->map)[y_axis][x_axis + 1] != 'B' && (game->map)[y_axis][x_axis + 1] != 'D')
			{
				if((game->map)[y_axis][x_axis + 1] == 'P')
				{
					game->game_over = 1;
					return ;
				}	
				if((game->map)[y_axis][x_axis + 1] == 'C')
					(game->flags_medus)[color_medus][1] = 1;
				else
					(game->flags_medus)[color_medus][1] = 0;
				if((game->flags_medus)[color_medus][0] == 1)
					tmp = 'C';
				else
					tmp = '0';
				(game->map)[y_axis][x_axis + 1] = medus;
				(game->map)[y_axis][x_axis] = tmp;
				(game->flags_medus)[color_medus][0] = (game->flags_medus)[color_medus][1];
				(game->flags_medus)[color_medus][1] = 0;
				if(color_medus == 0)
					game->medus_gamepath_green = D;
				else if (color_medus == 2)
					game->medus_gamepath_blue = D;
			}
		}
		// else if((game->map)[y_axis - 1][x_axis] != '1')
		// {
		// 	(game->map)[y_axis - 1][x_axis] = medus;
		// 	(game->map)[y_axis][x_axis] = '0';
		// 	game->medus_gamepath_green = W;
		// }
	}
}

void	anim_medus_moves_green(t_gamedata *game)
{
	if(game->medus_gamepath_green == W && game->game_over != 1)
		medus_anim_up(&(game->lists.medus_green_up), game, game->lists.head_green_up, game->medus_green_pos);
	else if(game->medus_gamepath_green == S && game->game_over != 1)
		medus_anim_down(&(game->lists.medus_green_down), game, game->lists.head_green_down, game->medus_green_pos);
	else if(game->medus_gamepath_green == A && game->game_over != 1)
		medus_anim_left(&(game->lists.medus_green_left), game, game->lists.head_green_left, game->medus_green_pos);
	else if(game->medus_gamepath_green == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_green_right), game, game->lists.head_green_right, game->medus_green_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_green.ghost_down1, game->medus_green_pos.x * SIZE, game->medus_green_pos.y * SIZE);
}

void	anim_medus_moves_blue(t_gamedata *game)
{
	if(game->medus_gamepath_blue == W && game->game_over != 1)
		medus_anim_up(&(game->lists.medus_blue_up), game, game->lists.head_blue_up, game->medus_blue_pos);
	else if(game->medus_gamepath_blue == S && game->game_over != 1)
		medus_anim_down(&(game->lists.medus_blue_down), game, game->lists.head_blue_down, game->medus_blue_pos);
	else if(game->medus_gamepath_blue == A && game->game_over != 1)
		medus_anim_left(&(game->lists.medus_blue_left), game, game->lists.head_blue_left, game->medus_blue_pos);
	else if(game->medus_gamepath_blue == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_blue_right), game, game->lists.head_blue_right, game->medus_blue_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_blue.ghost_down1, game->medus_blue_pos.x * SIZE, game->medus_blue_pos.y * SIZE);
}

void	enemy_image(t_gamedata *game)
{
	if(game->objects.enemies == 0)
		return ;
	ft_position(game->map, &(game->medus_green_pos), 'G');
	ft_position(game->map, &(game->medus_red_pos), 'R');
	ft_position(game->map, &(game->medus_blue_pos), 'B');
	ft_position(game->map, &(game->medus_purple_pos), 'D');
	anim_medus_moves_green(game);
	anim_medus_moves_blue(game);
	if(game->enemy_time == 16 && game->game_over != 1)
	{
		enemy_motion(game, game->medus_green_pos.y, game->medus_green_pos.x, 'G');
		enemy_motion(game, game->medus_blue_pos.y, game->medus_blue_pos.x, 'B');
		game->enemy_time = 0;
	}
	game->enemy_time += 1;
}

int	graphic_map(t_gamedata *game)
{
	size_t	y_axis;

	y_axis = -1;
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	if (game->game_over == 1)
		end_game(game);
	refresh_image(game);
	enemy_image(game);
	while ((game->map)[++y_axis])
		map_traversal((game->map)[y_axis], y_axis, game);
	return (0);
}
