/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:48:11 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/04 18:13:37 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nextt;

	current = *lst;
	nextt = *lst;
	if (!lst || !*lst || !del)
		return ;
	while (current)
	{
		nextt = nextt->next;
		del(current->content);
		free (current);
		current = nextt;
	}
	*lst = NULL;
}
