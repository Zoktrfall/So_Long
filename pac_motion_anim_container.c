#include "so_long.h"

t_list	*ft_container_right(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.pac_man.pac_semi_right);
	head = add_to_end(head, game->sprites.pac_man.pac_open_right);
	head = add_to_end(head, game->sprites.pac_man.pac_semi_right);
	head = add_to_end(head, game->sprites.pac_man.pac_closed);
	return (head);
}

t_list	*ft_container_down(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.pac_man.pac_semi_down);
	head = add_to_end(head, game->sprites.pac_man.pac_open_down);
	head = add_to_end(head, game->sprites.pac_man.pac_semi_down);
	head = add_to_end(head, game->sprites.pac_man.pac_closed);
	return (head);
}

t_list	*ft_container_up(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.pac_man.pac_semi_up);
	head = add_to_end(head, game->sprites.pac_man.pac_open_up);
	head = add_to_end(head, game->sprites.pac_man.pac_semi_up);
	head = add_to_end(head, game->sprites.pac_man.pac_closed);
	return (head);
}

t_list	*ft_container_left(t_gamedata *game)
{
	t_list	*head;

	head = add_to_empty(head, game->sprites.pac_man.pac_semi_left);
	head = add_to_end(head, game->sprites.pac_man.pac_open_left);
	head = add_to_end(head, game->sprites.pac_man.pac_semi_left);
	head = add_to_end(head, game->sprites.pac_man.pac_closed);
	return (head);
}

void	ft_containers(t_gamedata *game)
{
	game->oper_left = ft_container_left(game);
	game->head_left = game->oper_left;
	game->oper_right = ft_container_right(game);
	game->head_right = game->oper_right;
	game->oper_up = ft_container_up(game);
	game->head_up = game->oper_up;
	game->oper_down = ft_container_down(game);
	game->head_down = game->oper_down;
	game->pac_dying = ft_container_dying(game);
	ft_containers_enemy_green(game);
}
