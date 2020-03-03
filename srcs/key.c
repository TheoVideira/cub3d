/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:59:12 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/03 17:57:51 by tvideira         ###   ########.fr       */
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
	if (mlx->key_w)
	{
		x = (int)(p->pos_x + p->dir_x * mlx->move_speed * 4.0);
		if (map[x][(int)p->pos_y] != '1')
			p->pos_x += mlx->player->dir_x * mlx->move_speed;
		y = (int)(p->pos_y + p->dir_y * mlx->move_speed * 4.0);
		if (map[(int)floor(p->pos_x)][y] != '1')
			p->pos_y += mlx->player->dir_y * mlx->move_speed;
	}
	y = (int)(p->pos_y - p->dir_y * mlx->move_speed * 4.0);
	x = (int)(p->pos_x - p->dir_x * mlx->move_speed * 4.0);
	if (mlx->key_s && map[x][y] != '1')
	{
		p->pos_x -= mlx->player->dir_x * mlx->move_speed;
		p->pos_y -= mlx->player->dir_y * mlx->move_speed;
	}
	p->angle += (mlx->key_a) ? mlx->rotate_speed : 0;
	p->angle -= (mlx->key_d) ? mlx->rotate_speed : 0;
}
