/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:32:57 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/09 15:02:05 by tvideira         ###   ########.fr       */
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

    x = 10.5;
    y = 9.5;

    pX = x - cub->gi.player.pos_x;
    pY = y - cub->gi.player.pos_y;

    invDet = 1.0 / (dda->plane_x * cub->gi.player.dir_y - cub->gi.player.dir_x * dda->plane_y);
    tmp = pX;
    pX = invDet * (cub->gi.player.dir_y * pX - cub->gi.player.dir_x * pY);
    pY = invDet * (-dda->plane_y * tmp + dda->plane_x * pY);
    
    sprite_screen_x = (int)floor(((double)cub->gi.resolution[0] / 2.0) * (1.0 + pX / pY));
    
    sprite_size = (int)floor(fabs((double)cub->gi.resolution[1] / pY * 0.7));

    Ystart = (int)((double)cub->gi.resolution[1] / 2.0 - (double)sprite_size / 2.0);
	Yend = (int)((double)cub->gi.resolution[1] / 2.0 + (double)sprite_size / 2.0);

    Xstart = (int)((double)-sprite_size / 2.0 + (double)sprite_screen_x);
    Xend = (int)((double)sprite_size / 2.0 + (double)sprite_screen_x);
	Xend = (Xend > cub->gi.resolution[0]) ? cub->gi.resolution[0] : Xend ;

    ratio = (double)cub->gi.texture.size[4] / (double)sprite_size;
    for (int i = Xstart; i < Xend; i++)
    {
        if (dda->wall_dist[i] >= pY && pY >= 0)
        {
            for (int j = (Ystart > 0) ? Ystart : 0; j < cub->gi.resolution[1] && j < Yend; j++)
            {
                tmp = floor((double)(j - Ystart) * ratio);
                indexa = (i + j * cub->gi.resolution[0]);
                indexb = (int)((double)(i - Xstart) * ratio + tmp * cub->gi.texture.size[4]);
                if ((cub->gi.texture.data[4][indexb] & 0x00FFFFFF) != 0)
                    cub->mlx.screen[indexa] = cub->gi.texture.data[4][indexb];
            }
        }
    } 
}