/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 05:08:51 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/03 23:02:11 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "cub3d.h"
#include "render.h"
#include "game_info.h"
#include "parser.h"

static void	show_info(t_game_info *gi, t_mlx *mlx)
{
	int i;

	i = 0;
	printf("resolution = %d, %d\n", gi->resolution[0], gi->resolution[1]);
	printf("ceil = r[%d], g[%d], b[%d]\n", gi->c_color[0], gi->c_color[1], gi->c_color[2]);
	printf("floor = r[%d], g[%d], b[%d]\n", gi->f_color[0], gi->f_color[1], gi->f_color[2]);
	printf("no_path = %s\n", mlx->text_file[0]);
	printf("so_path = %s\n", mlx->text_file[1]);
	printf("we_path = %s\n", mlx->text_file[3]);
	printf("ea_path = %s\n", mlx->text_file[2]);
	printf("\nMap mlx:\n");
	while (mlx->map[i])
		printf("%s\n", mlx->map[i++]);
	printf("\nPlayer angle = %f\n", mlx->player->angle);
	printf("Player pos x = %f\n", mlx->player->pos_x);
	printf("Player pos y = %f\n", mlx->player->pos_y);
}

int		loop_hook(t_mlx *mlx)
{
	static int i = 0;
	/*if (i == 1)
	{
		save_first_frame(mlx, "sphere2.bmp");
		exit(0);
	}*/
	create_background(mlx);
	render_wall(mlx, mlx->map);
	mlx_put_image_to_window(mlx->id, mlx->window, mlx->img, 0, 0);
	printf("%d\n", i++);
	return (0);
}

int		init_screen(t_mlx *mlx)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	mlx->img = mlx_new_image(mlx->id, mlx->width, mlx->height);
	mlx->screen = (int *)mlx_get_data_addr(mlx->img, &bits_per_pixel, &size_line, &endian);
	mlx->key_w = 0;
	mlx->key_a = 0;
	mlx->key_s = 0;
	mlx->key_d = 0;
	mlx->key_l = 0;
	mlx->key_r = 0;
	mlx->move_speed = 0.06;
    mlx->rotate_speed = M_PI / 36.0;
	if (endian != 0 || bits_per_pixel != 32)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx		mlx;
	t_game_info		gi;
	t_parse_info	pi;

	if (argc != 2)
		return (-1);
	init_game_info(&gi);
	init_parse_info(&pi);
	parse_cub_file(argv[1], &pi, &gi);
	mlx.text_file[0] = gi.no_path;
	mlx.text_file[1] = gi.so_path;
	mlx.text_file[2] = gi.ea_path;
	mlx.text_file[3] = gi.we_path;
	mlx.height = gi.resolution[1];
	mlx.width = gi.resolution[0];
	mlx.map = gi.map;
	if (!(mlx.id = mlx_init()) || !init_screen(&mlx) || !init_textures(&mlx))
		return (-1);
	if (!(mlx.window = mlx_new_window(mlx.id, mlx.width, mlx.height, "cub3D")))
		return (-1);
	mlx.player = &(gi.player);
	show_info(&gi, &mlx);
	mlx_hook(mlx.window, KEYPRESS, 0, key_press, &mlx);
    mlx_hook(mlx.window, KEYRELEASE, 0, key_release, &mlx);
    mlx_hook(mlx.window, DESTROYNOTIFY, 0, quit_window, &mlx);
	mlx_loop_hook(mlx.id, loop_hook, &mlx);
	mlx_loop(mlx.id);
	return (0);
}
