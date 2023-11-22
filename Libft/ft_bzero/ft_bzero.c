/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisalles <relisalles@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:55:06 by relisalles        #+#    #+#             */
/*   Updated: 2023/11/20 19:01:32 by relisalles       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>


void bzero(void *s, size_t n)
{
	int i;
	i = 0;
	while (n > 0)
	{
		s[i] = '\0';
		n--;
	}
}

int main(void)
{
    char str[20]; // Reserva espaço para uma string
    strcpy(str, "Hello, World!");

    printf("Antes do bzero: %s\n", str);

    bzero(str + 7, 5); // Zera os próximos 5 caracteres da string a partir da posição 7

    printf("Depois do bzero: %s\n", str);

    return 0;
}



