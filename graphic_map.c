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
		if (map[x_axis] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.black, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.coins, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.portal, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == 'P')
		{
			game->player.x = x_axis;
			game->player.y = y_axis;
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.pac_man.pac_closed, x_axis * SIZE, y_axis * SIZE);
		}
	}
}

void	refresh_image(t_gamedata *game)
{
	size_t	y_axis;

	y_axis = 0;
	while ((game->map)[y_axis])
	{
		map_traversal((game->map)[y_axis], y_axis, game);
		y_axis++;
	}
	mlx_hook(game->mlx_win, 2, 1L << 0, character_movement, game);
}
