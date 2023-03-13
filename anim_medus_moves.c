#include "so_long.h"

void	medus_anim_up(t_list **sprite, t_gamedata *game, t_list *head, t_player pos)
{
	if ((*sprite)->next != NULL)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = (*sprite)->next;
		game->time_medus += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = head;
		game->time_medus += 1;
	}
	if (game->time_medus > game->max_time + 1)
		game->time_medus = 0;
}

void	medus_anim_down(t_list **sprite, t_gamedata *game, t_list *head, t_player pos)
{
	if ((*sprite)->next != NULL)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = (*sprite)->next;
		game->time_medus += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = head;
		game->time_medus += 1;
	}
	if (game->time_medus > game->max_time + 1)
		game->time_medus = 0;
}

void	medus_anim_left(t_list **sprite, t_gamedata *game, t_list *head, t_player pos)
{
	if ((*sprite)->next != NULL)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = (*sprite)->next;
		game->time_medus += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = head;
		game->time_medus += 1;
	}
	if (game->time_medus > game->max_time + 1)
		game->time_medus = 0;
}

void	medus_anim_right(t_list **sprite, t_gamedata *game, t_list *head, t_player pos)
{
	if ((*sprite)->next != NULL)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = (*sprite)->next;
		game->time_medus += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		(*sprite)->container, \
		pos.x * SIZE, pos.y * SIZE);
		if (game->time_medus == game->max_time + 1)
			(*sprite) = head;
		game->time_medus += 1;
	}
	if (game->time_medus > game->max_time + 1)
		game->time_medus = 0;
}
