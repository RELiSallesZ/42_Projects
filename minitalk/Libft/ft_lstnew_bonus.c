/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:01:16 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/04 18:16:15 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int main() {

    int data = 5;
    t_list *newNode = ft_lstnew(&data);
    if (newNode != NULL) {
        printf("Contenuto del nuovo nodo: %d\n", *(int *)(newNode->content));
    } else {
        printf("Errore nella creazione del nuovo nodo.\n");
    }
    free(newNode);
    return 0;
}*/
