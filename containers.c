#include "so_long.h"

void	ft_containers_enemy(t_gamedata *game)
{
	ft_container_enemy_green(game);
	ft_container_enemy_red(game);
	ft_container_enemy_purple(game);
	ft_container_enemy_blue(game);
}

t_list	*ft_container_enemy(t_gamedata *game, void *sprite1, void *sprite2)
{
	t_list	*head;

	head = add_to_empty(head, sprite1);
	head = add_to_end(head, sprite2);
	return (head);
}

t_list	*ft_container_pacman(t_gamedata *game, void *sprite1, \
								void *sprite2, void *sprite3)
{
	t_list	*head;

	head = add_to_empty(head, sprite1);
	head = add_to_end(head, sprite2);
	head = add_to_end(head, sprite3);
	head = add_to_end(head, game->sprites.pac_man.pac_closed);
	return (head);
}

void	ft_containers(t_gamedata *game)
{
	ft_containers_pacman(game);
	ft_containers_enemy(game);
}
