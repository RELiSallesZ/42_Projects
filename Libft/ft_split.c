/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:16:12 by relisalles        #+#    #+#             */
/*   Updated: 2023/12/04 12:36:31 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (i);
}

static char	*ft_wordall(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *) malloc((finish - start + 1) * sizeof (char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((ft_memcount(str, c) + 1) * sizeof(char *));
	if (!str ||!split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= (size_t)ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == (size_t)ft_strlen(str)) && index >= 0)
		{
			split[j++] = ft_wordall(str, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
int	main(void)
{
	char s [] = "vai lascar";
	char **split = ft_split(s, ' ');

	for (int i = 0; split[i] != NULL; i++)
  	  printf("%s\n", split[i]);
}
*/