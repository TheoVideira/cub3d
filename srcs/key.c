/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:59:12 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/19 11:22:31 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int     key_press(int key, t_mlx *mlx)
{
	double move_speed;
	double rotate_speed;

	move_speed = 0.06;
    rotate_speed = M_PI / 36.0;
	if (key == 13) // w
	{
        mlx->player->pos_x += mlx->player->dir_x * move_speed;
        mlx->player->pos_y += mlx->player->dir_y * move_speed;
	}
	if (key == 1) // s
	{
        mlx->player->pos_x -= mlx->player->dir_x * move_speed;
        mlx->player->pos_y -= mlx->player->dir_y * move_speed;
	}
    if (key == 0) // LEFT A
		mlx->player->angle += rotate_speed;
    if (key == 2) // RIGHT D
		mlx->player->angle -= rotate_speed;
    if (key == 53) // ESC
        exit(0);
    return (1);
}

int     key_release(int key, t_mlx *mlx)
{
    if (key == 13) // w
	{
        mlx->player->pos_x += 0;
        mlx->player->pos_y += 0;
	}
	if (key == 1) // s
	{
        mlx->player->pos_x -= 0;
        mlx->player->pos_y -= 0;
	}
    if (key == 0) // LEFT A
		mlx->player->angle += 0;
    if (key == 2)// RIGHT D
		mlx->player->angle -= 0;
    return (1);
}