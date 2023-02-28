#include "so_long.h"

void	error_map(void)
{
	write(2, "The map is incorrect\n", 21);
	exit (0);
}
