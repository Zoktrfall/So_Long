#include "so_long.h"

void	pacman_down(t_gamedata *game)
{
	static int	counter1;

	counter1++;
	if (counter1 == game->sprites.pac_man.state)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_down;
	else if (counter1 == game->sprites.pac_man.state * 2)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_open_down;
	else if (counter1 == game->sprites.pac_man.state * 4)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_down;
	else if (counter1 >= game->sprites.pac_man.state * 6)
	{
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_closed;
		counter1 = 0;
	}
}

void	pacman_right(t_gamedata *game)
{
	static int	counter2;

	counter2++;
	if (counter2 == game->sprites.pac_man.state)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_right;
	else if (counter2 == game->sprites.pac_man.state * 2)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_open_right;
	else if (counter2 == game->sprites.pac_man.state * 4)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_right;
	else if (counter2 >= game->sprites.pac_man.state * 6)
	{
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_closed;
		counter2 = 0;
	}
}

void	pacman_left(t_gamedata *game)
{
	static int	counter3;

	counter3++;
	if (counter3 == game->sprites.pac_man.state)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_left;
	else if (counter3 == game->sprites.pac_man.state * 2)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_open_left;
	else if (counter3 == game->sprites.pac_man.state * 4)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_left;
	else if (counter3 >= game->sprites.pac_man.state * 6)
	{
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_closed;
		counter3 = 0;
	}
}

void	pacman_up(t_gamedata *game)
{
	static int	counter4;

	counter4++;
	if (counter4 == game->sprites.pac_man.state)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_up;
	else if (counter4 == game->sprites.pac_man.state * 2)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_open_up;
	else if (counter4 == game->sprites.pac_man.state * 4)
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_semi_up;
	else if (counter4 >= game->sprites.pac_man.state * 6)
	{
		game->sprites.pac_man.pacman_status = \
		game->sprites.pac_man.pac_closed;
		counter4 = 0;
	}
}
