/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:36:21 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/03 22:09:11 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_map_heigth(char *filename, t_game_info *gi)
{
	int fd;
	int gnl;
	char *line;
	int heigth;

	heigth = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no_free(errno, gi);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if (*line >= '0' && *line <= '2')
			heigth++;
		free(line);
		if (!gnl)
			break;
	}
	if(!(gi->map = malloc(sizeof(char *) * heigth)))
		ft_error_free("malloc error\n", gi);
	while(--heigth >= 0)
		gi->map[heigth] = NULL;
	close(fd);
}

void	get_map(char *filename, t_game_info *gi)
{
	int		fd;
	int		gnl;
	char	*line;
	int		n;

	n = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no_free(errno, gi);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if (*line >= '0' && *line <= '2')
		{
			create_line_map(line, gi, n);
			n++;
		}
		free(line);
		if (!gnl)
			break;
	}
	close(fd);
}

void	valid_case_player_pos_check(t_game_info *gi)
{
	int i;
	int j;

	i = -1;
	while(gi->map[++i])
	{
		j = -1;
		while(gi->map[i][++j])
		{
			if (!is_valid_case(gi->map[i][j]))
			{
				ft_emergency_split(gi->map);
				ft_error_free("Map contains invalid value\n", gi);
			}
			if(is_pos_case(gi->map[i][j]))
				init_player_values(gi->map[i][j], gi, j, i);
		}
	}
	if (gi->player.angle == -1.0)
	{
		ft_emergency_split(gi->map);
		ft_error_free("Map is missing player position\n", gi);
	}
}

void	check_closed_map(t_game_info *gi)
{
	int i;
	int j;

	i = -1;
	while(gi->map[++i])
	{
		j = -1;
		while(gi->map[i][++j])
		{
			if ((!check_left_right(gi, i, j)) || (!check_top_bottom(gi, i, j)))
			{
				ft_emergency_split(gi->map);
				ft_error_free("Map isn't closed\n", gi);
			}
		}
	}
}

void	parse_map(char *filename, t_game_info *gi)
{
	get_map_heigth(filename, gi);
	get_map(filename, gi);
	valid_case_player_pos_check(gi);
	check_closed_map(gi);
}

