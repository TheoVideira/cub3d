/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:11:37 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/21 15:32:27 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_info.h"
#include "utils.h"

int	parser_tex(char *id, char **path, char *line)
{
	int i;
	int fd;

	if (!line || !*line)
		return (0);
	if (!(id[0] == line[0] && id[1] == line[1]))
		return (0);
	i = 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	if (parser_format(".xpm", ft_strrchr(line, '.')))
		return (0);
	if ((fd = open(&line[i], O_RDONLY)) == -1)
		return (0);
	close(fd);
	*path = ft_strdup(&line[i]);
	return ((!*path) ? 0 : 1);
}

int	parser_format(char *format, char *s)
{
	int len_f;
	int len_s;

	if (!format || !s)
		return (0);
	len_f = ft_strlen(format);
	len_s = ft_strlen(s);
	return (ft_strncmp(format, s, ft_max(len_f, len_s)));
}
