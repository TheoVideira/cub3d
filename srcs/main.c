/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 05:08:51 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/16 18:19:46 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "cub3d.h"
#include "render.h"


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
	mlx->move_speed = 0.06;
    mlx->rotate_speed = M_PI / 36.0;
	if (endian != 0 || bits_per_pixel != 32)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_player	p;
	t_mlx		mlx;
	t_map		map;
	int			fd1;
	int			fd2;

	if (argc != 2)
		return (-1);
	fd1 = open(argv[1], O_RDONLY);	
	fd2 = open(argv[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (-1);
	read_map(fd1, fd2, &map);
	print_map(&map);
	printf("is valid = %d\n", 	check_map(&map));
	mlx.height = 480;
	mlx.width = 680;
	mlx.texture_size = 16;
	mlx.text_file[3] = "textures/stone.xpm";
	mlx.text_file[2] = "textures/gold_block.xpm";
	mlx.text_file[1] = "textures/bee_nest_bottom.xpm";
	mlx.text_file[0] = "textures/red_wool.xpm";
	if (!(mlx.id = mlx_init()) || !init_screen(&mlx) || !init_textures(&mlx))
		return (-1);
	if (!(mlx.window = mlx_new_window(mlx.id, mlx.width, mlx.height, "cub3D")))
		return (-1);
	mlx.map = &map;
	p.angle = 0;
	p.pos_x = 1.5;
	p.pos_y = 1.5;
	mlx.player = &p;
	mlx_hook(mlx.window, KeyPress, KeyPressMask, key_press, &mlx);
    mlx_hook(mlx.window, KeyRelease, KeyReleaseMask, key_release, &mlx);
	mlx_loop_hook(mlx.id, loop_hook, &mlx);
	mlx_loop(mlx.id);
	return (0);
}