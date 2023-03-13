#include "so_long.h"

void	ft_container_enemy_green(t_gamedata *game)
{
	game->lists.medus_green_down = ft_container_enemy(game, \
	game->sprites.medus_green.ghost_down1, \
	game->sprites.medus_green.ghost_down2);
	game->lists.head_green_down = game->lists.medus_green_down;
	game->lists.medus_green_up = ft_container_enemy(game, \
	game->sprites.medus_green.ghost_up1, \
	game->sprites.medus_green.ghost_up2);
	game->lists.head_green_up = game->lists.medus_green_up;
	game->lists.medus_green_left = ft_container_enemy(game, \
	game->sprites.medus_green.ghost_left1, \
	game->sprites.medus_green.ghost_left2);
	game->lists.head_green_left = game->lists.medus_green_left;
	game->lists.medus_green_right = ft_container_enemy(game, \
	game->sprites.medus_green.ghost_right1, \
	game->sprites.medus_green.ghost_right2);
	game->lists.head_green_right = game->lists.medus_green_right;
}

void	ft_container_enemy_red(t_gamedata *game)
{
	game->lists.medus_red_down = ft_container_enemy(game, \
	game->sprites.medus_red.ghost_down1, \
	game->sprites.medus_red.ghost_down2);
	game->lists.head_red_down = game->lists.medus_red_down;
	game->lists.medus_red_up = ft_container_enemy(game, \
	game->sprites.medus_red.ghost_up1, \
	game->sprites.medus_red.ghost_up2);
	game->lists.head_red_up = game->lists.medus_red_up;
	game->lists.medus_red_left = ft_container_enemy(game, \
	game->sprites.medus_red.ghost_left1, \
	game->sprites.medus_red.ghost_left2);
	game->lists.head_red_left = game->lists.medus_red_left;
	game->lists.medus_red_right = ft_container_enemy(game, \
	game->sprites.medus_red.ghost_right1, \
	game->sprites.medus_red.ghost_right2);
	game->lists.head_red_right = game->lists.medus_red_right;
}

void	ft_container_enemy_blue(t_gamedata *game)
{
	game->lists.medus_blue_down = ft_container_enemy(game, \
	game->sprites.medus_blue.ghost_down1, \
	game->sprites.medus_blue.ghost_down2);
	game->lists.head_blue_down = game->lists.medus_blue_down;
	game->lists.medus_blue_up = ft_container_enemy(game, \
	game->sprites.medus_blue.ghost_up1, \
	game->sprites.medus_blue.ghost_up2);
	game->lists.head_blue_up = game->lists.medus_blue_up;
	game->lists.medus_blue_left = ft_container_enemy(game, \
	game->sprites.medus_blue.ghost_left1, \
	game->sprites.medus_blue.ghost_left2);
	game->lists.head_blue_left = game->lists.medus_blue_left;
	game->lists.medus_blue_right = ft_container_enemy(game, \
	game->sprites.medus_blue.ghost_right1, \
	game->sprites.medus_blue.ghost_right2);
	game->lists.head_blue_right = game->lists.medus_blue_right;
}

void	ft_container_enemy_purple(t_gamedata *game)
{
	game->lists.medus_purple_down = ft_container_enemy(game, \
	game->sprites.medus_purple.ghost_down1, \
	game->sprites.medus_purple.ghost_down2);
	game->lists.head_purple_down = game->lists.medus_purple_down;
	game->lists.medus_purple_up = ft_container_enemy(game, \
	game->sprites.medus_purple.ghost_up1, \
	game->sprites.medus_purple.ghost_up2);
	game->lists.head_purple_up = game->lists.medus_purple_up;
	game->lists.medus_purple_left = ft_container_enemy(game, \
	game->sprites.medus_purple.ghost_left1, \
	game->sprites.medus_purple.ghost_left2);
	game->lists.head_purple_left = game->lists.medus_purple_left;
	game->lists.medus_purple_right = ft_container_enemy(game, \
	game->sprites.medus_purple.ghost_right1, \
	game->sprites.medus_purple.ghost_right2);
	game->lists.head_purple_right = game->lists.medus_purple_right;
}
