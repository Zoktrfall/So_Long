#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
// 42
# include <mlx.h>
// Home
// # include "mlx.h"

//Delete
#include <stdio.h>

# define SIZE 32

enum e_gamepath {
	W = 13,
	S = 1,
	D = 2,
	A = 0,
	ESC = 53,
};

typedef struct s_player {
	int	x;
	int	y;
}	t_player;

typedef struct s_objects {
	size_t	coins;
	size_t	enemies;
	size_t	exit;
}	t_objects;

typedef struct s_pacman_dying {
	void	*dying1;
	void	*dying2;
	void	*dying3;
	void	*dying4;
	void	*dying5;
	void	*dying6;
	void	*dying7;
	void	*dying8;
	void	*dying9;
	void	*dying10;
	void	*whoosh;
}	t_pacman_dying;

typedef struct s_pacman {
	void			*pac_closed;
	void			*pac_open_down;
	void			*pac_semi_down;
	void			*pac_open_left;
	void			*pac_semi_left;
	void			*pac_open_right;
	void			*pac_semi_right;
	void			*pac_open_up;
	void			*pac_semi_up;
	t_pacman_dying	dead;
}	t_pacman;

typedef struct s_enemy {
	void	*ghost_down1;
	void	*ghost_down2;
	void	*ghost_left1;
	void	*ghost_left2;
	void	*ghost_right1;
	void	*ghost_right2;
	void	*ghost_up1;
	void	*ghost_up2;
}	t_enemy;

typedef struct s_sprites {
	void		*walls;
	void		*black;
	void		*portal;
	void		*coins;
	t_pacman	pac_man;
	t_enemy		medus_green;
}	t_sprites;

typedef struct s_list {
	void			*container;
	struct s_list	*next;
}	t_list;

typedef struct s_gamedata {
	void		*mlx_ptr;
	void		*mlx_win;
	size_t		y_axis;
	size_t		x_axis;
	t_player	player;
	t_player	medus_green_pos;
	size_t		medus_gamepath_green;
	size_t		score;
	char		**map;
	t_objects	objects;
	size_t		coins_score;
	size_t		game_over;
	size_t		gamepath;
	t_sprites	sprites;
	t_list		*oper_right;
	t_list		*head_right;
	t_list		*oper_left;
	t_list		*head_left;
	t_list		*oper_up;
	t_list		*head_up;
	t_list		*oper_down;
	t_list		*head_down;
	t_list		*pac_dying;
	t_list		*dying_head;
	t_list		*medus_green_up;
	t_list		*head_green_up;
	t_list		*medus_green_down;
	t_list		*head_green_down;
	t_list		*medus_green_left;
	t_list		*head_green_left;
	t_list		*medus_green_right;
	t_list		*head_green_right;
	size_t		time_medus;
	size_t		time_pac;
	size_t		enemy_time;
	size_t		flag_dead;
	size_t		max_time;
}	t_gamedata;

//The map is split or empty
void			error_empty(char **map);
void			error_divided(char **map);
int				divided_map(char **map);

//Rectangular map
int				rectangular_map(char **map);
int				error_rectangular(void);

//Open file
int				open_file(int fd, char *file_name);
int				print_file_error(void);
void			file_opening_error(void);

//Closed/Surrounded
int				closed_surrounded(char **map);
int				first_last_x(char *str);
int				last_y(char **str);
int				error_walls(void);
int				first_y(char *str);

//Player, Exit, Jellyfish, Coins
int				error_c_e_p(void);
int				check_e_p(char **map, size_t len);
int				check_c_m(char **map, size_t len);
int				do_check_c_e_p(char **map, size_t len);

//Correct chearacters in map
int				check_c_e_p(char **map);
int				correct_chearacters(char **map, size_t len);
int				chearacters(char *str);

//Position the player and count coins, enemies
void			ft_position(char **map, t_player *play, char oper);
size_t			count_enemies(char **map, size_t len);
size_t			count_coins(char **map, size_t len);

//Fill_Validation
void			fill_validation(char **map, t_player play, t_objects *medus);
int				valid_way(char **map);
int				error_valid_way(void);
char			**creat_tmp(char **map);
int				check_fill(char **map, t_objects medus);

//Argument Verification
int				args_verification(int argc, char **argv, char ***map);
int				map_verification(char **map);
void			print_warning(void);
int				print_one_argument_error(void);
int				correct_arguments(int argc, char **argv);
int				check_ber(char *arg, char *ber);
void			free_map(char ***str);
char			**map_initialization(int fd);
char			**create_map(char *file_name);
char			**optimization_map(char **map);
size_t			counts(char **map);
int				unprinted(char *str);

//Utilities
size_t			ft_log(size_t x, size_t y);
t_list			*add_to_empty(t_list *head, void *sprite);
t_list			*add_to_end(t_list *head, void *sprite);
char			**ft_strcat(char **map, char **new_map, size_t i);
char			*ft_strdup(const char *str);

//Get_Next_Line
char			*get_next_line(int fd, int check);
char			*replace_str(int fd, char *ptr, char *str);
char			*new_str(char *str);
char			*new_ptr(char *str);
char			*ft_strchr(const char *str, int ch);
char			*ft_strjoin_exlusive(char *str, char *ptr);
char			*adds(char *ptr);
size_t			ft_strlen(const char *str);
int				characters_str(char *str);
int				characters_ptr(char *str);

//Making Pac-Man
void			creating_game(char **map, t_gamedata *game);
t_sprites		ft_sprites(t_gamedata *game);
t_pacman		add_sprites_pacman(t_gamedata *game);
t_pacman_dying	pacman_dying(t_pacman_dying *dead, t_gamedata *game, int size);

//Gamepath
int				character_movement(int key_code, t_gamedata *game);
void			move_left(t_gamedata *game);
void			move_rigth(t_gamedata *game);
void			move_down(t_gamedata *game);
void			move_up(t_gamedata *game);

//Graphic map
int				graphic_map(t_gamedata *game);
void			map_traversal(char *map, size_t y_axis, t_gamedata *game);

//Packman motion animation and dying
void			pacman_down(t_gamedata *game);
void			pacman_right(t_gamedata *game);
void			pacman_left(t_gamedata *game);
void			pacman_up(t_gamedata *game);
void			end_game(t_gamedata *game);
void			pac_dead_animation(t_gamedata *game);

//Medus motion animation
void			medus_anim_up(t_list **sprite, t_gamedata *game, t_list *head);
void			medus_anim_down(t_list **sprite, \
					t_gamedata *game, t_list *head);
void			medus_anim_left(t_list **sprite, \
					t_gamedata *game, t_list *head);
void			medus_anim_right(t_list **sprite, \
					t_gamedata *game, t_list *head);

//Pacman motion animation and dying container
t_list			*ft_container_right(t_gamedata *game);
t_list			*ft_container_down(t_gamedata *game);
t_list			*ft_container_up(t_gamedata *game);
t_list			*ft_container_left(t_gamedata *game);
void			ft_containers(t_gamedata *game);
t_list			*ft_container_dying(t_gamedata *game);

void			medus_g_position(char **map, t_player *play);
void			ft_containers_enemy_green(t_gamedata *game);
t_list			*ft_container_enemy_green_left(t_gamedata *game);
t_list			*ft_container_enemy_green_up(t_gamedata *game);
t_list			*ft_container_enemy_green_down(t_gamedata *game);
t_list			*ft_container_enemy_green_right(t_gamedata *game);

#endif