/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:20:00 by tvideira          #+#    #+#             */
/*   Updated: 2020/03/05 23:58:07 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void		ft_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(-1);
}

void	ft_error_free(char *error, t_game_info *gi)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	free(gi->texture.path[0]);
	free(gi->texture.path[1]);
	free(gi->texture.path[2]);
	free(gi->texture.path[3]);
	free(gi->texture.path[4]);
	exit(-1);
}


void	ft_error_line(char *error, int n)
{
	write(2, "Error\n", 6);
	write(2, "Line ", 5);
	ft_putnbr_fd(n, 2);
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	exit(-1);
}

void	ft_error_no(int err)
{
	char *error;

	error = strerror(err);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(-1);
}

void	ft_error_no_free(int err, t_game_info *gi)
{
	char *error;

	error = strerror(err);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	free(gi->texture.path[0]);
	free(gi->texture.path[1]);
	free(gi->texture.path[2]);
	free(gi->texture.path[3]);
	free(gi->texture.path[4]);
	exit(-1);
}
