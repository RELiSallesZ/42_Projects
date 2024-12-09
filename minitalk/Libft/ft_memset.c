/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:14:55 by relisalles        #+#    #+#             */
/*   Updated: 2023/11/22 16:28:31 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t len)
{
	char	*p;

	p = (char *)str;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (str);
}
/*
int	main(void)
{
	char s1 [] = "123456789";
	int n = 97;
	int len = 1;
	printf("prima di memset:%s\n", s1);
	ft_memset(s1, n, len);

	printf("Dopo memset: %s", s1);
	
	return (0);
}
*/