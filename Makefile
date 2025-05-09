OLOR_RESET	=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
CYAN		= 	\033[1;36m



NAME	= fdf

SRC		=	src/main.c


CFLAGS	= -Wextra -Wall -Werror -Ofast
LIBMLX	= ./MLX42
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
MLX_A	= $(LIBMLX)/build/libmlx42.a 

HEADER_MLX	= -I ./include -I $(LIBMLX)/include
HEADER_NOW = includes/cub3d.h

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_NOW)
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4\
	$(CC) $(CFLAGS) -I $(HEADER_NOW) $(OBJS) $(MLX_A) $(MLXFLAGS) -o $(NAME)

