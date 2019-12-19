/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:35:50 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/19 11:21:49 by tvideira         ###   ########.fr       */
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
//		printf("DEBUT \n");
		dda.camera_x = 2.0 * (double)i / (double)mlx->width - 1.0;
		dda.ray_dir_x = p->dir_x + dda.camera_x * dda.plane_x;
		dda.ray_dir_y = p->dir_y + dda.camera_x * dda.plane_y;
//		printf("DEBUG 1\n");
		dda.delta_dist_x = 1.0 / dda.ray_dir_x;
		dda.delta_dist_y = 1.0 / dda.ray_dir_y;
//		printf("DEBUG 2\n");
		if (dda.delta_dist_x < 0.0)
			dda.delta_dist_x = -dda.delta_dist_x;
		if (dda.delta_dist_y < 0.0)
			dda.delta_dist_y = -dda.delta_dist_y;
		dda.ray_map_x = floor(p->pos_x);		
		dda.ray_map_y = floor(p->pos_y);		
//		printf("DEBUG 3\n");
		// RAY RIGHT
		if (dda.ray_dir_x > 0)
		{
			dda.step_x = 1;
			dda.side_dist_x = (dda.ray_map_x + 1.0 - p->pos_x) * dda.delta_dist_x;
		}
//		printf("DEBUG 4\n");
		// RAY LEFT
		else
		{
			dda.step_x = -1;
			dda.side_dist_x = (p->pos_x - dda.ray_map_x) * dda.delta_dist_x;
		}
//		printf("DEBUG 5\n");
		// RAY UP
		if (dda.ray_dir_y > 0)
		{
			dda.step_y = 1;
			dda.side_dist_y = (dda.ray_map_y + 1.0 - p->pos_y) * dda.delta_dist_y;
		}
//		printf("DEBUG 6\n");
		// RAY DOWN
		else
		{
			dda.step_y = -1;
			dda.side_dist_y = (p->pos_y - dda.ray_map_y) * dda.delta_dist_y;
		}
//		printf("DEBUG 7\n");
//		printf("i = %i\n", (map->width - 1 - dda.ray_map_y) * map->width + dda.ray_map_x);
//		fflush(stdout);
		c = map->map[dda.ray_map_y * map->width + dda.ray_map_x];
//		printf("r %d, i = %i, c = %c\n", dda.ray_map_x, i, c);
//		fflush(stdout);
//		printf("AVANT PREMIERE BOUCLE\n");
//		fflush(stdout);
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
//		printf("APRES PREMIERE BOUCLE\n");
//		fflush(stdout);
		if (!dda.side)
			dda.distance = (dda.ray_map_x - p->pos_x + (double)((1 - dda.step_x) / 2)) / dda.ray_dir_x;
		else
			dda.distance = (dda.ray_map_y - p->pos_y + (double)((1 - dda.step_y) / 2)) / dda.ray_dir_y;		
		double line_heigth = floor(mlx->height / dda.distance * 0.66);
		double draw_start = floor(-line_heigth / 2.0 + (double)(mlx->height) / 2.0);
		//double draw_end = floor(line_heigth / 2.0 + (double)(mlx->height) / 2.0);

/*		if (!dda.side)
			dda.wall_x = (dda.ray_map_x - p->pos_x + (double)((1 - dda.step_x) / 2)) / dda.ray_dir_x;
		else
			dda.distance = (dda.ray_map_y - p->pos_y + (double)((1 - dda.step_y) / 2)) / dda.ray_dir_y;		
*/
		double y = (draw_start < 0.0) ? -draw_start : 0;
//		printf("AVANT SECONDE BOUCLE\n");
//		fflush(stdout);
		while (y < floor(line_heigth) && y + draw_start < (double)(mlx->height))
		{
			int index = i + (draw_start + y) * mlx->width;
//			printf("index = %d", index);
			mlx->screen[index] = 0;
			y += 1.0;
		}
	}
}