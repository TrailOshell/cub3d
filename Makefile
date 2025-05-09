# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 20:46:08 by tsomchan          #+#    #+#              #
#    Updated: 2025/05/09 17:14:18 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

INC_PTH			=	inc/
INC				=	-I$(INC_PTH)

INC_CUB3D		=	$(INC_PTH)cub3D.h

SRC_PTH			=	src/
SRC				=	error.c \
					free.c \
					main.c

SRC_DEBUG_PTH	=	debug/
SRC	+=	$(addprefix $(SRC_DEBUG_PTH), \
					color.c \
					debug.c \
		)

SRC_EVENT_PTH	=	event/
SRC	+=	$(addprefix $(SRC_EVENT_PTH), \
					mlx_events.c \
		)

SRC_INIT_PTH	=	init/
SRC	+=	$(addprefix $(SRC_INIT_PTH), \
					flood_fill.c \
					get_next_row.c \
					grid.c \
					line.c \
					set_map.c \
					set_object.c \
					set_texture.c \
		)

SRC_RENDER_PTH	=	render/
SRC	+=	$(addprefix $(SRC_RENDER_PTH), \
					render.c \
					sprites.c \
		)

SRC_UTIL_PTH	=	util/
SRC	+=	$(addprefix $(SRC_UTIL_PTH), \
					is_conditions.c \
					util.c \
		)

OBJ_PTH	=	obj/
OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)
OBJ_SUB_PTHS =	$(OBJ_PTH) $(addprefix $(OBJ_PTH), \
					$(SRC_DEBUG_PTH) \
					$(SRC_EVENT_PTH) \
					$(SRC_INIT_PTH) \
					$(SRC_RENDER_PTH) \
					$(SRC_UTIL_PTH) \
				)

LIBFT_PTH	=	libft/
LIBFT		=	$(LIBFT_PTH)libft.a
LIBFT_INC	=	-I$(LIBFT_PTH)sources/libft.h

GNL_PTH	=	gnl/
GNL		=	$(GNL_PTH)get_next_line.a
GNL_INC	=	-I$(GNL_PTH)

MLX			=	$(MLX_PTH)/libmlx.a
MLX_PTH		=	mlx
MLX_FLAGS	=	-L$(MLX_PTH) -l$(MLX_PTH) -L/usr/lib -I$(MLX_PTH) -lXext -lX11 -lm -lz
MLX_INC		=	-I$(MLX_PTH)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-g

all: $(MLX) $(LIBFT) $(GNL) $(NAME)

$(OBJ_PTH)%.o: $(SRC_PTH)%.c Makefile $(INC_CUB3D) | $(OBJ_SUB_PTHS)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT_INC) $(GNL_INC) $(MLX_INC) -c $< -o $@
	@echo "$(GRN)compiled $(CYN)$@$(NCL)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(GNL) $(LIBFT) -o $@ $(MLX_FLAGS)
	@echo "$(GRN)compiled $(CYN)$@$(NCL)"

$(OBJ_SUB_PTHS):
	mkdir -p $(OBJ_PTH)
	mkdir -p $(OBJ_SUB_PTHS)

$(LIBFT):
	@make -C ${LIBFT_PTH}
	@echo "$(GRN)compiled $(CYN)$@$(NCL)"

$(GNL):
	@make -C ${GNL_PTH}
	@echo "$(GRN)compiled $(CYN)$@$(NCL)"

$(MLX):
	@make -C ${MLX_PTH}
	@echo "$(GRN)compiled $(CYN)$@$(NCL)"

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PTH)
	@echo "$(YLW)removed object files$(NCL)"

fclean: clean
	make clean -C $(MLX_PTH)
	rm -f $(NAME)
	@echo "$(YLW)removed $(NAME) and object files$(NCL)"

re: fclean all

#	Colors
NCL		=	\033[0;0m
RED		=	\033[0;31m
GRN		=	\033[0;32m
YLW		=	\033[0;33m
BLU		=	\033[0;34m
PUR		=	\033[0;35m
CYN		=	\033[0;36m