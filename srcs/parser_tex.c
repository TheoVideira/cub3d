/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:22:04 by tvideira          #+#    #+#             */
/*   Updated: 2020/02/25 19:00:07 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void parse_north(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->no++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->no_path = ft_strdup(line);
}

void parse_south(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->so++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->so_path = ft_strdup(line);
}

void parse_east(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->ea++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->ea_path = ft_strdup(line);
}

void parse_west(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->we++;
    line += 2;
    while (ft_isspace(*line))
        line++;
    gi->we_path = ft_strdup(line);
}

void parse_sprite(char *line, t_parse_info *pi, t_game_info *gi)
{
    pi->s++;
    line++;
    while (ft_isspace(*line))
        line++;
    gi->sp_path = ft_strdup(line);
}
