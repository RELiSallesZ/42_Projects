/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:11:29 by relisalles        #+#    #+#             */
/*   Updated: 2023/12/04 17:37:05 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	count_digits(long nbr)
{
	int	i;

	i = 1;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	size_t		len;
	char		*str;
	long		number;

	number = nbr;
	len = count_digits(number);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	else if (number < 0)
	{
		number = -number;
		str[0] = '-';
	}
	str[len] = '\0';
	while (number != 0)
	{
		str[--len] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	int		n;
// 	char	*str;

// 	// n = 0;
// 	// str = ft_itoa(n);
// 	// printf("0: %s\n", str);
// 	// free(str);
// 	n = -2147483643;
// 	str = ft_itoa(n);
// 	printf("%d: %s\n", n, str);
// 	free(str);
// 	return (0);
// }