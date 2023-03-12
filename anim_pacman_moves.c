#include "so_long.h"

void	pacman_down(t_gamedata *game)
{
	if ((game->lists.oper_down->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_down->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_down = game->lists.oper_down->next;
		game->time_pac += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_down->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_down = game->lists.head_down;
		game->time_pac += 1;
	}
	if (game->time_pac > game->max_time)
		game->time_pac = 0;
}

void	pacman_right(t_gamedata *game)
{
	if ((game->lists.oper_right->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_right->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_right = game->lists.oper_right->next;
		game->time_pac += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_right->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_right = game->lists.head_right;
		game->time_pac += 1;
	}
	if (game->time_pac > game->max_time)
		game->time_pac = 0;
}

void	pacman_left(t_gamedata *game)
{
	if ((game->lists.oper_left->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_left->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_left = game->lists.oper_left->next;
		game->time_pac += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_left->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_left = game->lists.head_left;
		game->time_pac += 1;
	}
	if (game->time_pac > game->max_time)
		game->time_pac = 0;
}

void	pacman_up(t_gamedata *game)
{
	if ((game->lists.oper_up->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_up->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_up = game->lists.oper_up->next;
		game->time_pac += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.oper_up->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.oper_up = game->lists.head_up;
		game->time_pac += 1;
	}
	if (game->time_pac > game->max_time)
		game->time_pac = 0;
}
