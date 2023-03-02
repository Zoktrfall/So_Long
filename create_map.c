#include "so_long.h"

void	file_opening_error(void)
{
	write(1, "Error When Opening A File\n", 26);
	exit(0);
}

int	open_file(int fd, char *file_name)
{
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		file_opening_error();
	return (fd);
}

void	free_map(char ***str)
{
	int	i;

	i = 0;
	if (*str == NULL)
		return ;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}

char	**map_initialization(int fd)
{
	size_t	i;
	char	**new_map;
	char	**map;

	i = 0;
	map = NULL;
	while (1)
	{
		new_map = malloc(sizeof(char *) * (i + 2));
		new_map[i + 1] = NULL;
		if (new_map == NULL)
		{
			free_map(&map);
			exit(1);
		}
		map = ft_strcat(map, new_map, i);
		map[i] = get_next_line(fd, 0);
		if (map[i] == NULL)
			break ;
		i++;
	}
	get_next_line(fd, 1);
	return (map);
}

char	**create_map(char *file_name)
{
	int		fd;
	char	**map;

	fd = open_file(fd, file_name);
	map = map_initialization(fd);
	return (map);
}
