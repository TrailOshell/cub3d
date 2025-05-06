NAME = cub3D
SRC = src/main.c\
		src/player.c

HEADER = includes/cub3d.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I $(HEADER) -O0
MLXFLAGS = -L ./minilibx-linux/ -lmlx -Ilmlx -lXext -lX11

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C minilibx-linux/
	$(CC) $(CFLAGS) $(OBJ) minilibx-linux/libmlx.a -Lmlx_linux -lmlx_Linux -Lminilibx-linux/ -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx_linux -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf minilibx/obj/*.o

fclean: clean
	rm -rf $(NAME)
	make clean -C minilibx-linux/

re: fclean all

.PHONY: all clean fclean re 