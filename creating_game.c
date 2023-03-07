#include "so_long.h"

t_sprites	ft_sprites(t_gamedata *game)
{
	int	size;

	size = SIZE;
	game->sprites.walls = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Other/Walls/wall.xpm", &size, &size);
	game->sprites.black = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Other/Walls/black.xpm", &size, &size);
	game->sprites.coins = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Other/Pacdots/pacdot_food.xpm", &size, &size);
	game->sprites.portal = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Other/Portal/portal.xpm", &size, &size);
	return (game->sprites);
}

void	creating_game(char **map, t_gamedata *game)
{
	size_t	x_axis;
	size_t	y_axis;

	x_axis = 0;
	y_axis = 0;
	player_position(map, &(game->player));
	game->map = map;
	while (map[y_axis])
		y_axis++;
	while (map[0][x_axis] != '\0')
		x_axis++;
	game->x_axis = x_axis;
	game->y_axis = y_axis;
	game->score = 0;
	game->game_over = 0;
	game->coins_score = 0;
	game->objects.coins = count_coins(map, y_axis);
	game->objects.enemies = count_enemies(map, y_axis);
	game->objects.exit = 1;
	game->sprites = ft_sprites(game);
}
