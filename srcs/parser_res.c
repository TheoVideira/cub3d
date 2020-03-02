/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:33 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/02 14:36:34 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static int	check_line(char line, int *p)
{
	if (!line)
		return (0);
	if (!ft_isdigit(line))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

void		parse_res(char *line, t_parse_info *pi, t_game_info *gi)
{
	pi->r++;
	line++;
	while(ft_isspace(*line))
		line++;
	if (!check_line(*line, &(gi->resolution[0])))
		return ;
	gi->resolution[0] = ft_atoi(line);
	if (gi->resolution[0] < 1)
		gi->resolution[0] = -2;
	while (ft_isdigit(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	if (!check_line(*line, &(gi->resolution[1])))
		return ;
	gi->resolution[1] = ft_atoi(line);
	if (gi->resolution[1] < 1)
		gi->resolution[1] = -2;
	while (ft_isdigit(*line))
		line++;
	if (*line)
		gi->resolution[1] = -4;
}