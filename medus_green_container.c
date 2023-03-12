#include "so_long.h"

t_list	*ft_container_enemy_green_right(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.medus_green.ghost_right1);
	head = add_to_end(head, game->sprites.medus_green.ghost_right2);
	return (head);
}

t_list	*ft_container_enemy_green_down(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.medus_green.ghost_down1);
	head = add_to_end(head, game->sprites.medus_green.ghost_down2);
	return (head);
}

t_list	*ft_container_enemy_green_up(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.medus_green.ghost_up1);
	head = add_to_end(head, game->sprites.medus_green.ghost_up2);
	return (head);
}

t_list	*ft_container_enemy_green_left(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.medus_green.ghost_left1);
	head = add_to_end(head, game->sprites.medus_green.ghost_left2);
	return (head);
}

void	ft_containers_enemy_green(t_gamedata *game)
{
    game->medus_green_down = ft_container_enemy_green_down(game);
    game->head_green_down = game->medus_green_down;
    game->medus_green_up = ft_container_enemy_green_up(game);
    game->head_green_up = game->medus_green_up;
    game->medus_green_left = ft_container_enemy_green_left(game);
    game->head_green_left = game->medus_green_left;
    game->medus_green_right = ft_container_enemy_green_right(game);
    game->head_green_right = game->medus_green_right;
}
