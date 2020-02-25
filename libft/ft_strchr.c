/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:22:20 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/10 18:54:59 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while ((*(s + i)))
	{
		if (*(s + i) == (char)c)
			return (char *)(s + i);
		i += 1;
	}
	if (c == '\0')
		return (char *)(s + i);
	return (NULL);
}
