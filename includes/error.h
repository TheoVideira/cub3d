/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:33:45 by tvideira          #+#    #+#             */
/*   Updated: 2020/01/17 12:24:31 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_error(char *error);
void	ft_error_no(int err);

#endif