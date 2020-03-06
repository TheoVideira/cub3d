/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 04:59:37 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 02:33:39 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_cub *cub, int i)
{
	int bits_per_pixel;
	int size_line;
	int endian;
	int width;
	int heigth;

	while (++i < 5)
	{
		if (!(cub->gi.texture.ptr[i] = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->gi.texture.path[i], &width, &heigth)))
    	    return (0);
   		cub->gi.texture.data[i] = (int *)mlx_get_data_addr(
			   cub->gi.texture.ptr[i], &bits_per_pixel, &size_line, &endian);
		if (endian != 0 || bits_per_pixel != 32)
			return (0);
		cub->gi.texture.size[i] = ft_min(width, heigth);
	}
	return (1);
}