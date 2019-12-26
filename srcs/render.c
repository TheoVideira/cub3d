/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:35:50 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/26 11:38:28 by tvideira         ###   ########.fr       */
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
	t_dda		dda;
	t_player	*p;
	int			i;
	char		c;

	p = mlx->player;
	init_render(&dda, p);
	i = -1;
	while(++i < mlx->width)
	{
		dda.camera_x = 2.0 * (double)i / (double)mlx->width - 1.0;
		dda.ray_dir_x = p->dir_x + dda.camera_x * dda.plane_x;
		dda.ray_dir_y = p->dir_y + dda.camera_x * dda.plane_y;
		dda.delta_dist_x = 1.0 / dda.ray_dir_x;
		dda.delta_dist_y = 1.0 / dda.ray_dir_y;
		if (dda.delta_dist_x < 0.0)
			dda.delta_dist_x = -dda.delta_dist_x;
		if (dda.delta_dist_y < 0.0)
			dda.delta_dist_y = -dda.delta_dist_y;
		dda.ray_map_x = floor(p->pos_x);		
		dda.ray_map_y = floor(p->pos_y);		
		// RAY RIGHT
		if (dda.ray_dir_x > 0)
		{
			dda.step_x = 1;
			dda.side_dist_x = (dda.ray_map_x + 1.0 - p->pos_x) * dda.delta_dist_x;
		}
		// RAY LEFT
		else
		{
			dda.step_x = -1;
			dda.side_dist_x = (p->pos_x - dda.ray_map_x) * dda.delta_dist_x;
		}
		// RAY UP
		if (dda.ray_dir_y > 0)
		{
			dda.step_y = 1;
			dda.side_dist_y = (dda.ray_map_y + 1.0 - p->pos_y) * dda.delta_dist_y;
		}
		// RAY DOWN
		else
		{
			dda.step_y = -1;
			dda.side_dist_y = (p->pos_y - dda.ray_map_y) * dda.delta_dist_y;
		}
		c = map->map[dda.ray_map_y * map->width + dda.ray_map_x];
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
			c = map->map[dda.ray_map_y * map->width + dda.ray_map_x];
		}
		if (!dda.side)
			dda.distance = ((double)dda.ray_map_x - p->pos_x + (double)((1 - dda.step_x) / 2)) / dda.ray_dir_x;
		else
			dda.distance = ((double)dda.ray_map_y - p->pos_y + (double)((1 - dda.step_y) / 2)) / dda.ray_dir_y;		
		double line_heigth = floor(mlx->height / dda.distance * 0.66);
		double draw_start = floor(-line_heigth / 2.0 + (double)(mlx->height) / 2.0);
		//double draw_end = floor(line_heigth / 2.0 + (double)(mlx->height) / 2.0);

		if (!dda.side)
			dda.wall_x = (p->pos_y + dda.distance * (double)dda.ray_map_y);
		else
			dda.wall_x = (p->pos_x + dda.distance * (double)dda.ray_map_x);		

		dda.wall_x -= floor(dda.wall_x); 

		double tex_x = dda.wall_x * (double)mlx->texture_size;
		if (!dda.side && dda.ray_dir_x < 0.0)
			tex_x = (double)mlx->texture_size - tex_x - 1.0;
		if (dda.side && dda.ray_dir_y > 0.0)
			tex_x = (double)mlx->texture_size - tex_x - 1.0;
		tex_x = floor(tex_x);
	
	// AJOUT TEXTURES
	int t;
	if (!dda.side)
		if (dda.ray_dir_x < 0.0)
			t = 0;
		else
			t = 1;
	else
		if (dda.ray_dir_y > 0.0)
			t = 2;
		else
			t = 3;
	//

		double ratio = (double)mlx->texture_size / line_heigth; 

		double y = (draw_start < 0.0) ? -draw_start : 0;

		while (y < floor(line_heigth) && y + draw_start < (double)(mlx->height))
		{
			double tex_y = floor(y * ratio);
			int index_t = tex_y * mlx->texture_size + tex_x;

			int index = i + (draw_start + y) * mlx->width;
			mlx->screen[index] = mlx->texture[t][index_t];
			y += 1.0;
		}
	}
}