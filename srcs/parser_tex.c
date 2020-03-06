/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:22:04 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/05 23:58:07 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void parse_north(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->no++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->texture.path[0] = ft_strdup(line);
}

void parse_south(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->so++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->texture.path[1] = ft_strdup(line);
}

void parse_east(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->ea++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->texture.path[2] = ft_strdup(line);
}

void parse_west(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->we++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->texture.path[3] = ft_strdup(line);
}

void parse_sprite(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->s++;
    line++;
    while (ft_isspace(*line))
        line++;
    gi->texture.path[4] = ft_strdup(line);
}
