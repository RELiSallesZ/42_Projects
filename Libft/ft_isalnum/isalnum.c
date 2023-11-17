/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisalles <relisalles@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:08:35 by relisalles        #+#    #+#             */
/*   Updated: 2023/11/17 06:14:40 by relisalles       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isalpha(char c)
{
	if((c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

static int	ft_isdigit(char c)
{
	if(c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_isalpha(char c)
{
	if(ft_isalpha(c)==1 || ft_isdigit(c)==1)
	{
		return (1);
	}
	return (0);
}
