/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:10 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/01 14:17:23 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, void *s2, size_t len)
{
	char	*sa;
	char	*sb;
	size_t	i;

	sa = (char *)s1;
	sb = (char *)s2;
	i = 0;
	while (i < len)
	{
		if (sa[i] != sb[i])
			return ((unsigned char)sa[i] - (unsigned char)sb[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char str1 [] = {0x03, 0x07, 0x09};
	char str2 [] = {0x03, 0x01, 0x09};
	int csnf = ft_memcmp(str1, str2, 500);
	printf("%d", csnf);
	return (0);
}*/
