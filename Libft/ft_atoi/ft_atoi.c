/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisalles <relisalles@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:16:12 by relisalles        #+#    #+#             */
/*   Updated: 2023/11/20 18:16:23 by relisalles       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<unistd.h>

int ft_isspace(char c)
{
	if(c <= 32)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(str[i]) == 1)
	{
		printf("huhuhu\n");
		i++;
	}
	if(str[i]=='-' || str[i] == '+')
	{
		if(str[i]== '-')
		{
			sign = -sign;
		}
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}


// int main(int argc, char **argv)
// {
// 	if(argc == 2)
// 	{
//     	printf("ft_atoi(\"%s\") = %d\n", argv[1], ft_atoi(argv[1]));
// 	}
// 	return(0);
// }
