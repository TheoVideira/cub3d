/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 05:08:51 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/18 14:27:16 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "cub3d.h"

void	create_background(t_mlx *mlx)
{
	int				i;
	unsigned int	color;

	i = 0;
	color = 255;
	while (i < mlx->width * mlx->height / 2)
	{
		mlx->screen[i] = color;
		i++;
	}
	while (i < mlx->width * mlx->height)
	{
		mlx->screen[i] = color << 16;
		i++;
	}
}

int		loop_hook(t_mlx *mlx)
{
	static int i = 0;
	/*if (i == 1)
	{
		save_first_frame(mlx, "sphere2.bmp");
		exit(0);
	}*/
	printf("%d\n", i++);
	create_background(mlx);
	mlx_put_image_to_window(mlx->id, mlx->window, mlx->img, 0, 0);
	return (0);
}

int		init_screen(t_mlx *mlx)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	mlx->img = mlx_new_image(mlx->id, mlx->width, mlx->height);
	mlx->screen = (int *)mlx_get_data_addr(mlx->img, &bits_per_pixel, &size_line, &endian);
	if (endian != 0 || bits_per_pixel != 32)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	int		fd1;
	int		fd2;

	if (argc != 2)
		return (-1);
	fd1 = open(argv[1], O_RDONLY);	
	fd2 = open(argv[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (-1);
	read_map(fd1, fd2, &map);
	print_map(&map);
	mlx.height = 480;
	mlx.width = 640;
	if (!(mlx.id = mlx_init()) || !init_screen(&mlx))
		return (-1);
	if (!(mlx.window = mlx_new_window(mlx.id, mlx.width, mlx.height, "cub3D")))
		return (-1);
	mlx_loop_hook(mlx.id, loop_hook, &mlx);
	mlx_loop(mlx.id);
	return (0);
}