/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 06:40:16 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/17 11:20:18 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "map.h"
#include <errno.h>
#include <stdio.h>

static int	is_valid_case(char c)
{
	return ((c >= '0' && c <= '2')
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	map_error(char *error, int len)
{
	write(2, error, len);
	exit(-1);
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
		else if (buffer == '\n')
		{
			if (!map->width)
				map->width = i;
			map->heigth++;
		}
		else if (buffer != ' ')
			map_error("Invalid char on map\n", 20);
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
		if (buffer == '\n')
		{
			x = i % map->width;
			if (x || i / map->width > map->heigth)
				map_error("Not a rectangular map\n", 22);			
		}
		if (is_valid_case(buffer))
		{
			x = i % map->width;
			y = i / map->width;
			map->map[(map->heigth - y - 1) * map->width + x] = buffer;
			i++;
		}
	}
	map->map[i] = '\0';
}

int			check_map(t_map *map)
{
	int x;
	int y;
	int c;
	int p;
	int pos_player;

	p = -1;
	pos_player = 0;
	while (++p < map->heigth * map->width)
	{
		x = p % map->width;
		y = p / map->width;
		c = x + y * map->width;
		if ((!y || y == map->heigth - 1) && map->map[c] != '1')
			map_error("Invalid map, not closed\n", 24);
		if ((!x || x == map->width - 1) && map->map[c] != '1')
			map_error("Invalid map, not closed\n", 24);
		if (map->map[c] == 'N' || map->map[c] == 'S' || map->map[c] == 'W' ||
			map->map[c] == 'E')
		{
			map->play_dir = map->map[c];
			pos_player++;
		}
	}
	if (pos_player != 1)
		map_error("player position invalid\n", 24);
	return (1);
}

void		print_map(t_map *map)
{
	int a;
	int b;

	b = -1;
	while (++b < map->heigth)
	{
		a = -1;
		while (++a < map->width)
			write(1, &(map->map[(map->heigth - b - 1) * map->width + a]), 1);
		write(1, "\n", 1);
	}
}
