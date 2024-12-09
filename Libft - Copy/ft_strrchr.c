/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:28:26 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/01 15:28:53 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s1, int n)
{
	int	i;

	i = ft_strlen(s1);
	if (n > 127)
		n %= 256;
	if (n == '\0')
		return (s1 + i);
	while (i >= 0)
	{
		if (s1[i] == n)
			return (s1 + i);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s1[] = "Ae galera";
	int n = 111;
	printf("STR = %s", ft_strrchr(s1, n));
	return (0);
}*/
