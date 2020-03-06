/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:21:53 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/05 23:52:00 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

/*
*** 0 = NORTH
*** 1 = SOUTH
*** 2 = EAST
*** 3 = WEST
*** 4 = SPRITE
*** path[4] is the POINTER to the PATH of the SPRITE FILE
*** ptr[0] is the POINTER to the NORTH IMAGE given by mlx_xpm_file_to_image()  
*** data[1] is a POINTER to the DATA from the SOUTH IMAGE given by mlx_get_data_addr()
*** size[2] is the MINIMUM BETWEEN the HEIGTH and the WIDTH of the EAST TEXTURE
*/

typedef struct	s_texture
{
	char		*path[5];
	void		*ptr[5];
	int			*data[5];
	int			size[5];
}				t_texture;

#endif
