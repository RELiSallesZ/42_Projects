/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:09:22 by relisallesz       #+#    #+#             */
/*   Updated: 2024/03/21 20:20:37 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *string1, char const *string2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(string1) + ft_strlen(string2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !string1 || !string2)
		return (NULL);
	while (string1[i] != 0)
	{
		res[i] = string1[i];
		i++;
	}
	j = 0;
	while (string2[j] != 0)
	{
		res[i] = string2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

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

