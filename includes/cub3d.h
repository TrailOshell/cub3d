#ifndef	CUB3D_H
#define CUB3D_H

// #include "MLX42/MLX42.h"
# include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363

#define PI 3.17159265359
#define WIDTH 1280
#define	HEIGHT 720

#define NO textures/path_to_the_north_texture.png
#define SO textures/path_to_the_south_texture.png
#define WE textures/path_to_the_west_texture.png
#define EA textures/path_to_the_east_texture.png

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	bool	k_up;
	bool	k_down;
	bool	k_left;
	bool	k_right;
	bool	rl;
	bool	rr;
} t_player;

typedef struct  s_win
{
	void	*mlx;
	void	*win;
	void	*img;

	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	t_player player;
	char	**map;
} t_win;

typedef struct	s_cub
{
	void	*mlx;
	void	*win;
} t_cub;


typedef struct s_texture
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
} t_texture;

void	init_player(t_player *player);
int		key_release(int key, t_player *player);
int		key_press(int key, t_player *player);
void	move(t_player *player);
int		ft_destroy(t_win *window);

#endif