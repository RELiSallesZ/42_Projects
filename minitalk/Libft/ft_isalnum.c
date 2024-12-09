/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:08:35 by relisalles        #+#    #+#             */
/*   Updated: 2023/12/04 12:54:13 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int s1)
{
	if (ft_isalpha(s1) || ft_isdigit(s1))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	nbr;
	char	c;

	c = '?';
	nbr = ft_isalnum(s);
	printf("%d\n", nbr);
	return (0);
}*/
