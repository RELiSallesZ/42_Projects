/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:21:06 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/01 15:22:17 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;	

	i = 0;
	str = malloc ((ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	toup(unsigned int d, char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 32;
    }
    return c;
}
int main (void)
{
	char str[] = "ae";
	printf("ates = %s\n", str);
	char *result = ft_strmapi(str, toup);
	printf("depois = %s\n", result);
	return (0);
}*/
