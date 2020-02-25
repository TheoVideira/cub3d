/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:46:43 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/16 14:37:43 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <math.h>
# include "map.h"
# include "player.h"
# define KeyPressMask			(1L<<0)  
# define KeyReleaseMask			(1L<<1)  
# define KeyPress		2
# define KeyRelease		3

typedef struct	s_mlx
{
	void		*id;
	int			width;
	int			height;
	void		*window;
	int			*screen;
	int			*img;
	t_map		*map;
	t_player	*player;
	int			texture_size;
	char		*text_file[4];
	int			*texture[4];
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	double		move_speed;
	double		rotate_speed;
}				t_mlx;

int     key_press(int key, t_mlx *mlx);
int     key_release(int key, t_mlx *mlx);
int		init_textures(t_mlx *mlx);
void	movement(t_mlx *mlx);
#endif