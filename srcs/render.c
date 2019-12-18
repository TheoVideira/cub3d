/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:35:50 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/18 16:37:58 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "player.h"

static void	init_render(t_dda *dda, t_player *p)
{
	p->dir_x = cos(p->angle);
	p->dir_y = sin(p->angle);
	dda->plane_x = -p->dir_y;
	dda->plane_y = p->dir_x;
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

void	render_wall(t_mlx *mlx)
{
	t_dda		dda;
	t_player	p;
	int			i;
	char		c;

	init_render(&dda, &p);
	i = -1;
	while(++i < mlx->width)
	{
		dda.camera_x = 2 * i / mlx->width - 1;
		dda.ray_dir_x = p.dir_x + dda.camera_x * dda.plane_x;
		dda.ray_dir_y = p.dir_y + dda.camera_x * dda.plane_y;

		dda.delta_dist_x = 1.0 / dda.ray_dir_x;
		dda.delta_dist_y = 1.0 / dda.ray_dir_y;
		if (dda.delta_dist_x < 0.0)
			dda.delta_dist_x = -dda.delta_dist_x;
		if (dda.delta_dist_y < 0.0)
			dda.delta_dist_y = -dda.delta_dist_y;
		dda.ray_map_x = floor(p.dir_x);		
		dda.ray_map_y = floor(p.dir_y);		

		// RAY RIGHT
		if (dda.ray_dir_x > 0)
		{
			dda.step_x = 1;
			dda.side_dist_x = (dda.ray_map_x + 1.0 - p.pos_x) * dda.delta_dist_x;
		}
		// RAY LEFT
		if (dda.ray_dir_x < 0)
		{
			dda.step_x = -1;
			dda.side_dist_x = (p.pos_x - dda.ray_map_x) * dda.delta_dist_x;
		}
		// RAY UP
		if (dda.ray_dir_y > 0)
		{
			dda.step_y = 1;
			dda.side_dist_y = (dda.ray_map_y + 1.0 - p.pos_y) * dda.delta_dist_y;
		}
		// RAY DOWN
		if (dda.ray_dir_y < 0)
		{
			dda.step_y = -1;
			dda.side_dist_y = (p.pos_y - dda.ray_map_y) * dda.delta_dist_y;
		}
		c = mlx->map.map[(mlx->map.width - 1 - dda.ray_map_y) * mlx->map.width + dda.ray_map_x];
		while (c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		{
			if (dda.side_dist_x < dda.side_dist_y)
			{
				dda.side_dist_x += dda.delta_dist_x;
				dda.ray_map_x += dda.step_x;
				dda.side = 0;
			}
			else
			{
				dda.side_dist_y += dda.delta_dist_y;
				dda.ray_map_y += dda.step_y;
				dda.side = 1;
			}
		}
		
	}
}