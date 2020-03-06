/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:35:50 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 04:32:42 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

static void	init_render(t_dda *dda, t_player *p)
{
	p->dir_x = cos(p->angle);
	p->dir_y = sin(p->angle);
	dda->plane_x = p->dir_y;
	dda->plane_y = -p->dir_x;
}

void	create_background(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->gi.resolution[0] * cub->gi.resolution[1] / 2)
	{
		cub->mlx.screen[i] = cub->gi.c_color[0] << 16;
		cub->mlx.screen[i] += cub->gi.c_color[1] << 8;
		cub->mlx.screen[i] += cub->gi.c_color[2];
		i++;
	}
	while (i < cub->gi.resolution[0] * cub->gi.resolution[1])
	{
		cub->mlx.screen[i] = cub->gi.f_color[0] << 16;
		cub->mlx.screen[i] += cub->gi.f_color[1] << 8;
		cub->mlx.screen[i] += cub->gi.f_color[2];
		i++;
	}
}

void	render_wall(t_cub *cub)
{
	t_dda		dda;
	t_player	*p;
	int			i;

	p = &(cub->gi.player);
	init_render(&dda, p);
	dda.wall_dist = malloc(sizeof(double) * cub->gi.resolution[0]);
	movement_forward_backward(cub);
	i = -1;
	while(++i < cub->gi.resolution[0])
	{
		render_1(cub, &dda, p, i);
		render_2(&dda, p);
		render_3(&dda, cub->gi.map);
		render_4(&(cub->gi.texture), &dda, p, cub->gi.resolution[1]);
		render_5(cub, &(cub->gi.texture), &dda, i);
	}
	render_sprite(cub, &dda);
	free(dda.wall_dist);
}