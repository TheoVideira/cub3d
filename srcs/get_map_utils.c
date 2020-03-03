/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:13 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/03 23:03:01 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <math.h>

int		is_valid_case(char c)
{
	return ((c >= '0' && c <= '2')
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int		is_pos_case(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	init_player_values(char c, t_game_info *gi, int x, int y)
{
	if (gi->player.angle != -1.0)
	{
		ft_emergency_split(gi->map);
		ft_error_free("Map error : Player position should appear once\n", gi);
	}
	if (c == 'N')
		gi->player.angle = M_PI / 2.0;
	else if (c == 'S')
		gi->player.angle = 3.0 * M_PI / 2.0;
	else if (c == 'E')
		gi->player.angle = 0.0;
	else
		gi->player.angle = M_PI;
	gi->player.pos_x = (double)x + 0.5;
	gi->player.pos_y = (double)y + 0.5;
}

void	create_line_map(char *line, t_game_info *gi, int n)
{
	char	**split;
	int		len;
	int		i;	

	i = -1;
	len = 0;
	split = ft_split(line, ' ');
	while (split[++i])
		len += ft_strlen(split[i]);
	if (!(gi->map[n] = ft_calloc(1, sizeof(char) * len + 1)))
	{
		ft_emergency_split(split);
		ft_emergency_split(gi->map);
		ft_error_free("error during calloc\n", gi);
	}
	i = -1;
	while(split[++i])
		ft_strlcat(gi->map[n], split[i], len + 1);
	ft_emergency_split(split);
}