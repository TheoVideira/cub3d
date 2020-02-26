/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:48:37 by tvideira          #+#    #+#             */
/*   Updated: 2020/02/25 19:00:55 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "game_info.h"
# include "libft.h"

typedef struct	s_parse_info
{
    int r;
    int no;
    int so;
    int ea;
    int we;
    int s;
    int f;
    int c;
}				t_parse_info;

void parse_north(char *line, t_parse_info *pi, t_game_info *gi);
void parse_south(char *line, t_parse_info *pi, t_game_info *gi);
void parse_east(char *line, t_parse_info *pi, t_game_info *gi);
void parse_west(char *line, t_parse_info *pi, t_game_info *gi);
void parse_sprite(char *line, t_parse_info *pi, t_game_info *gi);
void parse_res(char *line, t_parse_info *pi, t_game_info *gi);
void parse_f_color(char *line, t_parse_info *pi, t_game_info *gi);
void parse_c_color(char *line, t_parse_info *pi, t_game_info *gi);



#endif