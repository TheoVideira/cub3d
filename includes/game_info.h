/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:55:30 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/21 15:33:24 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INFO_H
# define GAME_INFO_H
# include <fcntl.h>
# include "get_next_line.h"

typedef struct	s_game_info
{
	char	*file_path;
	int		resolution[2];
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*sp_path;
	int		f_color[3];
	int		c_color[3];
}				t_game_info;

void			get_resolution(t_game_info *gi);
void			get_ceil(t_game_info *gi);
void			get_floor(t_game_info *gi);
void			get_tex_no(t_game_info *gi);
void			init_game_info(t_game_info *gi);


#endif