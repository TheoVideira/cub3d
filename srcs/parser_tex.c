/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:18:02 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/21 15:38:30 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_info.h"
#include "error.h"
#include "utils.h"

void		get_tex_no(t_game_info *gi)
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
		if (parser_tex("NO", &(gi->no_path), line))
			found = 1;
		free(line);
	}
	free(line);
	if (!found)
		ft_error("Error\nDidn't find valid NO texture configuration\n");
}
