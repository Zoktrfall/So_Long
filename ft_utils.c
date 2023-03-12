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

size_t	ft_log(size_t x, size_t y)
{
	size_t	i;
	size_t	n;

	i = 1;
	n = 4;
	while (n < x * y)
	{
		n = n * 2;
		++i;
	}
	if (i > 11)
		return (11);
	return (i);
}

char	**ft_strcat(char **map, char **new_map, size_t i)
{
	size_t	j;

	j = 0;
	if (map == NULL)
		return (new_map);
	while (j <= i && map[j] != NULL)
	{
		new_map[j] = map[j];
		j++;
	}
	free(map);
	return (new_map);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(str);
	j = 0;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr != NULL)
	{
		while (str[j] != '\0')
		{
			ptr[j] = str[j];
			j++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}
