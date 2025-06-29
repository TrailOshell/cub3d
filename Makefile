# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 20:46:08 by tsomchan          #+#    #+#              #
#    Updated: 2025/06/29 10:26:32 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-g

INC_PTH			=	inc/
INC				=	-I$(INC_PTH)

INC_CUB3D		=	$(INC_PTH)cub3D.h

SRC_PTH			=	src/
SRC				=	error.c \
					free.c \
					main.c \

SRC_DEBUG_PTH	=	debug/
SRC	+=	$(addprefix $(SRC_DEBUG_PTH), \
					color_write.c \
					color.c \
					debug.c \
		)


SRC_INIT_PTH	=	init/
SRC	+=	$(addprefix $(SRC_INIT_PTH), \
					get_next_row.c \
					init.c \
					set_map.c \
					set_texture.c \
					init_mlx.c\
					init_player.c\
		)

SRC_MAP_PTH	=	map/
SRC	+=	$(addprefix $(SRC_MAP_PTH), \
					flood_fill.c \
					grid.c \
					line.c \
		)

SRC_RAYCAST_PTH	=	raycast/
SRC	+=	$(addprefix $(SRC_RAYCAST_PTH), \
					relocate_player.c \
					minimap.c \
					ray.c \
					ray_utils.c\
					render_utils.c \
					render3D.c \
		)

SRC_CONTROL_PTH	=	control/
SRC	+=	$(addprefix $(SRC_CONTROL_PTH), \
					keybinds.c\
					movement.c\
		)

SRC_UTIL_PTH	=	util/
SRC	+=	$(addprefix $(SRC_UTIL_PTH), \
					is_conditions.c \
					util.c \
		)

OBJ_PTH			=	obj/
OBJ				=	$(SRC:%.c=$(OBJ_PTH)%.o)
OBJ_SUB_PTHS	=	$(OBJ_PTH) $(addprefix $(OBJ_PTH), \
					$(SRC_DEBUG_PTH) \
					$(SRC_INIT_PTH) \
					$(SRC_MAP_PTH) \
					$(SRC_RAYCAST_PTH) \
					$(SRC_CONTROL_PTH) \
					$(SRC_UTIL_PTH) \
				)

LIBFT_PTH	=	libft/
LIBFT		=	$(LIBFT_PTH)libft.a
LIBFT_INC	=	-I$(LIBFT_PTH)sources/

GNL_PTH	=	gnl/
GNL		=	$(GNL_PTH)get_next_line.a
GNL_INC	=	-I$(GNL_PTH)

MLX            =    $(MLX_PTH)build/libmlx42.a
MLX_PTH        =    MLX42/
MLX_FLAGS	=    -Iinclude -ldl -lglfw -pthread -lm
MLX_INC        =    -I$(MLX_PTH)include/MLX42

all: $(MLX) $(LIBFT) $(GNL) $(NAME)

$(OBJ_PTH)%.o: $(SRC_PTH)%.c Makefile $(INC_CUB3D) | $(OBJ_SUB_PTHS)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT_INC) $(GNL_INC) $(MLX_INC) -c $< -o $@
	@echo "$(GRN)compiled $(CYN)$@$(NCL)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(GNL) $(LIBFT) $(MLX) -o $@ $(MLX_FLAGS)
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
	@echo "$(YLW)===================> start make MLX42$(NCL)"
	cmake $(MLX_PTH) -B $(MLX_PTH)/build && make -C $(MLX_PTH)/build -j4
	@echo "$(YLW)===================> Finish mlx\n$(NCL)"
	@echo "$(GRN)compiled $(CYN)$@$(NCL)"

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PTH)
	rm -rf $(MLX_PTH)/build
	rm -rf $(TEXTURES)
	@echo "$(YLW)removed object files$(NCL)"

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)
	@echo "$(YLW)removed $(NAME) and object files$(NCL)"

re: fclean all

.PHONY	=	all clean fclean re

