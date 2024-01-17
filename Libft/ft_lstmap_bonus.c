/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 05:22:18 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:15 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;
	void	*current;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		current = (*f)(lst->content);
		new = ft_lstnew(current);
		if (!new)
		{
			del(current);
			ft_lstclear(&first, del);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
