/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:25:02 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/27 19:09:36 by tvideira         ###   ########.fr       */
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
	// RAY RIGHT
	if (dda->ray_dir_x > 0)
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->ray_map_x + 1.0 - p->pos_x) * dda->delta_dist_x;
	}
	// RAY LEFT
	else
	{
		dda->step_x = -1;
		dda->side_dist_x = (p->pos_x - dda->ray_map_x) * dda->delta_dist_x;
	}
	// RAY UP
	if (dda->ray_dir_y > 0)
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->ray_map_y + 1.0 - p->pos_y) * dda->delta_dist_y;
	}
	// RAY DOWN
	else
	{
		dda->step_y = -1;
		dda->side_dist_y = (p->pos_y - dda->ray_map_y) * dda->delta_dist_y;
	}
}