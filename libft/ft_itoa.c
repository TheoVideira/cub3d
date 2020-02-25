/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:13:45 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/15 19:33:57 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_alloc(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i += 1;
	while (n /= 10)
		i += 1;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_size_alloc(n);
	j = 0;
	if ((str = (char *)ft_calloc(i + 2, 1)) == NULL)
		return (NULL);
	if (n < 0)
	{
		str[j++] = '-';
		i -= 1;
	}
	while (i > 0)
	{
		str[j++] = (n < 0) ? n / ft_power(10, i) * -1 + '0' :
		n / ft_power(10, i) + '0';
		n -= n / ft_power(10, i) * ft_power(10, i);
		i--;
	}
	str[j++] = (n < 0) ? n * -1 + '0' : n + '0';
	return (str);
}
