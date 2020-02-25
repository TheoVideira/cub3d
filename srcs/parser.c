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
	if (!str[1] || str[1] == ' ' || str[1] == '\t')
		if (str[0] == 'R' || str[0] == 'S' || str[0] == 'F' || str[0] == 'C')
			return (1);
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	if (str[0] == 'S' && str[1] == 'O')
		return (1);
	if (str[0] == 'E' && str[1] == 'A')
		return (1);
	if (str[0] == 'W' && str[1] == 'E')
		return (1);
	return (0);
}

void	parse_line(char *str, t_parse_info *pi, t_game_info *gi)
{
	if (!str[1] || str[1] == ' ' || str[1] == '\t')
	{
		if (str[0] == 'R')
			return ;
		if (str[0] == 'S')
			parse_sprite(str, pi, gi);
		if (str[0] == 'F')
			return ;
		if (str[0] == 'C')
			return ;
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

int		parse_cub(char *filename, t_game_info *gi)
{
	t_parse_info	pi;
	int				fd = open(filename, O_RDONLY);
	char			*line;

	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		if (!*line)
			continue;
		if (is_identifier(line))
			parse_line(line, &pi, gi);
		free(line);
	}
	free(line);
	return (0);
}

int		main(int ac, char **av)
{
	t_game_info gi;

	if (ac != 2)
		return (-1);
	parse_cub(av[1], &gi);
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
