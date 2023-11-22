/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisalles <relisalles@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:14:55 by relisalles        #+#    #+#             */
/*   Updated: 2023/11/20 17:43:41 by relisalles       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

int main(void)
{
    char str[14]; // Reserva espaço para a string original "Hello, World!" e o caractere nulo
    strcpy(str, "Hello, World!");

    printf("Antes do  memset: %s\n", str);

    // Preenche os próximos 5 caracteres da string com 'A'
    memset(str + 7, 'A', 5);

    printf("Depois do memset: %s\n", str);

    return 0;
}
