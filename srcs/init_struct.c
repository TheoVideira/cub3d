/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:48 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/02 14:48:58 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_info.h"
#include "parser.h"

void init_parse_info(t_parse_info *pi)
{
	pi->r = 0;
	pi->s = 0;
	pi->f = 0;
	pi->c = 0;
	pi->no = 0;
	pi->so = 0;
	pi->we = 0;
	pi->ea = 0;
	pi->map = 0;
}

void init_game_info(t_game_info *gi)
{
	gi->resolution[0] = -1;
	gi->resolution[1] = -1;
	gi->f_color[0] = -1;
	gi->f_color[1] = -1;
	gi->f_color[2] = -1;
	gi->c_color[0] = -1;
	gi->c_color[1] = -1;
	gi->c_color[2] = -1;
	gi->no_path = NULL;
	gi->so_path = NULL;
	gi->ea_path = NULL;
	gi->we_path = NULL;
	gi->sp_path = NULL;
	gi->player.angle = -1.0;
	gi->player.pos_x = -1.0;
	gi->player.pos_y = -1.0;
	gi->player.dir_x = -1.0;
	gi->player.dir_y = -1.0;
}