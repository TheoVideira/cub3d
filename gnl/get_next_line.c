/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 03:30:14 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/30 15:55:26 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_error(char **line, char **buffer)
{
	free(*line);
	if (line && *line)
		*line = NULL;
	if (buffer)
		free(*buffer);
	if (buffer && *buffer)
		*buffer = NULL;
	return (-1);
}

int			create_line(int fd, char **line, char **buffer)
{
	int r;
	int i;

	while ((r = read(fd, *buffer, BUFFER_SIZE)) > 0)
	{
		i = find_next_line(*buffer);
		if (i < BUFFER_SIZE && buffer[0][i])
			return (r);
		if (!(*line = gnl_strjoin(*line, *buffer)))
			return (ft_error(line, NULL));
		gnl_bzero(*buffer, BUFFER_SIZE + 1);
	}
	if (!r)
	{
		*line = gnl_strjoin(*line, *buffer);
		return (0);
	}
	return (ft_error(line, NULL));
}

int			finish_line(char *buffer, char **line, char **remaining, int r)
{
	char	*sub_to_print;
	int		i;

	i = find_next_line(buffer);
	if (!(sub_to_print = gnl_substr(buffer, 0, i)))
		return (ft_error(line, &buffer));
	if (!(*line = gnl_strjoin(*line, sub_to_print)))
	{
		free(sub_to_print);
		return (ft_error(line, &buffer));
	}
	free(sub_to_print);
	if (buffer[i])
		if (!(*remaining = gnl_substr(buffer, i + 1, BUFFER_SIZE - i - 1)))
			return (ft_error(line, &buffer));
	i = (buffer[i] || r == BUFFER_SIZE) ? 1 : 0;
	free(buffer);
	return (i);
}

int			get_next_line(int fd, char **line)
{
	static char *remaining[1024];
	char		*buffer;
	int			r;

	if (fd < 0 || fd > 1023 || !line || BUFFER_SIZE < 1)
	{
		*line = NULL;
		return (-1);
	}
	*line = NULL;
	if (remaining[fd] && remaining[fd][find_next_line(remaining[fd])])
		return (finish_line(remaining[fd], line, &remaining[fd], BUFFER_SIZE));
	*line = remaining[fd];
	remaining[fd] = NULL;
	if (!(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	gnl_bzero(buffer, BUFFER_SIZE + 1);
	if ((r = create_line(fd, line, &buffer)) < 1)
	{
		free(buffer);
		return (r);
	}
	return (finish_line(buffer, line, &remaining[fd], r));
}
