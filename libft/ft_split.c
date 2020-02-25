/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:44:16 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/24 00:16:13 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cw(char const *s, char c)
{
	int i;
	int n;
	int in_word;

	i = 0;
	n = 0;
	in_word = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			if (!in_word++)
				n += 1;
		}
		else
			in_word = 0;
		i += 1;
	}
	return (n);
}

static int	ft_slen_c(const char *s, char c)
{
	int i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i += 1;
	return (i);
}

static char	**ft_emergency(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		in_word;
	char	**strs;

	i = 0;
	in_word = 0;
	if (!s)
		return (NULL);
	if (!(strs = (char **)ft_calloc(sizeof(char *) * (ft_cw(s, c) + 1), 1)))
		return (NULL);
	while (*s)
		if (*s++ != c)
		{
			if (!in_word++)
			{
				if (!(strs[i] = (char *)ft_calloc(ft_slen_c(s - 1, c) + 1, 1)))
					return (ft_emergency(strs));
				ft_memcpy(strs[i], s - 1, ft_slen_c(s - 1, c));
				i += 1;
			}
		}
		else
			in_word = 0;
	return (strs);
}
