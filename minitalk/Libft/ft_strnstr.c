/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:44 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/01 15:27:22 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (s2[0] == 0)
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && i + j < len)
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char s1 [] = "vai se lascar";
	char s2 [] = "se";
	int len = 100;

	printf("result = %s", ft_strnstr(s1, s2, len));
	return (0);
}*/
