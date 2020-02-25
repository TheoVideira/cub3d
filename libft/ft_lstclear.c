/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:54:19 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/19 22:23:41 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *suivant;
	t_list *elem_to_free;

	if (!lst || !del)
		return ;
	elem_to_free = *lst;
	while (elem_to_free)
	{
		suivant = elem_to_free->next;
		ft_lstdelone(elem_to_free, del);
		elem_to_free = suivant;
	}
	*lst = NULL;
}
