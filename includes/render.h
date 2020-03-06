/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:35:58 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 03:48:20 by tvideira         ###   ########.fr       */
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
	double	tex_x;
	double	tex_y;
	double	draw_start;
	double	line_heigth;
	int		id_tex;
}				t_dda;

void			render_1(t_cub *cub, t_dda *dda, t_player *p, int i);
void			render_2(t_dda *dda, t_player *p);
void			render_3(t_dda *dda, char **map);
void			render_4(t_texture *tex,
					t_dda *dda, t_player *p, double height);
void			render_5(t_cub *cub, t_texture *tex, t_dda *dda, int i);
#endif