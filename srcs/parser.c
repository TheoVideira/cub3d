/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:22:39 by tvideira          #+#    #+#             */
/*   Updated: 2020/02/25 19:06:13 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		is_identifier(char *str)
{
	if (!str[0])
		return (0);
	if (!str[1] || ft_isspace(str[1]))
		if (str[0] == 'R' || str[0] == 'S' || str[0] == 'F' || str[0] == 'C')
			return (1);
	if (str[0] == 'N' && str[1] == 'O' && (!str[2] || ft_isspace(str[2])))
		return (1);
	if (str[0] == 'S' && str[1] == 'O' && (!str[2] || ft_isspace(str[2])))
		return (1);
	if (str[0] == 'E' && str[1] == 'A' && (!str[2] || ft_isspace(str[2])))
		return (1);
	if (str[0] == 'W' && str[1] == 'E' && (!str[2] || ft_isspace(str[2])))
		return (1);
	return (0);
}

void	parse_line(char *str, t_parse_info *pi, t_game_info *gi)
{
	if (!str[1] || str[1] == ' ' || str[1] == '\t')
	{
		if (str[0] == 'R')
			parse_res(str, pi, gi);
		if (str[0] == 'S')
			parse_sprite(str, pi, gi);
		if (str[0] == 'F')
			parse_f_color(str, pi, gi);
		if (str[0] == 'C')
			parse_c_color(str, pi, gi);
	}
	if (str[0] == 'N' && str[1] == 'O')
		parse_north(str, pi, gi);
	if (str[0] == 'S' && str[1] == 'O')
		parse_south(str, pi, gi);
	if (str[0] == 'E' && str[1] == 'A')
		parse_east(str, pi, gi);
	if (str[0] == 'W' && str[1] == 'E')
		parse_west(str, pi, gi);
}

void get_info(char *filename, t_parse_info *pi, t_game_info *gi)
{
	int fd;
	int gnl;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if (is_identifier(line))
			parse_line(line, pi, gi);
		free(line);
		if (!gnl)
			break;
	}
	close(fd);
}

int		parse_cub(char *filename, t_parse_info *pi, t_game_info *gi)
{
	check_cub_file(filename);
	check_lines(filename);
	check_map(filename, pi);
	get_info(filename, pi, gi);
	check_info(pi, gi);
	return (0);
}

int		main(int ac, char **av)
{
	t_game_info		gi;
	t_parse_info	pi;

	init_game_info(&gi);
	init_parse_info(&pi);
	if (ac != 2)
		return (-1);
	parse_cub(av[1], &pi, &gi);
	printf("resolution = %d, %d\n", gi.resolution[0], gi.resolution[1]);
	printf("ceil = r[%d], g[%d], b[%d]\n", gi.c_color[0], gi.c_color[1], gi.c_color[2]);
	printf("floor = r[%d], g[%d], b[%d]\n", gi.f_color[0], gi.f_color[1], gi.f_color[2]);
	printf("no_path = %s\n", gi.no_path);
	printf("so_path = %s\n", gi.so_path);
	printf("ea_path = %s\n", gi.ea_path);
	printf("we_path = %s\n", gi.we_path);
	printf("sp_path = %s\n", gi.sp_path);
	return (0);
}
