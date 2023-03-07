#include "so_long.h"

void	start_game(t_gamedata *game)
{
	refresh_image(game);
}

int	main(int argc, char *argv[])
{
	t_gamedata	game;
	char		**map;

	if (args_verification(argc, argv, &map))
		return (0);
	game.mlx_ptr = mlx_init();
	creating_game(map, &game);
	game.mlx_win = mlx_new_window(game.mlx_ptr, game.x_axis * SIZE, game.y_axis * SIZE, "Pac-Man");
	start_game(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
