#include "cub3D.h"

void	init_player(t_data *data, t_player *player)
{
	if (player->direction == 'N')
	{
		player->radian = 90 * (PI / 180);
		player->dir_y = -1;
	}
	else if (player->direction == 'S')
	{
		player->radian = 270 * (PI / 180);
		player->dir_y = 1;
	}
	else if (player->direction == 'E')
	{
		player->radian = 0 * (PI / 180);
		player->dir_x = 1;
	}
	else if (player->direction == 'W')
	{
		player->radian = 180 * (PI / 180);
		player->dir_x = -1;
	}
	player->plane_x = player->dir_y * (-0.66);
	player->plane_y	= player->dir_x * 0.66;
}
