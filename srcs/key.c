/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:59:12 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/15 13:48:36 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include <stdio.h>

int     key_press(int key, t_mlx *mlx)
{
	if (key == 13) // w
		mlx->key_w = 1;
	if (key == 1) // s
		mlx->key_s = 1;
	if (key == 0) // LEFT A
		mlx->key_a = 1;
    if (key == 2) // RIGHT D
		mlx->key_d = 1;
    if (key == 53) // ESC
        exit(0);
    return (1);
}

int     key_release(int key, t_mlx *mlx)
{
	if (key == 13) // w
		mlx->key_w = 0;
	if (key == 1) // s
		mlx->key_s = 0;
	if (key == 0) // LEFT A
		mlx->key_a = 0;
    if (key == 2) // RIGHT D
		mlx->key_d = 0;
    return (1);
}

void	movement(t_mlx *mlx)
{
	double		move_speed;
	double		rotate_speed;
	t_player	*p;
	t_map		*m;
	int			y;
	int			x;

	move_speed = 0.06;
    rotate_speed = M_PI / 36.0;
	p = mlx->player;
	m = mlx->map;
	if (mlx->key_w)
	{
		y = (int)p->pos_y * m->width;
		x = (int)(p->pos_x + p->dir_x * move_speed * 4.0);
		printf("M1 = %c | x = %d y = %d\n", m->map[y + x], x, y);
		if (m->map[y + x] != '1')
			p->pos_x += mlx->player->dir_x * move_speed;
		y = (int)(p->pos_y + p->dir_y * move_speed * 4.0) * m->width;
		x = (int)(floor(p->pos_x));
		printf("M2 = %c | x = %d y = %d\n", m->map[y + x], x, y);
		if (m->map[y + x] != '1')
			p->pos_y += mlx->player->dir_y * move_speed;
	}
	p->pos_x -= (mlx->key_s) ? mlx->player->dir_x * move_speed : 0;
	p->pos_y -= (mlx->key_s) ? mlx->player->dir_y * move_speed : 0;
	p->angle += (mlx->key_a) ? rotate_speed : 0;
	p->angle -= (mlx->key_d) ? rotate_speed : 0;
}