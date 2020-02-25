/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:35:06 by tvideira          #+#    #+#             */
/*   Updated: 2019/10/19 23:03:36 by tvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *start;
	t_list *current;

	if (!lst || !f || !del)
		return (NULL);
	start = NULL;
	while (lst)
	{
		if (!(current = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, current);
		lst = lst->next;
	}
	return (start);
}
