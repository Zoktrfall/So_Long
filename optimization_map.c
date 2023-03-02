#include "so_long.h"

int	unprinted(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 0 && str[i] <= 31))
			return (0);
		i++;
	}
	return (1);
}

size_t	counts(char **map)
{
	size_t	size;
	size_t	size_new;

	size = 0;
	size_new = 0;
	while (map[size])
	{
		if (!unprinted(map[size]))
			size_new++;
		size++;
	}
	return (size_new);
}

char	**optimization_map(char **map)
{
	char	**new_map;
	size_t	size;
	size_t	size_new;

	size_new = counts(map);
	new_map = malloc(sizeof(char *) * (size_new + 1));
	if (new_map == NULL)
	{
		free_map(&map);
		exit(1);
	}
	size = 0;
	size_new = 0;
	while (map[size])
	{
		if (!unprinted(map[size]))
			new_map[size_new++] = map[size];
		else
			free(map[size]);
		size++;
	}
	new_map[size_new] = NULL;
	free(map);
	return (new_map);
}
