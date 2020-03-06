/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:55:30 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 02:42:13 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INFO_H
# define GAME_INFO_H
# include <fcntl.h>
# include "get_next_line.h"
# include "player.h"
# include "texture.h"

typedef struct	s_game_info
{
	char		*file_path;
	int			resolution[2];
	int			f_color[3];
	int			c_color[3];
	t_texture	texture;
	char		**map;
	t_player	player;
}				t_game_info;

void			get_resolution(t_game_info *gi);
void			get_ceil(t_game_info *gi);
void			get_floor(t_game_info *gi);
void			get_tex_no(t_game_info *gi);
void			init_game_info(t_game_info *gi);


#endif