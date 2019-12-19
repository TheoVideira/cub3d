/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:35:58 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/19 06:52:08 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef RENDER_H
# define RENDER_H

typedef struct	s_dda
{
	int		side;
	int		ray_map_x;
	int		ray_map_y;
	int		step_x;
	int		step_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	distance;
	double	wall_x;
}				t_dda;

void			create_background(t_mlx *mlx);
void			render_wall(t_mlx *mlx, t_map *map);

#endif