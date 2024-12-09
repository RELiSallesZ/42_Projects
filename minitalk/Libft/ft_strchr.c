/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:02:35 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/04 17:41:22 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int n)
{
	if (n > 127)
	{
		n %= 256;
	}
	while (*s1)
	{
		if (*s1 == (char)n)
			return ((char *)&*s1);
		s1++;
	}
	if ((char)n == *s1)
		return ((char *)&*s1);
	return (0);
}
/*
int	main (void)
{
	char s1 [] = "lasc";
	int n = 124;
	printf("pointer = %s", ft_strchr(s1, n));
	return (0);
}*/
