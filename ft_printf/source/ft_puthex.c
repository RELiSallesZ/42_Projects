/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:24:06 by rsalles-          #+#    #+#             */
/*   Updated: 2024/01/17 14:16:44 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_uphexa(unsigned int nbr)
{
	if (nbr >= 16)
		ft_uphexa(nbr / 16);
	write(1, &("0123456789ABCDEF"[nbr % 16]), 1);
}

static void	ft_lowhexa(unsigned int nbr)
{
	if (nbr >= 16)
		ft_lowhexa(nbr / 16);
	write(1, &("0123456789abcdef"[nbr % 16]), 1);
}

int	ft_puthex(unsigned int nb, char c)
{
	int	i;

	i = 0;
	if (c == 'x')
		ft_lowhexa(nb);
	else if (c == 'X')
		ft_uphexa(nb);
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		i++;
		nb /= 16;
	}
	return (i);
}
