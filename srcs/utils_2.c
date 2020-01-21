/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:57 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/21 15:33:47 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	p_dst = (char *)dst;
	p_src = (char *)src;
	while (i < n)
	{
		*(p_dst + i) = *(p_src + i);
		i += 1;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int last_occurence;

	i = 0;
	last_occurence = -1;
	while ((*(s + i)))
	{
		if (*(s + i) == c)
			last_occurence = i;
		i += 1;
	}
	if (last_occurence > -1)
		return ((char *)(s + last_occurence));
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while (i + 1 < n && !ft_memcmp(s1 + i, s2 + i, 1) && *(s1 + i))
		i += 1;
	return (ft_memcmp(s1 + i, s2 + i, 1));
}