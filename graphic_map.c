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
	}
}

int	refresh_image(t_gamedata *game)
{
	player_position(game->map, &(game->player));
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

void enemy_motion_green(t_gamedata *game)
{
	int	x_axis;
	int	y_axis;
	int	x;
	int	y;
	char	tmp;

	x_axis = game->medus_green_pos.x;
	y_axis = game->medus_green_pos.y;
	x = game->medus_green_pos.x - game->player.x;
	y = game->medus_green_pos.y - game->player.y;
	if(y == 0)
	{
		if(x > 0)
		{
			if((game->map)[y_axis][x_axis - 1] != '1')
			{
				(game->map)[y_axis][x_axis - 1] = 'M';
				(game->map)[y_axis][x_axis] = '0';
				game->medus_gamepath_green = A;
			}
			else if((game->map)[y_axis][x_axis - 1] == '1')
			{
				if((game->map)[y_axis - 1][x_axis] != '1')
				{
					(game->map)[y_axis - 1][x_axis] = 'M';
					(game->map)[y_axis][x_axis] = '0';
					game->medus_gamepath_green = W;
				}
				else if((game->map)[y_axis + 1][x_axis] != '1')
				{
					(game->map)[y_axis + 1][x_axis] = 'M';
					(game->map)[y_axis][x_axis] = '0';
					game->medus_gamepath_green = S;
				}
				else if((game->map)[y_axis][x_axis + 1] != '1')
				{
					(game->map)[y_axis][x_axis + 1] = 'M';
					(game->map)[y_axis][x_axis] = '0';
					game->medus_gamepath_green = D;
				}
			}
		}
		else if (x < 0)
		{
			if((game->map)[y_axis][x_axis + 1] != '1')
			{
				(game->map)[y_axis][x_axis + 1] = 'M';
				(game->map)[y_axis][x_axis] = '0';
				game->medus_gamepath_green = D;
			}
			else if((game->map)[y_axis][x_axis + 1] == '1')
			{
				if((game->map)[y_axis + 1][x_axis] != '1')
				{
					(game->map)[y_axis + 1][x_axis] = 'M';
					(game->map)[y_axis][x_axis] = '0';
					game->medus_gamepath_green = S;
				}
				else if((game->map)[y_axis - 1][x_axis] != '1')
				{
					(game->map)[y_axis - 1][x_axis] = 'M';
					(game->map)[y_axis][x_axis] = '0';
					game->medus_gamepath_green = W;
				}
				else if((game->map)[y_axis][x_axis - 1] != '1')
				{
					(game->map)[y_axis][x_axis - 1] = 'M';
					(game->map)[y_axis][x_axis] = '0';
					game->medus_gamepath_green = A;
				}
			}
		}
	}
	else if(y > 0)
	{
		if((game->map)[y_axis - 1][x_axis] != '1')
		{
			(game->map)[y_axis - 1][x_axis] = 'M';
			(game->map)[y_axis][x_axis] = '0';
			game->medus_gamepath_green = W;
		}
		else if(x > 0)
		{
			if((game->map)[y_axis][x_axis - 1] != '1')
			{
				(game->map)[y_axis][x_axis - 1] = 'M';
				(game->map)[y_axis][x_axis] = '0';
				game->medus_gamepath_green = A;
			}
		}
		else if (x < 0)
		{
			if((game->map)[y_axis][x_axis + 1] != '1')
			{
				(game->map)[y_axis][x_axis + 1] = 'M';
				(game->map)[y_axis][x_axis] = '0';
				game->medus_gamepath_green = D;
			}
		}
		else if ((game->map)[y_axis + 1][x_axis] != '1')
		{
			(game->map)[y_axis + 1][x_axis] = 'M';
			(game->map)[y_axis][x_axis] = '0';
			game->medus_gamepath_green = S;
		}
	}
	else if (y < 0)
	{
		if((game->map)[y_axis + 1][x_axis] != '1')
		{
			(game->map)[y_axis + 1][x_axis] = 'M';
			(game->map)[y_axis][x_axis] = '0';
			game->medus_gamepath_green = S;
		}
		else if(x > 0)
		{
			if((game->map)[y_axis][x_axis - 1] != '1')
			{
				(game->map)[y_axis][x_axis - 1] = 'M';
				(game->map)[y_axis][x_axis] = '0';
				game->medus_gamepath_green = A;
			}
		}
		else if (x < 0)
		{
			if((game->map)[y_axis][x_axis + 1] != '1')
			{
				(game->map)[y_axis][x_axis + 1] = 'M';
				(game->map)[y_axis][x_axis] = '0';
				game->medus_gamepath_green = D;
			}
		}
		else if((game->map)[y_axis - 1][x_axis] != '1')
		{
			(game->map)[y_axis - 1][x_axis] = 'M';
			(game->map)[y_axis][x_axis] = '0';
			game->medus_gamepath_green = W;
		}
	}
}

void	anim_medus_green_moves(t_gamedata *game)
{
	if(game->medus_gamepath_green == W)
		medus_anim_up(&(game->medus_green_up), game, game->head_green_up);
	else if(game->medus_gamepath_green == S)
		medus_anim_down(&(game->medus_green_down), game, game->head_green_down);
	else if(game->medus_gamepath_green == A)
		medus_anim_left(&(game->medus_green_left), game, game->head_green_left);
	else if(game->medus_gamepath_green == D)
		medus_anim_right(&(game->medus_green_right), game, game->head_green_right);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_green.ghost_down1, game->medus_green_pos.x * SIZE, game->medus_green_pos.y * SIZE);
}

void	enemy_image(t_gamedata *game)
{
	medus_g_position(game->map, &(game->medus_green_pos));
	anim_medus_green_moves(game);
	if(game->fol_med == 18)
	{
		enemy_motion_green(game);
		game->fol_med = 0;
	}
	game->fol_med += 1;
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
