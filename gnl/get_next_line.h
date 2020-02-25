/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 03:32:22 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/30 15:50:39 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32
# include <stdlib.h>
# include <unistd.h>

void	gnl_bzero(void *p, size_t n);
int		find_next_line(const char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
int		create_line(int fd, char **line, char **buffer);
int		finish_line(char *buffer, char **line, char **remaining, int r);
int		get_next_line(int fd, char **line);
#endif
