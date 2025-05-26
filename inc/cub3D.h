/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:07:26 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/26 10:51:09 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "mlx.h"
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
#  define SIZE				32
# endif

//	X11 events 
# define KEYPRESS			2
# define DESTROYNOTIFY		17
# define EXPOSE				12

//# define KEYPRESSMASK	(1L<<0)

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100 
# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364 
# define KEY_SPACE 			32
# define KEY_H				104
# define KEY_Q				113
# define KEY_ESC			65307

# define WIDTH	1920
# define HEIGHT 1080

typedef struct s_node
{
	struct s_node	*next;
	char			*line;
	int				x;
	int				y;
}	t_node;

typedef struct s_player
{
	int			x;
	int			y;
	
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char			**grid;
	int				n_row;
	int				n_col;
}	t_map;

typedef struct s_tx
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;// uninitfunc.
	
	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*ea_img;
	mlx_image_t		*we_img;

	mlx_texture_t	*no_tx;
	mlx_texture_t	*so_tx;
	mlx_texture_t	*ea_tx;
	mlx_texture_t	*we_tx;
}	t_tx;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_rgb;

typedef struct s_ray
{
	int				x;
	int				y;
	double			pov;
	double			dir_x;
	double			dir_y;
	double			dx;
	double			dy;
	int				hit;

	double			wall_dist;
	int				draw_start;
	int				draw_end;
	int				line_height;
	double			wall_size;
	int				tx_size;
	char			tx;

	int				step_x;
	int				step_y;

	double			side_distance_x;
	double			side_distance_y;
	int				side;

}	t_ray;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*win;
	t_map			*map;
	t_node			*node;
	t_player		*player;
	t_tx			*tx;
	t_rgb			*f;
	t_rgb			*c;
	t_ray			*ray;
	char			*line;
}	t_data;

/*	||  DEBUG  ||	*/
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

/*	||  EVENT  ||	*/
// mlx_events.c
int		game_exit(t_data *data);
int		on_keypress(int keysym, t_data *data);

/*	||  INIT  ||	*/
// flood_fill.c
int		flood_fill(t_data *data);
// get_next_row.c
void	get_next_row(t_data *data, int fd);
// grid.c
char	**new_grid(t_map *map);
char	**dupe_grid(t_map *map);
// init.c
t_data	*init_data(t_data *data);
// line.c
void	add_line(t_node **node, char *line);
char	*line_dupe(char *line);
char	*line_copy(char *copy, char *line);
// set_map.c
void	set_map(t_data *data, t_node *node);
// set_texture.c
int		set_elements(t_data *data);

/*	||  RENDER  ||	*/
// render.c
void	render_tile(t_data *data, int x, int y);
void	render_map(t_data *data);
// sprites.c
void	*load_a_sprite(t_data *data, char *filename);

/*	||  UTIL  ||	*/
// is_conditions.c
int		isplayerchar(char c);
int		isvalidchar(char c);
int		iswalkable(char c);
// util.c
int		ft_strrncmp(char *s1, char *s2, size_t n);
int		ft_isspace(char str);
int		chk_all_spaces(char *str);

/*	|| SRC ||	*/
// error.c
void	error_and_exit(t_data *data, char *msg);
// free.c
void	free_map(t_map *map);
void	free_node(t_node **node);
void	free_stuff(t_data *data);
// main.c
t_map	*init_map(t_map *map);

#endif