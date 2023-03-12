#include "so_long.h"

t_enemy	add_sprites_medus_green(t_gamedata *game, int size)
{
	game->sprites.medus_green.ghost_down1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_down1.xpm", &size, &size);
	game->sprites.medus_green.ghost_down2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_down2.xpm", &size, &size);
	game->sprites.medus_green.ghost_left1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_left1.xpm", &size, &size);
	game->sprites.medus_green.ghost_left2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_left2.xpm", &size, &size);
	game->sprites.medus_green.ghost_right1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_right1.xpm", &size, &size);
	game->sprites.medus_green.ghost_right2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_right2.xpm", &size, &size);
	game->sprites.medus_green.ghost_up1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_up1.xpm", &size, &size);
	game->sprites.medus_green.ghost_up2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/G/ghost_up2.xpm", &size, &size);
	return (game->sprites.medus_green);
}

t_enemy	add_sprites_medus_blue(t_gamedata *game, int size)
{
	game->sprites.medus_blue.ghost_down1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_down1.xpm", &size, &size);
	game->sprites.medus_blue.ghost_down2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_down2.xpm", &size, &size);
	game->sprites.medus_blue.ghost_left1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_left1.xpm", &size, &size);
	game->sprites.medus_blue.ghost_left2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_left2.xpm", &size, &size);
	game->sprites.medus_blue.ghost_right1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_right1.xpm", &size, &size);
	game->sprites.medus_blue.ghost_right2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_right2.xpm", &size, &size);
	game->sprites.medus_blue.ghost_up1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_up1.xpm", &size, &size);
	game->sprites.medus_blue.ghost_up2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/B/ghost_up2.xpm", &size, &size);
	return (game->sprites.medus_blue);
}

t_enemy	add_sprites_medus_red(t_gamedata *game, int size)
{
	game->sprites.medus_red.ghost_down1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_down1.xpm", &size, &size);
	game->sprites.medus_red.ghost_down2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_down2.xpm", &size, &size);
	game->sprites.medus_red.ghost_left1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_left1.xpm", &size, &size);
	game->sprites.medus_red.ghost_left2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_left2.xpm", &size, &size);
	game->sprites.medus_red.ghost_right1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_right1.xpm", &size, &size);
	game->sprites.medus_red.ghost_right2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_right2.xpm", &size, &size);
	game->sprites.medus_red.ghost_up1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_up1.xpm", &size, &size);
	game->sprites.medus_red.ghost_up2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/R/ghost_up2.xpm", &size, &size);
	return (game->sprites.medus_red);
}

t_enemy	add_sprites_medus_purple(t_gamedata *game, int size)
{
	game->sprites.medus_purple.ghost_down1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_down1.xpm", &size, &size);
	game->sprites.medus_purple.ghost_down2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_down2.xpm", &size, &size);
	game->sprites.medus_purple.ghost_left1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_left1.xpm", &size, &size);
	game->sprites.medus_purple.ghost_left2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_left2.xpm", &size, &size);
	game->sprites.medus_purple.ghost_right1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_right1.xpm", &size, &size);
	game->sprites.medus_purple.ghost_right2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_right2.xpm", &size, &size);
	game->sprites.medus_purple.ghost_up1 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_up1.xpm", &size, &size);
	game->sprites.medus_purple.ghost_up2 = \
		mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/Ghosts/P/ghost_up2.xpm", &size, &size);
	return (game->sprites.medus_purple);
}
