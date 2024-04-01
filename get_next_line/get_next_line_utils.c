/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:21:22 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/01 15:57:22 by relisallesz      ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if (len != 0 && len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = (char *)malloc (sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
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

char	*ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
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
	{
		free(mem);
		return (NULL);
	}
	while (i < tot)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
