#include "so_long.h"

void	pac_dead_animation(t_gamedata *game)
{
	if (game->lists.pac_dying->next != NULL)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.pac_dying->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
			game->lists.pac_dying = game->lists.pac_dying->next;
		game->time_pac += 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->lists.pac_dying->container, \
		game->player.x * SIZE, game->player.y * SIZE);
		if (game->time_pac == game->max_time)
		{
			game->lists.pac_dying = game->lists.dying_head;
			game->flag_dead = 1;
		}
		game->time_pac += 1;
	}
	if (game->time_pac > game->max_time)
		game->time_pac = 0;
}

void	end_game(t_gamedata *game)
{
	if (game->flag_dead == 1)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		exit(0);
	}
	pac_dead_animation(game);
}
