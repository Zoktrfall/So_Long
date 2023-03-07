#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_gamedata	game;
	char 		**map;

	if (args_verification(argc, argv, &map))
		return (0);
	int i, j;
	game.mlx_ptr = mlx_init();
	creating_game(map, &game);
	game.mlx_win = mlx_new_window(game.mlx_ptr, game.x_axis * SIZE, game.y_axis * SIZE, "Pac-Man");
	j = 0;
	i = 0;
	while((game.map)[i])
	{
		while((game.map)[i][j] != '\0')
		{
			if((game.map)[i][j] == '1')
				mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.sprites.walls , j * SIZE, i * SIZE);
			if((game.map)[i][j] == '0')
				mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.sprites.black , j * SIZE, i * SIZE);
			if((game.map)[i][j] == 'C')
				mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.sprites.coins , j * SIZE, i * SIZE);
			if((game.map)[i][j] == 'E')
				mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.sprites.portal , j * SIZE, i * SIZE);
			if((game.map)[i][j] == 'P')
				mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.sprites.pac_man.pac_closed , j * SIZE, i * SIZE);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_loop(game.mlx_ptr);
	free_map(&game.map);
	printf("\n");
	printf("continue\n");
	return (0);
}
