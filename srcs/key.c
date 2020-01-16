/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:59:12 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/16 15:16:48 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include <stdio.h>

int		key_press(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->key_w = 1;
	if (key == 1)
		mlx->key_s = 1;
	if (key == 0)
		mlx->key_a = 1;
	if (key == 2)
		mlx->key_d = 1;
	if (key == 53)
		exit(0);
	return (1);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->key_w = 0;
	if (key == 1)
		mlx->key_s = 0;
	if (key == 0)
		mlx->key_a = 0;
	if (key == 2)
		mlx->key_d = 0;
	return (1);
}

void	movement(t_mlx *mlx)
{
	t_player	*p;
	t_map		*m;
	int			y;
	int			x;

	p = mlx->player;
	m = mlx->map;
	if (mlx->key_w)
	{
		x = (int)(p->pos_x + p->dir_x * mlx->move_speed * 4.0);
		if (m->map[(int)p->pos_y * m->width + x] != '1')
			p->pos_x += mlx->player->dir_x * mlx->move_speed;
		y = (int)(p->pos_y + p->dir_y * mlx->move_speed * 4.0) * m->width;
		if (m->map[y + (int)(floor(p->pos_x))] != '1')
			p->pos_y += mlx->player->dir_y * mlx->move_speed;
	}
	y = (int)(p->pos_y - p->dir_y * mlx->move_speed * 4.0) * m->width;
	x = (int)(p->pos_x - p->dir_x * mlx->move_speed * 4.0);
	if (mlx->key_s && m->map[y + x] != '1')
	{
		p->pos_x -= mlx->player->dir_x * mlx->move_speed;
		p->pos_y -= mlx->player->dir_y * mlx->move_speed;
	}
	p->angle += (mlx->key_a) ? mlx->rotate_speed : 0;
	p->angle -= (mlx->key_d) ? mlx->rotate_speed : 0;
}
