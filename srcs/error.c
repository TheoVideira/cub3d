/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:20:00 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/17 13:42:14 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static int	ft_strlen(char *s)
{
	int i;
	i = 0;
	while(s[i])
		i++;
	return (i);
}

void		ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(-1);
}

void		ft_error_no(int err)
{
	char *error;

	error = strerror(err);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(-1);
}
