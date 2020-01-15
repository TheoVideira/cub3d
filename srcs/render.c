/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:35:50 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/15 11:51:58 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "player.h"
#include <stdio.h>

static void	init_render(t_dda *dda, t_player *p)
{
	p->dir_x = cos(p->angle);
	p->dir_y = sin(p->angle);
	dda->plane_x = p->dir_y;
	dda->plane_y = -p->dir_x;
}

void	create_background(t_mlx *mlx)
{
	int				i;
	unsigned int	color;

	i = 0;
	color = 255;
	while (i < mlx->width * mlx->height / 2)
	{
		mlx->screen[i] = color;
		i++;
	}
	while (i < mlx->width * mlx->height)
	{
		mlx->screen[i] = color << 16;
		i++;
	}
}

void	render_wall(t_mlx *mlx, t_map *map)
{
	t_dda		d;
	t_dda		*dda;
	t_player	*p;
	int			i;

	p = mlx->player;
	init_render(&d, p);
	movement(mlx);
	dda = &d;
	i = -1;
	while(++i < mlx->width)
	{
		render_1(mlx, dda, p, &i);
		render_2(dda, p);
		render_3(dda, map);
		render_4(mlx, dda, p);
		render_5(mlx, dda, i);
	}
}