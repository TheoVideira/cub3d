/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:54:49 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/15 22:19:13 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t len;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	len = (src_len < dstsize - 1) ? src_len : dstsize - 1;
	ft_memcpy(dst, src, len);
	*(dst + len) = '\0';
	return (src_len);
}
