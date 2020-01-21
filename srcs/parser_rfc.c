/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rfc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:25:18 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/21 15:37:56 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_info.h"
#include "error.h"
#include "utils.h"

static void	fill_numbers(int *tab, char *s, int n)
{
	int i;
	int k;

	i = 0;
	k = -1;
	while (++k < n)
	{
		while (!ft_isdigit(s[i]) && s[i])
			i++;
		tab[k] = ft_atoi(&s[i]);
		while (ft_isdigit(s[i]) && s[i])
			i++;
	}
}

void		get_resolution(t_game_info *gi)
{
	int		fd;
	char	*line;

	fd = open(gi->file_path, O_RDONLY);
	if (fd == -1)
		ft_error_no(errno);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			fill_numbers(gi->resolution, line, 2);
		free(line);
	}
	if (gi->resolution[0] <= 0 || gi->resolution[1] <= 0)
		ft_error("Error in finding resolution\n");
	close(fd);
}

void		get_ceil(t_game_info *gi)
{
	int		fd;
	char	*line;
	int		found;

	fd = open(gi->file_path, O_RDONLY);
	if (fd == -1)
		ft_error_no(errno);
	found = 0;
	while (get_next_line(fd, &line) && !found)
	{
		if ((found = (line[0] == 'C')))
			fill_numbers(gi->c_color, line, 3);
		free(line);
	}
	free(line);
	if (!found)
		ft_error("Error\nDidn't find ceil parameter\n");
	if (gi->f_color[0] < 0 || gi->f_color[0] > 255)
		ft_error("Error\nCeil red color out of range\n");
	if (gi->f_color[1] < 0 || gi->f_color[1] > 255)
		ft_error("Error\nCeil green color out of range\n");
	if (gi->f_color[2] < 0 || gi->f_color[2] > 255)
		ft_error("Error\nCeil blue color out of range\n");
	close(fd);
}

void		get_floor(t_game_info *gi)
{
	int		fd;
	char	*line;
	int		found;

	fd = open(gi->file_path, O_RDONLY);
	if (fd == -1)
		ft_error_no(errno);
	found = 0;
	while (get_next_line(fd, &line) && !found)
	{
		if ((found = (line[0] == 'F')))
			fill_numbers(gi->f_color, line, 3);
		free(line);
	}
	free(line);
	if (!found)
		ft_error("Error\nDidn't find floor parameter\n");
	if (gi->f_color[0] < 0 || gi->f_color[0] > 255)
		ft_error("Error\nFloor red color out of range\n");
	if (gi->f_color[1] < 0 || gi->f_color[1] > 255)
		ft_error("Error\nFloor green color out of range\n");
	if (gi->f_color[2] < 0 || gi->f_color[2] > 255)
		ft_error("Error\nFloor blue color out of range\n");
	close(fd);
}
