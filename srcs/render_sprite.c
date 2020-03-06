/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:32:57 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 05:15:56 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"

void    render_sprite(t_cub *cub, t_dda *dda)
{
    //Sprite coordinates
    double x, y;
    // Relative player coordinates
    double pX, pY;
    // Coeff inversion matrix
    double invDet;

    double  ratio;
    double  tmp;
    int     sprite_size, sprite_screen_x;
    int     Ystart, Yend, Xstart, Xend;
    int     indexa, indexb;

    x = 15.0;
    y = 10.0;

    pX = x - cub->gi.player.pos_x;
    pY = y - cub->gi.player.pos_y;

    invDet = 1.0 / (dda->plane_x * cub->gi.player.dir_y - cub->gi.player.dir_x * dda->plane_y);
    tmp = pX;
    pX = invDet * (cub->gi.player.dir_y * pX - cub->gi.player.dir_x * pY);
    pY = invDet * (-dda->plane_y * tmp + dda->plane_x * pY);
    sprite_screen_x = (int)floor((double)(cub->gi.resolution[0] / 2) * (1.0 + pX / pY));
    sprite_size = (int)floor(fabs((double)cub->gi.resolution[1] / pY));

    Ystart = (cub->gi.resolution[1] / 2 - sprite_size / 2);
	Yend = (cub->gi.resolution[1] / 2 + sprite_size / 2);
	
    Xstart = ~~(-sprite_size / 2 + sprite_screen_x);
    Xend = sprite_size / 2 + sprite_screen_x;
	Xend = (Xend > cub->gi.resolution[0]) ? cub->gi.resolution[0] : Xend ;

    ratio = cub->gi.resolution[0] / (double)sprite_size;
    for (int i = Xstart; i < Xend; i++)
    {
        if (dda->wall_dist[i] >= pY && pY >= 0)
        {
            for (int j = (Ystart > 0) ? Ystart : 0; j < cub->gi.resolution[1]; j++)
            {
                tmp = (double)(j - Ystart) * ratio;
                indexa = i + j * cub->gi.resolution[0];
                indexb = (int)floor((double)(i - Xstart) * ratio + tmp * (double)cub->gi.resolution[0]);
                cub->mlx.screen[indexa] = cub->gi.texture.data[4][indexb];
            }
        }
    } 
}