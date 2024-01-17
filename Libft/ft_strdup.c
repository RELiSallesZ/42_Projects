/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:07:14 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/04 12:36:21 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = ft_strlen(src);
	dest = (char *) malloc (sizeof(*dest) * (j + 1));
	if (dest == NULL)
		return (NULL);
	while (i < j)
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char src [] = "afff";
	char *dest;
	dest = ft_strdup(src);
	printf("str = %s\n", dest);
	return (0);
}*/
