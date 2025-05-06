NAME = cub3d
CC = cc
OBJ = $(SRC:.c=.o)

FLAGS = -L ./includes/MLX42 -lmlx -lXext -lX11 -lm -lz
INCLUDES = includes/MLX42/libmlx.a
SRC = src/main.c

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(INCLUDES) $(LFLAGS)

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)

.PHONY all fclean
