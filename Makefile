# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 16:46:54 by tsomchan          #+#    #+#              #
#    Updated: 2025/05/06 16:56:05 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

INC_PTH			=	inc/
INC				=	-I$(INC_PTH)

INC_CUB3D		=	$(INC_PTH)cub3D.h

SRC_PTH			=	src/
SRC				=	main.c

SRC_DEBUG_PTH	=	debug/
SRC	+=	$(addprefix $(SRC_DEBUG_PTH), error.c free.c color.c \
		debug.c debug_pathfinding.c)

SRC_EVENT_PTH	=	event/
SRC	+=	$(addprefix $(SRC_EVENT_PTH), mlx_events.c input.c)

SRC_INIT_PTH	=	init/
SRC	+=	$(addprefix $(SRC_INIT_PTH), get_next_row.c line.c grid.c \
		set_map.c check_map_input.c set_object.c flood_fill.c) \

SRC_RENDER_PTH	=	render/
SRC	+=	$(addprefix $(SRC_RENDER_PTH), sprites.c free_sprites.c render.c \
		render_pl_front_of_pt.c)

SRC_UTIL_PTH	=	util/
SRC	+=	$(addprefix $(SRC_UTIL_PTH), util.c sl_itoa.c is_conditions.c)

OBJ_PTH	=	obj/
OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)
OBJ_SUB_PTHS =	$(OBJ_PTH) $(addprefix $(OBJ_PTH), \
				$(SRC_DEBUG_PTH) \
				$(SRC_EVENT_PTH) \
				$(SRC_INIT_PTH) \
				$(SRC_RENDER_PTH) \
				$(SRC_UTIL_PTH))

BONUS_PTH	=	bonus/

# < get_next_line >
GNL_PTH	=	gnl/
GNL		=	$(GNL_PTH)get_next_line.a
GNL_INC	=	-I$(GNL_PTH)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-g

MLX			=	$(MLX_PTH)/libmlx.a
MLX_PTH		=	mlx
MLX_FLAGS	=	-L$(MLX_PTH) -l$(MLX_PTH) -L/usr/lib -I$(MLX_PTH) -lXext -lX11 -lm -lz
MLX_INC		=	-I$(MLX_PTH)

all: $(MLX) $(GNL) $(NAME)

$(OBJ_PTH)%.o: $(SRC_PTH)%.c Makefile $(INC_CUB3D)| $(OBJ_SUB_PTHS)
	$(CC) $(CFLAGS) $(INC) $(GNL_INC) $(MLX_INC) -c $< -o $@
	@echo "$(D_GREEN)compiled $<$(NC)"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GNL) -o $@ $(MLX_FLAGS)
	@echo "$(D_GREEN)compiled $@$(NC)"

$(OBJ_SUB_PTHS):
	mkdir -p $(OBJ_PTH)
	mkdir -p $(OBJ_SUB_PTHS)

$(GNL):
	make -C ${GNL_PTH}
	@echo "$(D_GREEN)compiled $@$(NC)"

$(MLX):
	make -C ${MLX_PTH}
	@echo "$(D_GREEN)compiled $@$(NC)"

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PTH)
	@echo "$(D_YELLOW)removed object files$(NC)"

fclean: clean
	make clean -C $(MLX_PTH)
	rm -f $(NAME)
	@echo "$(D_YELLOW)removed $(NAME) and object files$(NC)"

re: fclean all

#	Colors
NC			=	\033[0;0m
BLACK		=	\033[0;30m
D_RED		=	\033[0;31m
D_GREEN		=	\033[0;32m
D_YELLOW	=	\033[0;33m
D_BLUE		=	\033[0;34m
D_PURPLE	=	\033[0;35m
D_CYAN		=	\033[0;36m
L_GRAY		=	\033[0;37m
D_GRAY		=	\033[1;30m
L_RED		=	\033[1;31m
L_GREEN		=	\033[1;32m
L_YELLOW	=	\033[1;33m
L_BLUE		=	\033[1;34m
L_PURPLE	=	\033[1;35m
L_CYAN		=	\033[1;36m
WHITE		=	\033[1;37m