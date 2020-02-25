/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 06:45:53 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/17 09:54:10 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int		width;
	int		heigth;
	char	*map;
	char	play_dir;
}				t_map;

void			read_map(int fd1, int fd2, t_map *map);
void 			print_map(t_map *map);
int		 		check_map(t_map *map);

#endif