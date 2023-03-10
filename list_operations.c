#include "so_long.h"

t_list	*add_to_empty(t_list *head, void *sprite)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list *));
	tmp->container = sprite;
	tmp->next = NULL;
	return (tmp);
}

t_list	*add_to_end(t_list *head, void *sprite)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = malloc(sizeof(t_list *));
	tmp2->container = sprite;
	tmp2->next = NULL;
	tmp = head;
	while (head->next != NULL)
		head = head->next;
	head->next = tmp2;
	head = tmp;
	return (head);
}
