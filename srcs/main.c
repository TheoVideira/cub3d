/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 05:08:51 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/06 03:49:07 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "cub3d.h"

int		loop_hook(t_cub *cub)
{
	//static int i = 0;
	/*if (i == 1)
	{
		save_first_frame(mlx, "sphere2.bmp");
		exit(0);
	}*/
	create_background(cub);
	render_wall(cub);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.window, cub->mlx.img, 0, 0);
	return (0);
}

int		init_screen(t_cub *cub)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	cub->mlx.img = mlx_new_image(cub->mlx.ptr,
				cub->gi.resolution[0], cub->gi.resolution[1]);
	cub->mlx.screen = (int *)mlx_get_data_addr(cub->mlx.img,
				&bits_per_pixel, &size_line, &endian);
	if (endian != 0 || bits_per_pixel != 32)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cub			cub;

	if (argc != 2)
		return (-1);
	init_cub(&cub);
	parse_cub_file(argv[1], &(cub.pi), &(cub.gi));
	if (!(cub.mlx.ptr = mlx_init()) || !init_screen(&cub)
									|| !init_textures(&cub, -1))
		return (-1);
	if (!(cub.mlx.window = mlx_new_window(cub.mlx.ptr,
		cub.gi.resolution[0], cub.gi.resolution[1], "cub3D")))
		return (-1);
	mlx_hook(cub.mlx.window, KEYPRESS, 0, key_press, &cub);
	mlx_hook(cub.mlx.window, KEYRELEASE, 0, key_release, &cub);
	mlx_hook(cub.mlx.window, DESTROYNOTIFY, 0, quit_window, &cub);
	mlx_loop_hook(cub.mlx.ptr, loop_hook, &cub);
	mlx_loop(cub.mlx.ptr);
	return (0);
}
