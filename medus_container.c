#include "so_long.h"

t_list	*ft_container_enemy(t_gamedata *game, void *sprite1, void *sprite2)
{
	t_list	*head;

	head = add_to_empty(head, sprite1);
	head = add_to_end(head, sprite2);
	return (head);
}

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

void	ft_containers_enemy(t_gamedata *game)
{
	ft_container_enemy_green(game);
}
