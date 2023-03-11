NAME = so_long

# 42
# MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
# Home
MLX = -L. -lmlx -framework OpenGL -framework AppKit

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

all : $(NAME)

$(NAME) : Makefile so_long.h $(OBJ)
	gcc -I /usr/local/include $(OBJ) $(MLX) -o $(NAME)

%.o : %.c
	@gcc -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)