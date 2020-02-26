#include "parser.h"

void check_cub_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	if (ft_strcmp(".cub", ft_strrchr(filename, '.')))
		ft_error("File isn't a .cub file");
}

void check_lines(char *filename)
{
	int fd;
	int gnl;
	int n;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	n = 0;
	while ((gnl = get_next_line(fd, &line)) > -1)
	{
		n++;
		if (*line && !is_identifier(line))
		{
			free(line);
			ft_error_line("Not empty line that isn't recognized", n);			
		}
		free(line);
		if (!gnl)
			break;
	}
}