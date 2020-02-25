/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:39:19 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/15 20:18:20 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
