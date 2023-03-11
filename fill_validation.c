#include "so_long.h"

int	error_valid_way(void)
{
	write(1, "Error\nIncorrect Map Configuration\n", 34);
	exit(0);
}

void	fill_validation(char **map, t_player play, t_objects *medus)
{
	if (map[play.y][play.x] == '5' || map[play.y][play.x] == '1')
		return ;
	if (map[play.y][play.x] == 'C')
		((*medus).coins)++;
	if (map[play.y][play.x] == 'E')
		((*medus).exit)++;
	if (map[play.y][play.x] == 'M')
		((*medus).enemies)++;
	map[play.y][play.x] = '5';
	fill_validation(map, (t_player){(play.x) + 1, (play.y)}, (medus));
	fill_validation(map, (t_player){(play.x), (play.y) + 1}, (medus));
	fill_validation(map, (t_player){(play.x) - 1, (play.y)}, (medus));
	fill_validation(map, (t_player){(play.x), (play.y) - 1}, (medus));
}

int	check_fill(char **map, t_objects medus)
{
	size_t	exit;
	size_t	coins;
	size_t	enemies;
	size_t	len;

	len = 0;
	exit = 1;
	while (map[len])
		len++;
	coins = count_coins(map, len);
	enemies = count_enemies(map, len);
	if (medus.coins == coins && medus.enemies == enemies && medus.exit == exit)
		return (0);
	return (1);
}

char	**creat_tmp(char **map)
{
	char	**tmp_map;
	size_t	len;

	len = 0;
	while (map[len])
		len++;
	tmp_map = malloc(sizeof(char *) * (len + 1));
	if (tmp_map == NULL)
	{
		free_map(&map);
		exit(1);
	}
	len = -1;
	while (map[++len])
	{
		tmp_map[len] = ft_strdup(map[len]);
		if (tmp_map[len] == NULL)
		{
			free_map(&map);
			free_map(&tmp_map);
			exit(1);
		}
	}
	tmp_map[len] = NULL;
	return (tmp_map);
}

int	valid_way(char **map)
{
	t_player	play;
	t_objects	medus;
	char		**tmp_map;

	medus.coins = 0;
	medus.enemies = 0;
	medus.exit = 0;
	tmp_map = creat_tmp(map);
	player_position(map, &play);
	fill_validation(tmp_map, play, &medus);
	free_map(&tmp_map);
	if (check_fill(map, medus))
		error_valid_way();
	return (0);
}
