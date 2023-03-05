#include "so_long.h"

int	map_verification(char **map)
{
	if (rectangular_map(map))
		return (error_rectangular());
	if (closed_surrounded(map))
		return (error_walls());
	if (check_c_e_p(map))
		return (error_c_e_p());
	if (valid_way(map))
		return (error_valid_way());
	return (0);
}

void	creating_game(char **map, t_gamedata *game)
{
	size_t	x_axis;
	size_t	y_axis;

	x_axis = 0;
	y_axis = 0;
	player_position(map, &(game->player));
	(*game).map = map;
	while(map[y_axis])
		y_axis++;
	while(map[0][x_axis] != '\0')
		x_axis++;
	(*game).x_axis = x_axis;
	(*game).y_axis = y_axis;
	(*game).score = 0;
	(*game).game_over = 0;
	(*game).coins_score = 0;
	(*game).objects.coins = count_coins(map, y_axis);
	(*game).objects.enemies = count_enemies(map, y_axis);
	(*game).objects.exit = 1;
	// creating_sprites(&game);
}

int	args_verification(int argc, char **argv, t_gamedata *game)
{
	char	**map;

	if (correct_arguments(argc, argv))
		return (1);
	map = create_map(argv[1]);
	if (map[0] == NULL)
		error_empty(map);
	if (divided_map(map))
		error_divided(map);
	map = optimization_map(map);
	if (map_verification(map))
	{
		free_map(&map);
		return (1);
	}
	creating_game(map, game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_gamedata	game;

	if (args_verification(argc, argv, &game))
		return (0);
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
	free_map(&game.map);
	printf("\n");
	printf("continue\n");
	return (0);
}
