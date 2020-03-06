/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:59:12 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 02:50:01 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int		key_press(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->input.key_forward = 1;
	if (key == S_KEY)
		cub->input.key_backward = 1;
	if (key == A_KEY)
		cub->input.key_left = 1;
	if (key == D_KEY)
		cub->input.key_right = 1;
	if (key == LEFT_KEY)
		cub->input.key_rotate_left = 1;
	if (key == RIGHT_KEY)
		cub->input.key_rotate_right = 1;
	return (1);
}

int		key_release(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->input.key_forward = 0;
	if (key == S_KEY)
		cub->input.key_backward = 0;
	if (key == A_KEY)
		cub->input.key_left = 0;
	if (key == D_KEY)
		cub->input.key_right = 0;
	if (key == LEFT_KEY)
		cub->input.key_rotate_left = 0;
	if (key == RIGHT_KEY)
		cub->input.key_rotate_right = 0;
	if (key == ESC_KEY)
		quit_window(cub);
	return (1);
}

void	movement_forward_backward(t_cub *cub)
{
	t_player	*p;
	int			y;
	int			x;

	p = &(cub->gi.player);
	if (cub->input.key_forward)
	{
		x = (int)(p->pos_x + p->dir_x * MOVE_SPEED * 4.0);
		if (cub->gi.map[(int)p->pos_y][x] != '1')
			p->pos_x += p->dir_x * MOVE_SPEED;
		y = (int)(p->pos_y + p->dir_y * MOVE_SPEED * 4.0);
		if (cub->gi.map[y][(int)floor(p->pos_x)] != '1')
			p->pos_y += p->dir_y * MOVE_SPEED;
	}
	y = (int)(p->pos_y - p->dir_y * MOVE_SPEED * 4.0);
	x = (int)(p->pos_x - p->dir_x * MOVE_SPEED * 4.0);
	if (cub->input.key_backward && cub->gi.map[y][x] != '1')
	{
		p->pos_x -= p->dir_x * MOVE_SPEED;
		p->pos_y -= p->dir_y * MOVE_SPEED;
	}
	movement_left_right_rotate(cub);
}

void	movement_left_right_rotate(t_cub *cub)
{
	t_player	*p;
	int			y;
	int			x;

	p = &(cub->gi.player);
	y = (int)(p->pos_y + p->dir_x * MOVE_SPEED * 4.0);
	x = (int)(p->pos_x - p->dir_y * MOVE_SPEED * 4.0);
	if (cub->input.key_left && cub->gi.map[y][x] != '1')
	{
		p->pos_x -= p->dir_y * MOVE_SPEED;
		p->pos_y += p->dir_x * MOVE_SPEED;
	}
	y = (int)(p->pos_y - p->dir_x * MOVE_SPEED * 4.0);
	x = (int)(p->pos_x + p->dir_y * MOVE_SPEED * 4.0);
	if (cub->input.key_right && cub->gi.map[y][x] != '1')
	{
		p->pos_x += p->dir_y * MOVE_SPEED;
		p->pos_y -= p->dir_x * MOVE_SPEED;
	}
	p->angle += (cub->input.key_rotate_left) ? ROTATE_SPEED : 0;
	p->angle -= (cub->input.key_rotate_right) ? ROTATE_SPEED : 0;
}


int		quit_window(t_cub *cub)
{
	(void)(cub);
	exit (0);
	return (0);
}