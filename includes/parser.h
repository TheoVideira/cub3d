/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:48:37 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/02 15:05:42 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "game_info.h"
# include "libft.h"
# include "error.h"

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
	int map;
}				t_parse_info;

void	parse_north(char *line, t_parse_info *pi, t_game_info *gi);
void    parse_south(char *line, t_parse_info *pi, t_game_info *gi);
void    parse_east(char *line, t_parse_info *pi, t_game_info *gi);
void    parse_west(char *line, t_parse_info *pi, t_game_info *gi);
void    parse_sprite(char *line, t_parse_info *pi, t_game_info *gi);
void    parse_res(char *line, t_parse_info *pi, t_game_info *gi);
void    parse_f_color(char *line, t_parse_info *pi, t_game_info *gi);
void    parse_c_color(char *line, t_parse_info *pi, t_game_info *gi);
void    check_cub_file(char *filename);
void    check_lines(char *filename);
int     is_identifier(char *str);
void	init_parse_info(t_parse_info *pi);
void	check_map_1(char *filename, t_parse_info *pi);
void	check_map(char *filename, t_parse_info *pi);
void	check_map_2(char *filename);
void	check_resolution(t_parse_info *pi, t_game_info *gi);
void	check_f_color(t_parse_info *pi, t_game_info *gi);
void    check_c_color(t_parse_info *pi, t_game_info *gi);
void	check_no_tex(t_parse_info *pi, t_game_info *gi);
void	check_so_tex(t_parse_info *pi, t_game_info *gi);
void	check_ea_tex(t_parse_info *pi, t_game_info *gi);
void	check_we_tex(t_parse_info *pi, t_game_info *gi);
void	check_sp_tex(t_parse_info *pi, t_game_info *gi);
void	check_info(t_parse_info *pi, t_game_info *gi);
int     check_format(char *filename, char *format);
void	get_map_heigth(char *filename, t_game_info *gi);
void	parse_map(char *filename, t_game_info *gi);
void	get_map(char *filename, t_game_info *gi);
void	create_line_map(char *line, t_game_info *gi, int n);
int		is_valid_case(char c);
int		is_pos_case(char c);
void	init_player_values(char c, t_game_info *gi, int x, int y);
void	valid_case_player_pos_check(t_game_info *gi);


#endif
