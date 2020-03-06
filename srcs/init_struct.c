/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:48 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 00:26:18 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	init_parse_info(&(cub->pi));
	init_game_info(&(cub->gi));
	init_input(&(cub->input));
}

void	init_parse_info(t_parse_info *pi)
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

void	init_game_info(t_game_info *gi)
{
	gi->resolution[0] = -1;
	gi->resolution[1] = -1;
	gi->f_color[0] = -1;
	gi->f_color[1] = -1;
	gi->f_color[2] = -1;
	gi->c_color[0] = -1;
	gi->c_color[1] = -1;
	gi->c_color[2] = -1;
	gi->texture.path[0] = NULL;
	gi->texture.path[1] = NULL;
	gi->texture.path[2] = NULL;
	gi->texture.path[3] = NULL;
	gi->texture.path[4] = NULL;
	gi->player.angle = -1.0;
	gi->player.pos_x = -1.0;
	gi->player.pos_y = -1.0;
	gi->player.dir_x = -1.0;
	gi->player.dir_y = -1.0;
}

void	init_input(t_input *input)
{
	input->key_forward = 0;
	input->key_backward = 0;
	input->key_left = 0;
	input->key_right = 0;
	input->key_rotate_left = 0;
	input->key_rotate_right = 0;
}
