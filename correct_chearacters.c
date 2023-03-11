#include "so_long.h"

int	chearacters(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'M' || str[i] == '0'
			|| str[i] == '1' || str[i] == 'E'
			|| str[i] == 'P' || str[i] == 'C')
			i++;
		else
			return (1);
	}
	return (0);
}

int	correct_chearacters(char **map, size_t len)
{
	size_t	y_axis;

	y_axis = 1;
	while (y_axis < len - 1)
	{
		if (chearacters(map[y_axis]))
			return (1);
		y_axis++;
	}
	return (0);
}

int	check_c_e_p(char **map)
{
	size_t	len;

	len = 0;
	while (map[len])
		len++;
	if (correct_chearacters(map, len))
		return (1);
	if (do_check_c_e_p(map, len))
		return (1);
	return (0);
}
