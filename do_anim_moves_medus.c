#include "so_long.h"

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
	else if(game->medus_gamepath_purple == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_purple_right), game, game->lists.head_purple_right, game->medus_purple_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_purple.ghost_down1, game->medus_purple_pos.x * SIZE, game->medus_purple_pos.y * SIZE);
}

void	anim_medus_moves_red(t_gamedata *game)
{
	if(game->medus_gamepath_red == W && game->game_over != 1)
		medus_anim_up(&(game->lists.medus_red_up), game, game->lists.head_red_up, game->medus_red_pos);
	else if(game->medus_gamepath_red == S && game->game_over != 1)
		medus_anim_down(&(game->lists.medus_red_down), game, game->lists.head_red_down, game->medus_red_pos);
	else if(game->medus_gamepath_red == A && game->game_over != 1)
		medus_anim_left(&(game->lists.medus_red_left), game, game->lists.head_red_left, game->medus_red_pos);
	else if(game->medus_gamepath_red == D && game->game_over != 1)
		medus_anim_right(&(game->lists.medus_red_right), game, game->lists.head_red_right, game->medus_red_pos);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
		game->sprites.medus_red.ghost_down1, game->medus_red_pos.x * SIZE, game->medus_red_pos.y * SIZE);
}
