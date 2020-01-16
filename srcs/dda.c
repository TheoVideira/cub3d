/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:25:02 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/14 20:50:21 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_1(t_mlx *mlx, t_dda *dda, t_player *p, int *i)
{
	dda->camera_x = 2.0 * (double)*i / (double)mlx->width - 1.0;
	dda->ray_dir_x = p->dir_x + dda->camera_x * dda->plane_x;
	dda->ray_dir_y = p->dir_y + dda->camera_x * dda->plane_y;
	dda->delta_dist_x = 1.0 / dda->ray_dir_x;
	dda->delta_dist_y = 1.0 / dda->ray_dir_y;
	if (dda->delta_dist_x < 0.0)
		dda->delta_dist_x = -dda->delta_dist_x;
	if (dda->delta_dist_y < 0.0)
		dda->delta_dist_y = -dda->delta_dist_y;
	dda->ray_map_x = floor(p->pos_x);
	dda->ray_map_y = floor(p->pos_y);
}

void	render_2(t_dda *dda, t_player *p)
{
	if (dda->ray_dir_x > 0)
	{
		dda->step_x = 1;
		dda->side_dist_x =
			(dda->ray_map_x + 1.0 - p->pos_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = -1;
		dda->side_dist_x = (p->pos_x - dda->ray_map_x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y > 0)
	{
		dda->step_y = 1;
		dda->side_dist_y =
			(dda->ray_map_y + 1.0 - p->pos_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = -1;
		dda->side_dist_y = (p->pos_y - dda->ray_map_y) * dda->delta_dist_y;
	}
}

void	render_3(t_dda *dda, t_map *map)
{
	char c;

	c = map->map[dda->ray_map_y * map->width + dda->ray_map_x];
	while (c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->ray_map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->ray_map_y += dda->step_y;
			dda->side = 1;
		}
		c = map->map[dda->ray_map_y * map->width + dda->ray_map_x];
	}
}

void	render_4(t_mlx *mlx, t_dda *dda, t_player *p)
{
	if (!dda->side)
		dda->distance = ((double)dda->ray_map_x - p->pos_x +
							(double)((1 - dda->step_x) / 2)) / dda->ray_dir_x;
	else
		dda->distance = ((double)dda->ray_map_y - p->pos_y +
							(double)((1 - dda->step_y) / 2)) / dda->ray_dir_y;
	dda->line_heigth = floor(mlx->height / dda->distance * 0.66);
	dda->draw_start =
				floor(-(dda->line_heigth) / 2.0 + (double)(mlx->height) / 2.0);
	if (!(dda->side))
		dda->wall_x = p->pos_y + dda->distance * dda->ray_dir_y;
	else
		dda->wall_x = p->pos_x + dda->distance * dda->ray_dir_x;
	dda->wall_x -= floor(dda->wall_x);
	dda->tex_x = dda->wall_x * (double)mlx->texture_size;
	if (!dda->side && dda->ray_dir_x < 0.0)
		dda->tex_x = (double)mlx->texture_size - dda->tex_x - 1.0;
	if (dda->side && dda->ray_dir_y > 0.0)
		dda->tex_x = (double)mlx->texture_size - dda->tex_x - 1.0;
	dda->tex_x = floor(dda->tex_x);
}

void	render_5(t_mlx *mlx, t_dda *dda, int i)
{
	int		t;
	int		index;
	int		index_t;
	double	ratio;
	double	y;

	if (!dda->side)
		t = (dda->ray_dir_x < 0.0) ? 0 : 1;
	else
		t = (dda->ray_dir_y > 0.0) ? 2 : 3;
	ratio = (double)mlx->texture_size / dda->line_heigth;
	y = (dda->draw_start < 0.0) ? -(dda->draw_start) : 0;
	while (y < floor(dda->line_heigth) &&
			y + dda->draw_start < (double)(mlx->height))
	{
		dda->tex_y = floor(y * ratio);
		index_t = dda->tex_y * mlx->texture_size + dda->tex_x;
		index = i + (dda->draw_start + y) * mlx->width;
		mlx->screen[index] = mlx->texture[t][index_t];
		y += 1.0;
	}
}
