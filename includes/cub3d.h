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
#define	IMG 64

#define NO textures/path_to_the_north_texture.png
#define SO textures/path_to_the_south_texture.png
#define WE textures/path_to_the_west_texture.png
#define EA textures/path_to_the_east_texture.png
#define P1 textures/p1.png

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
	void	*window;

	char	**map;

	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*p1_texture;

	mlx_image_t		*north_image;
	mlx_image_t		*south_image;
	mlx_image_t		*west_image;
	mlx_image_t		*east_image;
	mlx_image_t		*p1;

	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*player;

	int		pos_x;
	int		pos_y;
	int		exit_x;
	int		exit_y;
	int		move_counter;
	int		collect_counter;


	
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