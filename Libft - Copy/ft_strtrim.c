/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:47:44 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/04 12:36:21 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charrepeat(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_charrepeat(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charrepeat(s1[end - 1], set))
		end--;
	str = (char *) malloc (sizeof (*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
/*
int main(void)
{
	const char s1 [] ="caggaccaa";
	const char set [] = "ca";
	char *dest = ft_strtrim(s1, set);
	printf("%s", dest);
	return (0);
		
}*/