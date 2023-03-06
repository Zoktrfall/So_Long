#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

//Delete
#include <stdio.h>

typedef struct s_player {
	size_t	x;
	size_t	y;
}	t_player;

typedef struct s_objects {
	size_t	coins;
	size_t	enemies;
	size_t	exit;
}	t_objects;

typedef struct s_sprites {
	void	*walls;
}	t_sprites;

typedef struct s_gamedata {
	void		*mlx_ptr;
	void		*mlx_win;
	size_t		y_axis;
	size_t		x_axis;
	t_player	player;
	size_t		score;
	char		**map;
	t_objects	objects;
	size_t		coins_score;
	size_t		game_over;
	t_sprites	sprites;
}	t_gamedata;

//The map is split or empty
void	error_empty(char **map);
void	error_divided(char **map);
int		divided_map(char **map);

//Rectangular map
int		rectangular_map(char **map);
int		error_rectangular(void);

//Open file
int		open_file(int fd, char *file_name);
int		print_file_error(void);
void	file_opening_error(void);

//Closed/Surrounded
int		closed_surrounded(char **map);
int		first_last_x(char *str);
int		last_y(char **str);
int		error_walls(void);
int		first_y(char *str);

//Player, Exit, Jellyfish, Coins
int		error_c_e_p(void);
int		check_e_p(char **map, size_t len);
int		check_c_m(char **map, size_t len);
int		do_check_c_e_p(char **map, size_t len);

//Correct chearacters in map
int		check_c_e_p(char **map);
int		correct_chearacters(char **map, size_t len);
int		chearacters(char *str);

//Position the player and count coins, enemies
void	player_position(char **map, t_player *play);
size_t	count_enemies(char **map, size_t len);
size_t	count_coins(char **map, size_t len);

//Fill_Validation
void	fill_validation(char **map, t_player play, t_objects *medus);
int		valid_way(char **map);
int		error_valid_way(void);
char	**creat_tmp(char **map);
int		check_fill(char **map, t_objects medus);

//Argument Verification
void	print_warning(void);
int		print_one_argument_error(void);
int		correct_arguments(int argc, char **argv);
int		check_ber(char *arg, char *ber);
void	free_map(char ***str);
char	**map_initialization(int fd);
char	**create_map(char *file_name);
char	**optimization_map(char **map);
size_t	counts(char **map);
int		unprinted(char *str);

//Utilities
char	**ft_strcat(char **map, char **new_map, size_t i);
char	*ft_strdup(const char *str);

//Get_Next_Line
char	*get_next_line(int fd, int check);
char	*replace_str(int fd, char *ptr, char *str);
char	*new_str(char *str);
char	*new_ptr(char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin_exlusive(char *str, char *ptr);
char	*adds(char *ptr);
size_t	ft_strlen(const char *str);
int		characters_str(char *str);
int		characters_ptr(char *str);

#endif