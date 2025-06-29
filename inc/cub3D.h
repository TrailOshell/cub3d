/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:07:26 by tsomchan          #+#    #+#             */
/*   Updated: 2025/06/29 16:23:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# include <stdio.h>

# include "MLX42.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "../libft/sources/libft.h"

// color
# define NCL "\033[0;39m"
# define RED "\033[0;91m"
# define GRN "\033[0;92m"
# define YLW "\033[0;93m"
# define BLU "\033[0;94m"
# define PUR "\033[0;95m"
# define CYN "\033[0;96m"

# ifndef SIZE
#  define SIZE				64
# endif

# ifndef DRAW_MODE
#  define DRAW_MODE			3
# endif

# ifndef DEBUG_MODE
#  define DEBUG_MODE		0
# endif

//	Debug Color
# define RAY_CLR			0xFFFFFFFF
# define PLAYER_CLR			0xFFFF64FF
# define WALL_CLR			0x00FFFFFF
# define MAP_WALL_CLR		0x0000FFFF

//	X11 events 
# define KEYPRESS			2
# define DESTROYNOTIFY		17
# define EXPOSE				12

# define WIDTH				1920
# define HEIGHT 			1080
# define MAP_SIZE			16
# define PI 				3.14159265
# define STEP 				0.05
# define RSPEED 			0.05

typedef struct s_node
{
	struct s_node	*next;
	char			*line;
	int				x;
	int				y;
}	t_node;


typedef struct s_player
{
	double			x;
	double			y;
	char			direction;

	double			radian;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}	t_player;

typedef struct s_map
{
	char			**grid;
	int				n_row;
	int				n_col;
}	t_map;

typedef struct s_tx
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;

	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*ea_img;
	mlx_image_t		*we_img;

	mlx_texture_t	*no_tx;
	mlx_texture_t	*so_tx;
	mlx_texture_t	*ea_tx;
	mlx_texture_t	*we_tx;
}	t_tx;

typedef struct s_tx_scale
{
	mlx_texture_t	*tx;
	int				height;
	int				width;
	double			range;
	double			pos;
}	t_tx_scale;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
	int				rgb;
	uint32_t		rgba;
}	t_rgb;

typedef struct s_ray
{
	int				x;
	int				y;
	double			fov;
	double			dir_x;
	double			dir_y;
	double			ddist_x;
	double			ddist_y;
	bool			hit;

	int				step_x;
	int				step_y;
	double			side_dx;
	double			side_dy;
	int				side;

	float			prep_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wallx;
	int				tx_x;
	char			tx_hit;

	int				tx_pos_x;
	int				tx_pos_y;

}	t_ray;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*win;
	t_map			*map;
	int				draw_mode;
	int				debug_mode;
	t_node			*node;
	t_player		*player;
	t_tx			*tx;
	t_rgb			*f;
	t_rgb			*c;
	t_ray			*ray;
	char			*line;
}	t_data;

/*	  CONTROL  	*/
// keybinds.c
void	keybinds(void *tmp);
// movement.c
void	key_ws(t_data *data, double cos_r, double sin_r);
void	key_ad(t_data *data, double cos_r, double sin_r);
void	set_direction_leftright(t_player *player, t_data *data, double rspeed);

/*	  DEBUG  	*/
// color_write.c
void	write_color(char *msg, char *color);
void	write_color_nl(char *msg, char *color);
void	write_color_nb(int nb, char *color);
void	write_double_color(char *msg1, char *color1, char *msg2, char *color2);
// color.c
void	set_color(char *color);
void	color_from_char(char c);
// debug.c
void	write_grid(char **grid);
void	write_elements(t_data *data);

/*	  INIT  	*/
// get_next_row.c
void	get_next_row(t_data *data, int fd);
// init_mlx.c
void	init_mlx(t_data *data);
// init_player.c
void	init_player(t_player *player);
// init.c
t_map	*init_map(t_map *map);
void	clear_player(t_data *data, int x, int y);
t_data	*init_data(t_data *data);
// set_map.c
void	set_map(t_data *data, t_node *node);
// set_texture.c
int		set_elements(t_data *data);

/*	  MAP  	*/
// flood_fill.c
int		flood_fill(t_data *data);
// grid.c
char	**new_grid(t_map *map);
char	**dupe_grid(t_map *map);
// line.c
void	add_line(t_node **node, char *line);
char	*line_dupe(char *line);
char	*line_copy(char *copy, char *line);

/*	 RAYCAST 	*/
// ray_utils.c
void	ft_set_texture(t_ray *ray);
void	ft_cal_value_wallx(t_ray *ray, t_player *player);
void	ft_prep_draw(t_ray *ray);
void	ft_prep_wall_dist(t_ray *ray);
void	ft_init_side_dist(t_ray *ray, t_player *player);
// ray.c
void	ft_ray_render(t_data *data);

void	render_three_dimension(t_data *data, int i);

void	calculate_wall(t_data *data);

void	wall_render(t_data *data, int i);

/*	  UTIL  	*/
// is_conditions.c
int		isplayerchar(char c);
int		isvalidchar(char c);
int		iswalkable(char c);
// util.c
int		ft_strrncmp(char *s1, char *s2, size_t n);
int		ft_isspace(char str);
int		chk_all_spaces(char *str);

/*	 SRC 	*/
// error.c
void	error_and_exit(t_data *data, char *msg);
// free.c
void	free_map(t_map *map);
void	free_node(t_node **node);
void	free_stuff(t_data *data);
// main.c
void	free_and_exit(void	*data);

// for debug
void	minimap(t_data *data);
void	draw_player(int y, int x, t_data *data, int color);
void	draw_map(t_map *map, t_data *data);
void	clear_player(t_data *data, int x, int y);
void	draw_square(int y, int x, t_data *data, int color);
void	relocate_player(t_data *data);

void	clear_image(t_data *data);
void	draw_floor(t_data *data);
void	draw_ceiling(t_data *data);

int		is_ray_hit(float ray_x, float ray_y, t_data *data);

#endif