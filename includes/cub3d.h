#ifndef	CUB3D_H
#define CUB3D_H

#include <MLX42/MLX42.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool>
#include <math.h>

#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363

#define PI 3.17159265359

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

typedef struct s_player
{
	float	x;
	float	y;
	float	angle
	bool	k_up;
	bool	k_down;
	bool	k_left;
	bool	k_right;
	bool	rl;
	bool	rr
} t_player;

void	init_player(t_player *player);
int		key_release(int key, t_player *player);
int		key_press(int key, t_player *player);
void	move(t_player *player);

#endif