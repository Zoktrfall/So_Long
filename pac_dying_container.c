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
