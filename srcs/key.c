/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:59:12 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/03 23:08:04 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int		key_press(int key, t_mlx *mlx)
{
	if (key == W_KEY)
		mlx->key_w = 1;
	if (key == S_KEY)
		mlx->key_s = 1;
	if (key == A_KEY)
		mlx->key_a = 1;
	if (key == D_KEY)
		mlx->key_d = 1;
	if (key == LEFT_KEY)
		mlx->key_l = 1;
	if (key == RIGHT_KEY)
		mlx->key_r = 1;
	return (1);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == W_KEY)
		mlx->key_w = 0;
	if (key == 1)
		mlx->key_s = 0;
	if (key == A_KEY)
		mlx->key_a = 0;
	if (key == D_KEY)
		mlx->key_d = 0;
	if (key == LEFT_KEY)
		mlx->key_l = 0;
	if (key == RIGHT_KEY)
		mlx->key_r = 0;
	if (key == ESC_KEY)
		quit_window(mlx);
	return (1);
}

void	movement(t_mlx *mlx)
{
	t_player	*p;
	char		**map;
	int			y;
	int			x;

	p = mlx->player;
	map = mlx->map;
	//forward
	if (mlx->key_w)
	{
		x = (int)(p->pos_x + p->dir_x * mlx->move_speed * 4.0);
		if (map[(int)p->pos_y][x] != '1')
			p->pos_x += mlx->player->dir_x * mlx->move_speed;
		y = (int)(p->pos_y + p->dir_y * mlx->move_speed * 4.0);
		if (map[y][(int)floor(p->pos_x)] != '1')
			p->pos_y += mlx->player->dir_y * mlx->move_speed;
	}
	//backward
	y = (int)(p->pos_y - p->dir_y * mlx->move_speed * 4.0);
	x = (int)(p->pos_x - p->dir_x * mlx->move_speed * 4.0);
	if (mlx->key_s && map[y][x] != '1')
	{
		p->pos_x -= mlx->player->dir_x * mlx->move_speed;
		p->pos_y -= mlx->player->dir_y * mlx->move_speed;
	}
	//left
	y = (int)(p->pos_y + p->dir_x * mlx->move_speed * 4.0);
	x = (int)(p->pos_x - p->dir_y * mlx->move_speed * 4.0);
	if (mlx->key_a && map[y][x] != '1')
	{
		p->pos_x -= mlx->player->dir_y * mlx->move_speed;
		p->pos_y += mlx->player->dir_x * mlx->move_speed;
	}
	//right
	y = (int)(p->pos_y - p->dir_x * mlx->move_speed * 4.0);
	x = (int)(p->pos_x + p->dir_y * mlx->move_speed * 4.0);
	if (mlx->key_d && map[y][x] != '1')
	{
		p->pos_x += mlx->player->dir_y * mlx->move_speed;
		p->pos_y -= mlx->player->dir_x * mlx->move_speed;
	}
	//rotate
	p->angle += (mlx->key_l) ? mlx->rotate_speed : 0;
	p->angle -= (mlx->key_r) ? mlx->rotate_speed : 0;
}

int		quit_window(t_mlx *mlx)
{
	(void)(mlx);
	exit (0);
	return (0);
}