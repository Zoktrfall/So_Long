#include "so_long.h"
#include <stdio.h>

// char **ft_strcat(char **map, char **new_map, size_t i)
// {
// 	size_t j;

// 	j = 0;
// 	if (map == NULL)
// 		return (new_map);
// 	while (j <= i && map[j] != NULL)
// 	{
// 		new_map[j] = map[j];
// 		j++;
// 	}
// 	free(map);
// 	return (new_map);
// }

// void map_initialization(t_game *game, int argc, char **argv)
// {
// 	size_t	i;
// 	char	**new_map;
// 	char 	**map;
// 	int		fd;

// 	i = 0;
// 	map = NULL;
// 	fd = open_your_map();
// 	while (1)
// 	{
// 		new_map = malloc(sizeof(char *) * (i + 2));
// 		if (new_map == NULL)
// 			return ;
// 		map = ft_strcat(map, new_map, i);
// 		new_map = NULL;
// 		map[i] = get_next_line(fd, 0);
// 		if (map[i] == NULL)
// 			break;
// 		map[++i] = NULL;
// 	}
// 	get_next_line(fd, 1);
// }

int	print_one_argument_error(void)
{
	write(1, "Please Enter A Map Name\n", 24);
	return (1);
}

void	print_warning(void)
{
	write(1, "Only The First File Would Be Used\n", 34);
}

int print_file_error(void)
{
	write(1, "Map Should Be A (*.ber) File\n", 29);
	return (1);
}

int	check_ber(char *arg, char *ber)
{
	size_t	len_arg;
	size_t	len_ber;

	len_arg = ft_strlen(arg);
	len_ber = ft_strlen(ber);
	if (len_arg == len_ber)
		return (1);
	while (len_ber > 0)
	{
		--len_arg;
		--len_ber;
		if (arg[len_arg] != ber[len_ber])
			return (1);
	}
	if (arg[--len_arg] == ' ' || arg[--len_arg] == '\t')
		return (1);
	return (0);
}

int	correct_arguments(int argc, char **argv)
{
	if (argc == 1)
		return (print_one_argument_error());
	if (argc > 2)
		print_warning();
	if (check_ber(argv[1], ".ber"))
		return (print_file_error());
	return (0);
}

int	main(int argc, char *argv[])
{
	if(correct_arguments(argc, argv))
		return (0);
	printf("continue\n");
	return (0);
}