#	Colors
NCL		=	\033[0;0m
RED		=	\033[0;31m
GRN		=	\033[0;32m
YLW		=	\033[0;33m
BLU		=	\033[0;34m
PUR		=	\033[0;35m
CYN		=	\033[0;36m

#	Tests

TEXTURES_PTH	=	textures/
TEXTURES		=	path_to_the_east_texture.png \
					path_to_the_north_texture.png \
					path_to_the_south_texture.png \
					path_to_the_west_texture.png
$(TEXTURES):
	# cp $(TEXTURES_PTH)path_to_the_east_texture.png .
	# cp $(TEXTURES_PTH)path_to_the_north_texture.png .
	# cp $(TEXTURES_PTH)path_to_the_south_texture.png .
	# cp $(TEXTURES_PTH)path_to_the_west_texture.png .

define	test_cub
	@echo "$(YLW)Map:$(CYN) $1 \________ ____ __ _$(NCL)"
	./$(NAME) $1
endef

t : test
test : $(NAME) $(TEXTURES)
	-$(call test_cub, cub/test.cub)

s : subject
subject : $(NAME) $(TEXTURES)
	-$(call test_cub, cub/subject.cub)

v : valid
valid : $(NAME)
	-$(call test_cub, cub/valid/ok_1.cub)
	-$(call test_cub, cub/valid/ok_2.cub)
	-$(call test_cub, cub/valid/ok_dimond.cub)
	-$(call test_cub, cub/valid/ok_subject.cub)

i : invalid
invalid : $(NAME) $(TEXTURES) im if

im : invalid_map
invalid_map : $(NAME) $(TEXTURES)
	-$(call test_cub, cub/invalid/color_floor_0.cub)
	-$(call test_cub, cub/invalid/color_floor_2.cub)
	-$(call test_cub, cub/invalid/no_news_1.cub)
	-$(call test_cub, cub/invalid/no_news_2.cub)
	-$(call test_cub, cub/invalid/player_0.cub)
	-$(call test_cub, cub/invalid/player_2.cub)
	-$(call test_cub, cub/invalid/textures_0.cub)
	-$(call test_cub, cub/invalid/textures_2.cub)
	-$(call test_cub, cub/invalid/wall_no_close_1.cub)
	-$(call test_cub, cub/invalid/wall_no_close_2.cub)

if : invalid_file
invalid_file : $(NAME) $(TEXTURES)
	-$(call test_cub, cub/invalid/file_name_error_no_path.cub)
	-$(call test_cub, cub/invalid/file_name_error_pn.cub)
	-$(call test_cub, cub/invalid/file_name_error_text.cub)
	-$(call test_cub, cub/invalid/file_name.cu)

VAL_FLAGS	=	 --leak-check=full --show-leak-kinds=all --show-reachable=no --suppressions=mlx.supp

define	val_cub
	@echo "$(YLW)Map:$(CYN) $1 \________ ____ __ _$(NCL)"
	-valgrind $(VAL_FLAGS) --log-file="valgrind.out" ./$(NAME) $1
	@- GREP_COLOR='01;32' grep --color=auto -E "no leaks" valgrind.out || @- GREP_COLOR='01;31' grep echo "leaks found"
	@- GREP_COLOR='01;0' grep --color=auto -E "definitely lost: 0 bytes in 0 blocks" valgrind.out || grep --color=auto -E "definitely lost:" valgrind.out
	@- GREP_COLOR='01;0' grep --color=auto -E "indirectly lost: 0 bytes in 0 blocks" valgrind.out || grep --color=auto -E "indirectly lost:" valgrind.out
	@- GREP_COLOR='01;0' grep --color=auto -E "possibly lost: 0 bytes in 0 blocks" valgrind.out ||  grep --color=auto -E "possibly lost:" valgrind.out 
	@- GREP_COLOR='01;34' grep --color=auto -E "still reachable:| suppressed:" valgrind.out || true
	@- GREP_COLOR='01;35' grep --color=auto "ERROR SUMMARY" valgrind.out || true
endef

val : $(NAME) $(TEXTURES)
	-$(call val_cub, cub/test.cub)

.PHONY	+=	t test s subject v valid i invalid im invalid_map if invalid_file