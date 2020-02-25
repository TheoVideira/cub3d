/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:26:15 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/13 16:40:21 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = ft_strlen(dst);
	if (i > dstsize || !dstsize)
		return (ft_strlen(src) + dstsize);
	return (i + ft_strlcpy(dst + i, src, dstsize - i));
}
