#include "so_long.h"

void	pacman_down(t_gamedata *game)
{
	if ((game->oper_down->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_down->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_down = game->oper_down->next;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_down->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_down = game->head_down;
	}
}

void	pacman_right(t_gamedata *game)
{
	if ((game->oper_right->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_right->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_right = game->oper_right->next;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_right->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_right = game->head_right;
	}
}

void	pacman_left(t_gamedata *game)
{
	if ((game->oper_left->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_left->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_left = game->oper_left->next;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_left->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_left = game->head_left;
	}
}

void	pacman_up(t_gamedata *game)
{
	if ((game->oper_up->next != NULL))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_up->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_up = game->oper_up->next;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->oper_up->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		game->oper_up = game->head_up;
	}
}
