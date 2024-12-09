/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:35:52 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/01 13:56:09 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot;
	size_t	i;
	char	*mem;

	i = 0;
	tot = count * size;
	mem = malloc(tot);
	if (mem == NULL)
		return (NULL);
	while (i < tot)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
/*
int main() {
    size_t num_elements = 9;
    size_t element_size = sizeof(char);

    char *int_array = (char *)ft_calloc(num_elements, element_size);

    if (int_array == NULL) {
        printf("Errore nell'allocazione di memoria.\n");
        return 1;
    }

	int_array [0] = '2';
	int_array [1] = '3';
	int_array [2] = 1;
	int_array [3] = 5;
	int_array [4] = 5;
	
	int_array = "ciao";

 	printf("Valori nell'array:\n");

        printf("%s", int_array);

    free(int_array);

    return 0;
}*/