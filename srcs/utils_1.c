/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:59:46 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/21 14:44:04 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int     ft_isspace(int c)
{
        return (c == 32 || !(c < '\t' || c > '\r'));
}

int     ft_isdigit(int c)
{
        return (!(c < '0' || c > '9'));
}

int     ft_atoi(const char *str)
{
        int i;
        int res;
        int sign;

        i = 0;
        res = 0;
        while (ft_isspace(*(str + i)))
                i += 1;
        sign = (*(str + i) == '-') ? -1 : 1;
        if (*(str + i) == '-' || *(str + i) == '+')
                i += 1;
        while (ft_isdigit(*(str + i)))
        {
                res = (res * 10) + ((*(str + i) - '0') * sign);
                i += 1;
        }
        return (res);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	if ((dup = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	ft_strlcpy(dup, s1, len + 1);
	return (dup);
}

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