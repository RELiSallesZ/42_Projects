/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:44 by rsalles-          #+#    #+#             */
/*   Updated: 2024/01/17 14:20:16 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(char k, va_list args)
{
	if (k == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (k == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (k == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (k == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (k == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (k == 'u')
		return (ft_putunsignednbr(va_arg(args, unsigned int)));
	else if (k == 'x')
		return (ft_puthex(va_arg(args, unsigned int), k));
	else if (k == 'X')
		return (ft_puthex(va_arg(args, unsigned int), k));
	else if (k == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	if (!str)
		return (0);
	i = 0;
	va_start(args, str);
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += convert(str[i], args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*int main() {
    char *str = "Vaise lascar!!!!";
    int num = 42;
    double dbl = 4.2;

    int ftprintf_chars = ft_printf("String: %s\n", str);
    int printf_chars = printf("String: %s\n", str);
    printf("[ft_printf]: %i characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
    ftprintf_chars = ft_printf("Integer: %d\n", num);
    printf_chars = printf("Integer: %d\n", num);
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
    ftprintf_chars = ft_printf("Character: %c\n", 'A');
    printf_chars = printf("Character: %c\n", 'A');
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
    ftprintf_chars = ft_printf("Pointer: %p\n", (void *)&num);
    printf_chars = printf("Pointer: %p\n", (void *)&num);
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
    ftprintf_chars = ft_printf("Unsigned: %u\n", (unsigned int)num);
    printf_chars = printf("Unsigned: %u\n", (unsigned int)num);
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
    ftprintf_chars = ft_printf("Hexadecimal: %x\n", num);
    printf_chars = printf("Hexadecimal: %x\n", num);
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
    ftprintf_chars = ft_printf("Uppercase Hexadecimal: %X\n", num);
    printf_chars = printf("Uppercase Hexadecimal: %X\n", num);
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
    ftprintf_chars = ft_printf("Percent sign: %%\n");
    printf_chars = printf("Percent sign: %%\n");
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
	ftprintf_chars = 0;
	printf_chars = 0;
	ftprintf_chars = ft_printf("Integer: %i\n", num);
    printf_chars = printf("Integer: %i\n", num);
    printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
    printf("[printf]: %d characters printed\n", printf_chars);
	ftprintf_chars = ft_printf("123456");
	printf_chars = printf("123456");
	printf("[ft_printf]: %d characters printed\n", ftprintf_chars);
	printf("[printf]: %d characters printed\n", printf_chars);
    return 0;
}*/
