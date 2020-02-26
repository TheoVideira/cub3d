#include "parser.h"

static int  check_end(char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line)
		return (0);
	return (1);
}
static int	check_line(char line, int *p)
{
	if (!line)
		return (0);
	if (!ft_isdigit(line))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

static int	check_separator(char *line, int *p)
{
	if (!*line)
		return (0);
	if (*line != ',' || !ft_isdigit(line[1]))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

void		parse_f_color(char *line, t_parse_info *pi, t_game_info *gi)
{
	int i;

	i = 0;
	pi->r++;
	line++;
	while(ft_isspace(*line))
		line++;
	if (!check_line(*line, &(gi->f_color[0])))
		return ;
	gi->f_color[0] = ft_atoi(line);
	if (gi->f_color[0] < 0 || gi->f_color[0] > 255)
		gi->f_color[0] = -2;
	while (++i < 3)
	{
		while (ft_isdigit(*line))
			line++;
		if (!check_separator(line, &(gi->f_color[i])))
			return ;
		line++;
		gi->f_color[i] = ft_atoi(line);
		if (gi->f_color[i] < 0 || gi->f_color[i] > 255)
			gi->f_color[i] = -2;
	}
	if (!check_end(line))
		gi->f_color[2] = -4;
}

void		parse_c_color(char *line, t_parse_info *pi, t_game_info *gi)
{
	int i;

	i = 0;
	pi->r++;
	line++;
	while(ft_isspace(*line))
		line++;
	if (!check_line(*line, &(gi->c_color[0])))
		return ;
	gi->c_color[0] = ft_atoi(line);
	if (gi->c_color[0] < 0 || gi->c_color[0] > 255)
		gi->c_color[0] = -2;
	while (++i < 3)
	{
		while (ft_isdigit(*line))
			line++;
		if (!check_separator(line, &(gi->c_color[i])))
			return ;
		line++;
		gi->c_color[i] = ft_atoi(line);
		if (gi->c_color[i] < 0 || gi->c_color[i] > 255)
			gi->c_color[i] = -2;
	}
	if (!check_end(line))
		gi->c_color[2] = -4;
}