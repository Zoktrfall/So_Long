#include "so_long.h"

t_pacman	add_sprites_pacman(t_gamedata *game)
{
	int	size;

	size = SIZE;
	game->sprites.pac_man.pac_closed = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_closed.xpm", &size, &size);
	game->sprites.pac_man.pac_open_down = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_open_down.xpm", &size, &size);
	game->sprites.pac_man.pac_open_left = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_open_left.xpm", &size, &size);
	game->sprites.pac_man.pac_open_right = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_open_right.xpm", &size, &size);
	game->sprites.pac_man.pac_open_up = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_open_up.xpm", &size, &size);
	game->sprites.pac_man.pac_semi_down = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_semi_down.xpm", &size, &size);
	game->sprites.pac_man.pac_semi_left = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_semi_left.xpm", &size, &size);
	game->sprites.pac_man.pac_semi_right = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_semi_right.xpm", &size, &size);
	game->sprites.pac_man.pac_semi_up = mlx_xpm_file_to_image(game->mlx_ptr, \
			"sprites/Pac-Man/pac_semi_up.xpm", &size, &size);
	return (game->sprites.pac_man);
}

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
	game->sprites.pac_man = add_sprites_pacman(game);
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
	player_position(map, &(game->player));
	game->x_axis = x_axis;
	game->y_axis = y_axis;
	game->score = 0;
	game->game_over = 0;
	game->coins_score = 0;
	game->objects.coins = count_coins(map, y_axis);
	game->objects.enemies = count_enemies(map, y_axis);
	game->objects.exit = 1;
	game->gamepath = -1;
	game->sprites = ft_sprites(game);
	ft_containers(game);
}
