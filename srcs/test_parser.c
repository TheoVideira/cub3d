#include "game_info.h"
#include "error.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av)
{
	t_game_info gi;

	if (ac < 2 || ac > 3)
		ft_error("Invalid number of argument.\nExit program...\n");
	gi.file_path = av[1];
	get_resolution(&gi);
	get_ceil(&gi);
	get_floor(&gi);
	get_tex_no(&gi);
	printf("resolution = %d, %d\n", gi.resolution[0], gi.resolution[1]);
	printf("ceil = r[%d], g[%d], b[%d]\n", gi.c_color[0], gi.c_color[1], gi.c_color[2]);
	printf("floor = r[%d], g[%d], b[%d]\n", gi.f_color[0], gi.f_color[1], gi.f_color[2]);
	printf("no_path = %s\n", gi.no_path);
	return (0);
}
