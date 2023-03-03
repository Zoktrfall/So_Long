#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//Delete
#include <stdio.h>

typedef struct s_mapdata {
	char	**map;
}	t_mapdata;

//The map is split or empty
void	error_empty(char **map);
void	error_divided(char **map);
int		divided_map(char **map);

//Argument Verification
int		correct_arguments(int argc, char **argv);
int		check_ber(char *arg, char *ber);
int		open_file(int fd, char *file_name);
void	free_map(char ***str);
char	**map_initialization(int fd);
char	**create_map(char *file_name);
char	**optimization_map(char **map);
size_t	counts(char **map);
int		unprinted(char *str);
int		rectangular_map(char **map);

//Utilities
char	**ft_strcat(char **map, char **new_map, size_t i);

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

//Errors and Warnings
int		error_rectangular(void);
int		print_file_error(void);
void	print_warning(void);
int		print_one_argument_error(void);
void	file_opening_error(void);

#endif