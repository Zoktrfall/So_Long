#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//Utilities

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