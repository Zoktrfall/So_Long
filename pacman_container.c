#include "so_long.h"

t_list	*ft_container_dying(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.pac_man.dead.dying1);
	head = add_to_end(head, game->sprites.pac_man.dead.dying2);
	head = add_to_end(head, game->sprites.pac_man.dead.dying3);
	head = add_to_end(head, game->sprites.pac_man.dead.dying4);
	head = add_to_end(head, game->sprites.pac_man.dead.dying5);
	head = add_to_end(head, game->sprites.pac_man.dead.dying6);
	head = add_to_end(head, game->sprites.pac_man.dead.dying7);
	head = add_to_end(head, game->sprites.pac_man.dead.dying8);
	head = add_to_end(head, game->sprites.pac_man.dead.dying9);
	head = add_to_end(head, game->sprites.pac_man.dead.dying10);
	head = add_to_end(head, game->sprites.pac_man.dead.whoosh);
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

void	ft_containers_pacman(t_gamedata *game)
{
	game->oper_left = ft_container_pacman(game, \
	game->sprites.pac_man.pac_semi_left, game->sprites.pac_man.pac_open_left, \
	game->sprites.pac_man.pac_semi_left);
	game->head_left = game->oper_left;
	game->oper_right = ft_container_pacman(game, \
	game->sprites.pac_man.pac_semi_right, game->sprites.pac_man.pac_open_right, \
	game->sprites.pac_man.pac_semi_right);
	game->head_right = game->oper_right;
	game->oper_up = ft_container_pacman(game, \
	game->sprites.pac_man.pac_semi_up, game->sprites.pac_man.pac_open_up, \
	game->sprites.pac_man.pac_semi_up);
	game->head_up = game->oper_up;
	game->oper_down = ft_container_pacman(game, \
	game->sprites.pac_man.pac_semi_down, game->sprites.pac_man.pac_open_down, \
	game->sprites.pac_man.pac_semi_down);
	game->head_down = game->oper_down;
	game->pac_dying = ft_container_dying(game);
}

void	ft_containers(t_gamedata *game)
{
	ft_containers_pacman(game);
	ft_containers_enemy(game);
}
