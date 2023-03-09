#include "so_long.h"

void	move_up(t_gamedata *game)
{
	size_t	x;
	size_t	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->map)[y - 1][x] == 'E')
	{
		mlx_destroy_image(game->mlx_ptr, game->mlx_win);
		exit(0);
	}
	if ((game->map)[y - 1][x] != '1')
	{
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->gamepath = W;
	}
}

void	move_down(t_gamedata *game)
{
	size_t	x;
	size_t	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->map)[y + 1][x] == 'E')
	{
		mlx_destroy_image(game->mlx_ptr, game->mlx_win);
		exit(0);
	}
	if ((game->map)[y + 1][x] != '1')
	{
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		game->gamepath = S;
	}
}

void	move_rigth(t_gamedata *game)
{
	size_t	x;
	size_t	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->map)[y][x + 1] == 'E')
	{
		mlx_destroy_image(game->mlx_ptr, game->mlx_win);
		exit(0);
	}
	if ((game->map)[y][x + 1] != '1')
	{
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		game->gamepath = D;
	}
}

void	move_left(t_gamedata *game)
{
	size_t	x;
	size_t	y;

	x = game->player.x;
	y = game->player.y;
	if ((game->map)[y][x - 1] == 'E')
	{
		mlx_destroy_image(game->mlx_ptr, game->mlx_win);
		exit(0);
	}
	if ((game->map)[y][x - 1] != '1')
	{
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->gamepath = A;
	}
}

int	character_movement(int key_code, t_gamedata *game)
{
	if (key_code == ESC)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		exit (0);
	}
	if (key_code == W)
		move_up(game);
	else if (key_code == S)
		move_down(game);
	else if (key_code == D)
		move_rigth(game);
	else if (key_code == A)
		move_left(game);
	return (0);
}
