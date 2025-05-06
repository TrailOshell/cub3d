#include "../includes/cub3d.h"

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;

	player->k_up = false;
	player->k_down = false;
	player->k_left = false;
	player->k_right = false;
	player->rl = false;
	player->rr = false;
}

int	key_press(int key, t_player *player)
{
	if (key == W)
		player->k_up = true;
	if (key == A)
		player->k_left = true;
	if (key == S)
		player->k_down = true;
	if (key == D)
		player->k_right = true;
	if (key == LEFT)
		player->rl = true;
	if (key == RIGHT)
		player->rr = true;
	return (0);
}

int	key_release(int key, t_player *player)
{
	if (key == W)
		player->k_up = false;
	if (key == A)
		player->k_left = false;
	if (key == S)
		player->k_down = false;
	if (key == D)
		player->k_right = false;
	if (key == LEFT)
		player->rl = false;
	if (key == RIGHT)
		player->rr = false;
	return (0);
}

void	move(t_player *player)
{
	int	speed = 5;
	float	r_speed = 0.1;
	float	cos_angle = cos(player->angle);
	float	sin_angle = sin(player->angle);

	if (player->k_up)
	{
		player->x += cos_angle * speed;
		player->x += sin_angle * speed;
	}
	if (player->k_down)
	{
		player->x -= cos_angle * speed;
		player->x -= sin_angle * speed;
	}
	if (player->k_left)
	{
		player->x += cos_angle * speed;
		player->x -= sin_angle * speed;
	}
	if (player->k_right)
	{
		player->x -= cos_angle * speed;
		player->x += sin_angle * speed;
	}

	if (player->rl)
		player->angle -= r_speed;
	if (player->rr)
		player->angle += r_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}