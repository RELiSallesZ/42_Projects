/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:44:09 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/04 17:41:27 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main(void)
{
	char s [] = "hola";

	char *sub = ft_substr(s, 1, 125554454545465456);
	printf("prima stringa:%s, \nseconda stringa:%s", s, sub);
	return (0);
}*/
