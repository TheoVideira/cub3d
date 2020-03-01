#include "parser.h"

static void	ft_emergency(int fd, char **line)
{
	free(*line);
	close(fd);
}

void 		check_map_1(char *filename, t_parse_info *pi)
{
	int		fd;
	int		gnl;
	char	*line;
	int		inmap;

	inmap = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		if ((*line >= '0' && *line <= '2') && !inmap)
		{
			pi->map++;
			inmap = 1;
		}
		if (!(*line >= '0' && *line <= '2'))
			inmap = 0;
		free(line);
		if (!gnl)
			break;
	}
	close(fd);
}

void check_map_2(char *filename)
{
	int		fd;
	int		gnl;
	char	*line;
	int		found_map;
	int		n;

	n = 0;
	found_map = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	while ((gnl = get_next_line(fd, &line)) > -1 && (++n))
	{
		if ((*line == '0' || *line == '1'))
			found_map = 1;
		if (is_identifier(line) && found_map)
		{
			ft_emergency(fd, &line);
			ft_error_line("Map should be last elment of file", n);
		}
		free(line);
		if (!gnl)
			break;
	}
	close(fd);
}