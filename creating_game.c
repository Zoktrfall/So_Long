#include "so_long.h"

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
}
