#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_gamedata	game;
	char 		**map;

	if (args_verification(argc, argv, &map))
		return (0);
	creating_game(map, &game);
	printf("y_axis = %zu\n", game.y_axis);
	printf("x_axis = %zu\n", game.x_axis);
	printf("player pos x = %zu\n", game.player.x);
	printf("player pos y = %zu\n", game.player.y);
	printf("score = %zu\n", game.score);
	printf("objects coins = %zu\n", game.objects.coins);
	printf("objects enemies= %zu\n", game.objects.enemies);
	printf("objects exit = %zu\n", game.objects.exit);
	printf("game over = %zu\n", game.game_over);
	printf("coints_score = %zu\n", game.coins_score);
	int i = 0;
	while(game.map[i])
	{
		printf("%s", game.map[i]);
		i++;
	}
	int fx = 32, fy = 32;
	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, game.x_axis * SIZE, game.y_axis * SIZE, "Pac-Man");
	int j = 0;
	game.sprites = ft_sprites(&game);
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
			j++;
		}
		j = 0;
		i++;
	}
	mlx_loop(game.mlx_ptr);
	// free_map(&game.map);
	printf("\n");
	printf("continue\n");
	return (0);
}
