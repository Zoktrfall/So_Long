#include "so_long.h"

int end_program()
{
	printf("hello\n");
	exit(0);
}

void	start_game(t_gamedata *game, char **map)
{
	game->mlx_ptr = mlx_init();
	creating_game(map, game);
	game->mlx_win = mlx_new_window(game->mlx_ptr, \
		game->x_axis * SIZE, game->y_axis * SIZE, "so_long");
	mlx_hook(game->mlx_win, 17, 0, end_program, game);
	mlx_loop_hook(game->mlx_ptr, graphic_map, game);
	mlx_key_hook(game->mlx_win, character_movement, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_gamedata	game;
	char		**map;

	if (args_verification(argc, argv, &map))
		return (0);
	start_game(&game, map);
	return (0);
}
