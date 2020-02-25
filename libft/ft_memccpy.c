/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 07:46:29 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/11 19:22:01 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (i < n)
	{
		*(p_dst + i) = *(p_src + i);
		if (*(p_src + i) == (unsigned char)c)
			return (p_dst + i + 1);
		i += 1;
	}
	if (*(p_src + i) == (unsigned char)c)
		return (p_src + i + 1);
	return (NULL);
}
