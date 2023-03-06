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
	game.mlx_win = mlx_new_window(game.mlx_ptr, 500, 500, "Pac-Man");
	void *gabess = mlx_xpm_file_to_image(game.mlx_ptr, "sprites/Other/Walls/wall.xpm", &fx,&fy);
	mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, gabess,0 , 0);
	mlx_loop(game.mlx_ptr);





	// free_map(&game.map);
	printf("\n");
	printf("continue\n");
	return (0);
}
