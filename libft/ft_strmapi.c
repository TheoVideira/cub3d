/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:30:27 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/16 14:42:43 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;

	if (!s || !f || !(new_str = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (*(new_str + i))
	{
		*(new_str + i) = f(i, *(new_str + i));
		i += 1;
	}
	return (new_str);
}
