/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:57:52 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/15 17:01:16 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int n, int p)
{
	int res;

	res = 1;
	if (p < 0)
		return (0);
	if (!p || n == 1)
		return (1);
	if (n == -1)
		return ((p % 2) ? -1 : 1);
	while (p)
	{
		res *= n;
		p -= 1;
	}
	return (res);
}