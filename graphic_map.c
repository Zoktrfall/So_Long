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
		monstr.color_medus = 0;
	else if(ft_strcmp_min(medus, 'R'))
		monstr.color_medus = 1;
	else if(ft_strcmp_min(medus, 'B'))
		monstr.color_medus = 2;
	else if(ft_strcmp_min(medus, 'D'))
		monstr.color_medus = 3;
	if (monstr.y == 0)
		follower_part1(game, monstr, x_axis, y_axis);
	else if(monstr.y > 0)
		follower_part2(game, monstr, x_axis, y_axis);
	else if (monstr.y < 0)
		follower_part3(game, monstr, x_axis, y_axis);
}

void	anim_medus_moves_green(t_gamedata *game)
{
	if(game->medus_gamepath_green == W && game->game_over != 1)
		medus_anim_up(&(game->lists.medus_green_up), game, game->lists.head_green_up, game->medus_green_pos);
	else if(game->medus_gamepath_green == S && game->game_over != 1)
		medus_anim_down(&(game->lists.medus_green_down), game, game->lists.head_green_down, game->medus_green_pos);
	else if(game->medus_gamepath_green == A && game->game_over != 1)
		medus_anim_left(&(game->lists.medus_green_left), game, game->lists.head_green_left, game->medus_green_pos);
	else if(game->medus_gamepath_green == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_green_right), game, game->lists.head_green_right, game->medus_green_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_green.ghost_down1, game->medus_green_pos.x * SIZE, game->medus_green_pos.y * SIZE);
}

void	anim_medus_moves_blue(t_gamedata *game)
{
	if(game->medus_gamepath_blue == W && game->game_over != 1)
		medus_anim_up(&(game->lists.medus_blue_up), game, game->lists.head_blue_up, game->medus_blue_pos);
	else if(game->medus_gamepath_blue == S && game->game_over != 1)
		medus_anim_down(&(game->lists.medus_blue_down), game, game->lists.head_blue_down, game->medus_blue_pos);
	else if(game->medus_gamepath_blue == A && game->game_over != 1)
		medus_anim_left(&(game->lists.medus_blue_left), game, game->lists.head_blue_left, game->medus_blue_pos);
	else if(game->medus_gamepath_blue == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_blue_right), game, game->lists.head_blue_right, game->medus_blue_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_blue.ghost_down1, game->medus_blue_pos.x * SIZE, game->medus_blue_pos.y * SIZE);
}

void	anim_medus_moves_purple(t_gamedata *game)
{
	if(game->medus_gamepath_purple == W && game->game_over != 1)
		medus_anim_up(&(game->lists.medus_purple_up), game, game->lists.head_purple_up, game->medus_purple_pos);
	else if(game->medus_gamepath_purple == S && game->game_over != 1)
		medus_anim_down(&(game->lists.medus_purple_down), game, game->lists.head_purple_down, game->medus_purple_pos);
	else if(game->medus_gamepath_purple == A && game->game_over != 1)
		medus_anim_left(&(game->lists.medus_purple_left), game, game->lists.head_purple_left, game->medus_purple_pos);
	else if(game->medus_gamepath_blue == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_purple_right), game, game->lists.head_purple_right, game->medus_purple_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_purple.ghost_down1, game->medus_purple_pos.x * SIZE, game->medus_purple_pos.y * SIZE);
}

void	anim_medus_moves_red(t_gamedata *game)
{
	if(game->medus_gamepath_red == W && game->game_over != 1)
		medus_anim_up(&(game->lists.medus_red_up), game, game->lists.head_red_up, game->medus_red_pos);
	else if(game->medus_gamepath_blue == S && game->game_over != 1)
		medus_anim_down(&(game->lists.medus_red_down), game, game->lists.head_red_down, game->medus_red_pos);
	else if(game->medus_gamepath_red == A && game->game_over != 1)
		medus_anim_left(&(game->lists.medus_red_left), game, game->lists.head_red_left, game->medus_red_pos);
	else if(game->medus_gamepath_blue == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_red_right), game, game->lists.head_red_right, game->medus_red_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_red.ghost_down1, game->medus_red_pos.x * SIZE, game->medus_red_pos.y * SIZE);
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
