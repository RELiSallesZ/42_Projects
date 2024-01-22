/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:09:52 by rsalles-          #+#    #+#             */
/*   Updated: 2024/01/17 14:02:30 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int nb)
{
	int				i;

	i = 0;
	if (nb == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_putunsignednbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

static void	ft_post(unsigned long long ptr)
{
	static char	digits[] = "0123456789abcdef";

	if (ptr >= 16)
		ft_post(ptr / 16);
	write(1, &digits[ptr % 16], 1);
}

int	ft_putptr(void *ptr)
{
	int					i;
	unsigned long long	n;

	n = (unsigned long long)ptr;
	i = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_post(n);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i + 2);
}
