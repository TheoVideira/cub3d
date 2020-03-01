#include "parser.h"

void check_cub_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_no(errno);
	if (check_format(filename, ".cub"))
	{
		close(fd);
		ft_error("File isn't a .cub file\n");
	}
	close(fd);
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
		if (*line && (!is_identifier(line) && (*line < '0' || *line > '2')))
		{
			free(line);
			close(fd);
			ft_error_line("Not empty line that isn't recognized\n", n);			
		}
		free(line);
		if (!gnl)
			break;
	}
	close(fd);
}

void check_map(char *filename, t_parse_info *pi)
{
	check_map_1(filename, pi);
	if (pi->map == 0)
		ft_error("Map error : No map found");
	if (pi->map != 1)
		ft_error("Map error : There should be one map on the file\
		\nHint : remove empty lines in its declaration.\n");
	check_map_2(filename);
}

void check_info(t_parse_info *pi, t_game_info *gi)
{
	check_resolution(pi, gi);
	check_f_color(pi, gi);
	check_c_color(pi, gi);
	check_no_tex(pi, gi);
	check_so_tex(pi, gi);
	check_ea_tex(pi, gi);
	check_we_tex(pi, gi);
	check_sp_tex(pi, gi);
}