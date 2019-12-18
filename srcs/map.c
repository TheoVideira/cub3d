/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 06:40:16 by tvideira          #+#    #+#             */
/*   Updated: 2019/12/18 11:28:08 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "map.h"

static int	is_valid_case(char c)
{
	return ((c >= '0' && c <= '2')
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	size_map(int fd, t_map *map)
{
	char	buffer;
	int		i;

	i = 0;
	while (read(fd, &buffer, 1))
	{
		if (is_valid_case(buffer))
			i++;
		if (buffer == '\n')
		{
			if (!map->width)
				map->width = i;
			map->heigth++;
		}
	}
}

void		read_map(int fd1, int fd2, t_map *map)
{
	char	buffer;
	int		i;
	int		x;
	int		y;

	map->heigth = 1;
	map->width = 0;
	size_map(fd1, map);
	if (!(map->map = malloc(sizeof(char) * (map->width * map->heigth + 1))))
		return ;
	i = 0;
	while (read(fd2, &buffer, 1))
	{
		if (is_valid_case(buffer))
		{
			x = i % map->width;
			y = i / map->width;
			map->map[(map->width - 1 - y) * map->width + x] = buffer;
			i++;
		}
	}
	map->map[i] = '\0';
}

void 		print_map(t_map *map)
{
	for (int b = 0; b < map->heigth; b++){
		for (int a = 0; a < map->width; a++){
			write(1 , &(map->map[(map->width - b - 1) * map->width + a]), 1);
		 }
		write(1, "\n", 1);
	}
}