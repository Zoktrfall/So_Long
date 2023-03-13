#include "so_long.h"

void	map_traversal(char *map, size_t y_axis, t_gamedata *game)
{
	size_t	x_axis;

	x_axis = -1;
	while (map[++x_axis] != '\0')
	{
		if (map[x_axis] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.walls, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.coins, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.portal, x_axis * SIZE, y_axis * SIZE);
		if (map[x_axis] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->sprites.black, x_axis * SIZE, y_axis * SIZE);
	}
}

int	refresh_image(t_gamedata *game)
{
	ft_position(game->map, &(game->player), 'P');
	if (game->gamepath == S && game->game_over != 1)
		pacman_down(game);
	else if (game->gamepath == W && game->game_over != 1)
		pacman_up(game);
	else if (game->gamepath == A && game->game_over != 1)
		pacman_left(game);
	else if (game->gamepath == D && game->game_over != 1)
		pacman_right(game);
	else if (game->game_over != 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.pac_man.pac_closed, \
		game->player.x * SIZE, game->player.y * SIZE);
	return (0);
}

void enemy_motion(t_gamedata *game, int y_axis, int x_axis, char medus)
{
	t_follower monstr;

	monstr.x = x_axis - game->player.x;
	monstr.y = y_axis - game->player.y;
	monstr.tmp = '0';
	monstr.medus = medus;
	if(ft_strcmp_min(medus, 'G'))
		monstr.color_medus = green;
	else if(ft_strcmp_min(medus, 'R'))
		monstr.color_medus = red;
	else if(ft_strcmp_min(medus, 'B'))
		monstr.color_medus = blue;
	else if(ft_strcmp_min(medus, 'D'))
		monstr.color_medus = purple;
	if (monstr.y == 0)
		follower_part1(game, monstr, x_axis, y_axis);
	else if(monstr.y > 0)
		follower_part2(game, monstr, x_axis, y_axis);
	else if (monstr.y < 0)
		follower_part3(game, monstr, x_axis, y_axis);
}

void	enemy_image(t_gamedata *game)
{
	if(game->objects.enemies == 0)
		return ;
	ft_position(game->map, &(game->medus_green_pos), 'G');
	ft_position(game->map, &(game->medus_red_pos), 'R');
	ft_position(game->map, &(game->medus_blue_pos), 'B');
	ft_position(game->map, &(game->medus_purple_pos), 'D');
	anim_medus_moves_green(game);
	anim_medus_moves_blue(game);
	anim_medus_moves_red(game);
	anim_medus_moves_purple(game);
	if(game->enemy_time == 16 && game->game_over != 1)
	{
		enemy_motion(game, game->medus_green_pos.y, game->medus_green_pos.x, 'G');
		enemy_motion(game, game->medus_blue_pos.y, game->medus_blue_pos.x, 'B');
		enemy_motion(game, game->medus_red_pos.y, game->medus_red_pos.x, 'R');
		enemy_motion(game, game->medus_purple_pos.y, game->medus_purple_pos.x, 'D');
		game->enemy_time = 0;
	}
	game->enemy_time += 1;
}

int	graphic_map(t_gamedata *game)
{
	size_t	y_axis;

	y_axis = -1;
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	if (game->game_over == 1)
		end_game(game);
	refresh_image(game);
	enemy_image(game);
	while ((game->map)[++y_axis])
		map_traversal((game->map)[y_axis], y_axis, game);
	return (0);
}
