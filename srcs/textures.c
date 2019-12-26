/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 04:59:37 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/26 11:07:36 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_mlx *mlx)
{
	int *texture;
	int bits_per_pixel;
	int size_line;
	int endian;
	int i;

	i = -1;
	while (++i < 4)
	{
		if (!(texture = mlx_xpm_file_to_image(mlx->id, mlx->text_file[i], &mlx->texture_size, &mlx->texture_size)))
    	    return (0);
   		mlx->texture[i] = (int *)mlx_get_data_addr(texture, &bits_per_pixel, &size_line, &endian);
		if (endian != 0 || bits_per_pixel != 32)
			return (0);
	}
	return (1);
}