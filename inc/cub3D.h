/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:07:26 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/09 17:49:15 by tsomchan         ###   ########.fr       */
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

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_rgb;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_node			*node;
	t_player		*player;
	t_tx			*tx;
	t_rgb			*f;
	t_rgb			*c;
}	t_data;

// color
# define NCL "\033[0;39m"
# define RED "\033[0;91m"
# define GRN "\033[0;92m"
# define YLW "\033[0;93m"
# define BLU "\033[0;94m"
# define PUR "\033[0;95m"
# define CYN "\033[0;96m"

/*	||  DEBUG  ||	*/
// color.c
void	set_color(char *color);
void	color_from_char(char c);
// debug.c
void	write_grid(char **grid);
void	write_color(char *msg, char *color);

/*	||  EVENT  ||	*/
// mlx_events.c
int		game_exit(t_data *data);

/*	||  INIT  ||	*/
// flood_fill.c
int		flood_fill(t_data *data);
// get_next_row.c
void	get_next_row(t_data *data, int fd);
// grid.c
char	**new_grid(t_map *map);
char	**dupe_grid(t_map *map);
// line.c
void	add_line(t_node **node, char *line);
char	*line_dupe(char *line);
char	*line_copy(char *copy, char *line);
// set_map.c
void	set_map(t_data *data, t_node *node);
// set_object.c
int		set_player(t_player *player, int x, int y);

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
size_t	cub_strlen(char *s);
char	*cub_strdup(char *s);
int		cub_strrncmp(char *s1, char *s2, size_t n);
char	*cub_strjoin(char *s1, char *s2);

/*	|| SRC ||	*/
// error.c
void	error_and_exit(t_data *data, char *msg);
// free.c
void	free_map(t_map **map);
void	free_node(t_node **node);
void	free_stuff(t_data *data);
// main.c
t_map	*start_map(t_map *map);

#endif