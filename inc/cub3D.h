/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:07:26 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:31:39 by tsomchan         ###   ########.fr       */
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

// color
# define RESET "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

# ifndef SIZE
#  define SIZE				64
# endif

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
}	t_player;

typedef struct s_map
{
	char			**grid;
	int				n_row;
	int				n_col;
}	t_map;

typedef struct s_tx
{
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
}	t_tx;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_node			*node;
	t_player		*player;
	t_tx			tx;
}	t_data;

// main.c
t_map	*start_map(t_map *map);

// util.c
size_t	sl_strlen(char *s);
char	*sl_strdup(char *s);
int		sl_strrncmp(char *s1, char *s2, size_t n);
char	*sl_strjoin(char *s1, char *s2);
// sl_itoa.c
char	*sl_itoa(int n);
// is_conditions.c
int		isvalidchar(char c);
int		iswalkable(char c);
int		ispatrolable(char c);

// error.c
void	error_and_exit(t_data *data, char *msg);
// free.c
void	free_map(t_map **map);
void	free_node(t_node **node);
void	free_stuff(t_data *data);
// color.c
void	set_color(char *color);
void	color_from_char(char c);
// debug.c
void	write_grid(char **grid);
void	write_value(char *msg, int int_val);
void	write_color(char *msg, char *color);
void	write_color_exit(t_data *data, char *msg, char *color);
// debug_pathfinding.c
void	debug_facing_step(int up, int down, int left, int right);
void	debug_pathfinding(int up, int down, int left, int right);

// get_next_row.c
void	get_next_row(t_data *data, int fd);
// line.c
void	add_line(t_node **node, char *line);
char	*line_dupe(char *line);
char	*line_copy(char *copy, char *line);
// grid.c
char	**new_map(t_map *map);
char	**dupe_map(t_map *map);
// set_map.c
void	set_map(t_data *data, t_node *node);
// check_map_input.c
int		check_map_size(t_data *data);
int		check_map_by_lines(t_data *data, char **grid);
int		check_map_enclosed_walls(t_data *data, char **grid);
int		check_map_chars_count(t_data *data);
// set_object.c
int		set_player(t_player *player, int x, int y);
// flood_fill.c
int		flood_fill(t_data *data);

// sprites.c
void	*load_a_sprite(t_data *data, char *filename);
void	load_sprites(t_data *data);
// free_sprites.c
void	free_pl_sprites(t_data *data);
void	free_pt_sprites(t_data *data);
void	free_sprites(t_data *data);
// render.c
void	render_map(t_data *data);
void	render_tile(t_data *data, int x, int y);
//void	render_pl_direction(t_data *data, t_pl_sprite player, int x, int y);
void	render_player(t_data *data, int x, int y);
void	render_patrol(t_data *data);
void	render_objects(t_data *data);

// render_pl_front_of_pt.c
void	render_pl_front_of_pt(t_data *data, int x, int y);

// mlx_events.c
int		game_exit(t_data *data);
int		on_keypress(int keysym, t_data *data);
// input.c
void	player_move(int x, int y, t_data *data);
void	player_wait(t_data *data);
void	show_help(void);

// patrol.c
void	patroling(t_data *data);
// pathfinding.c
//int		pathfinding(char **grid, t_patrol *patrol);
char	set_next_step(int up, int down, int left, int right);

#endif