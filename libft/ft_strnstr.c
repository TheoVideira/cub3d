/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:51:10 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/15 21:34:51 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t d_len;

	if (!(d_len = ft_strlen(needle)))
		return (char *)haystack;
	i = 0;
	while (*(haystack + i) && len - i >= d_len && i < len)
	{
		if (!ft_memcmp(haystack + i, needle, d_len))
			return ((char *)haystack + i);
		i += 1;
	}
	return (NULL);
}
