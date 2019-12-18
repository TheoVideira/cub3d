/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:46:43 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/18 16:06:28 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <math.h>
# include "map.h"

typedef struct	s_mlx
{
	void	*id;
	int		width;
	int		height;
	void	*window;
	int		*screen;
	int		*img;
	t_map	map;
}				t_mlx;

#endif