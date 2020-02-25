/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 03:41:44 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/28 17:45:07 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_bzero(void *p, size_t n)
{
	size_t	i;
	char	*r;

	i = 0;
	r = (char *)p;
	while (i < n)
		r[i++] = '\0';
}

int		find_next_line(const char *s)
{
	size_t size;

	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	return (size);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (s[i + start] && i < len)
		i++;
	len = (len > i) ? i : len;
	if (!(sub = (char *)malloc(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*new_string;

	i = 0;
	j = 0;
	x = -1;
	if (s1)
		while (s1[i])
			i++;
	while (s2[j])
		j++;
	if ((new_string = (char *)malloc(i + j + 1)) == NULL)
		return (NULL);
	while (++x < i)
		new_string[x] = s1[x];
	x = -1;
	while (++x < j)
		new_string[i + x] = s2[x];
	new_string[i + j] = '\0';
	free(s1);
	return (new_string);
}
