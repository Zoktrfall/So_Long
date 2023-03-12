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
	game->sprites.logo = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Other/Logo/logo.xpm", &size, &size);
	game->sprites.pac_man = add_sprites_pacman(game);
	game->sprites.medus_green = add_sprites_medus_green(game, SIZE);
	game->sprites.medus_blue = add_sprites_medus_blue(game, SIZE);
	game->sprites.medus_purple = add_sprites_medus_purple(game, SIZE);
	game->sprites.medus_red = add_sprites_medus_red(game, SIZE);
	return (game->sprites);
}

void	creating_game(char **map, t_gamedata *game)
{
	size_t	x_axis;
	size_t	y_axis;

	x_axis = 0;
	y_axis = 0;
	game->map = map;
	while (map[y_axis])
		y_axis++;
	while (map[0][x_axis] != '\0')
		x_axis++;
	game->x_axis = x_axis;
	game->y_axis = y_axis;
	game->time_pac = 0;
	game->time_medus = 0;
	game->score = 0;
	game->game_over = 0;
	game->coins_score = 0;
	game->max_time = 12 - ft_log(game->x_axis, game->y_axis);
	game->enemy_time = 0;
	game->objects.coins = count_coins(map, y_axis);
	game->objects.enemies = count_enemies(map, y_axis);
	game->objects.exit = 1;
	game->medus_gamepath_green = -1;
	game->gamepath = -1;
	game->flag_dead = 0;
	game->sprites = ft_sprites(game);
	ft_containers(game);
}
