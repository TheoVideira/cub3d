/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:32:09 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/18 15:06:02 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct	s_player
{
	double	angle;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}				t_player;

#endif