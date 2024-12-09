/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:55:06 by relisalles        #+#    #+#             */
/*   Updated: 2023/12/04 11:04:25 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s1, size_t len)
{
	ft_memset(s1, 0, len);
}
/*
int main(void)
{
    char str[20]; // Reserva espaço para uma string
    strcpy(str, "Vai se lascar");

    printf("Antes do bzero: %s\n", str);

    bzero(str + 7, 5); // Zera os próximos 5 
	caracteres da string a partir da posição 7

    printf("Depois do bzero: %s\n", str);

    return 0;
}
*/
