/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:32:09 by rsalles-          #+#    #+#             */
/*   Updated: 2023/12/01 14:33:26 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	if (!str)
		return ;
	ft_putstr_fd((char *) str, fd);
	ft_putchar_fd('\n', fd);
}
/*
int main() 
{
    char *str = "vaiselascar";
    int fd = 1; 
    ft_putendl_fd(str, fd);

    return 0;
}*/