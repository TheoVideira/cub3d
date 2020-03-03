/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:51:45 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/02 18:09:33 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int     check_left_right(t_game_info *gi, int x, int y)
{
	int n;
	int l;
	int r;

	r = 0;
	l = 0;
	n = y;
	while (y >= 0)
	{
		if (gi->map[x][y] == '1')
			l = 1;
		y--;
	}
	y = n;
	while (gi->map[x][y])
	{
		if (gi->map[x][y] == '1')
			r = 1;
		y++;
	}
	return (l && r);
}

int     check_top_bottom(t_game_info *gi, int x, int y)
{
	int n;
	int b;
	int t;

	b = 0;
	t = 0;
	n = x;
	while (x >= 0 && y < (int)ft_strlen(gi->map[x]))
	{
		if (gi->map[x][y] == '1')
			t = 1;
		x--;
	}
	x = n;
	while (gi->map[x] && y < (int)ft_strlen(gi->map[x]))
	{
		if (gi->map[x][y] == '1')
			b = 1;
		x++;
	}
	return (b && t);
}