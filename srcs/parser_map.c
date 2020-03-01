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
	printf("heigth %d\n", heigth);
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

void	parse_map(char *filename, t_game_info *gi)
{
	get_map_heigth(filename, gi);
	get_map(filename, gi);
}

