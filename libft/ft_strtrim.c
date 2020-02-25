/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:34:09 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/20 18:01:12 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_border(char const c, char const *s)
{
	while (*s)
		if (c == *s++)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_calc_border(*(s1 + start), set))
		start += 1;
	if (!*(s1 + start))
		return (ft_calloc(1, 1));
	end = ft_strlen(s1) - 1;
	while (ft_calc_border(*(s1 + end), set))
		end -= 1;
	return (ft_substr(s1, start, end - start + 1));
}
