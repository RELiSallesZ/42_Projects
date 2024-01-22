/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:36:24 by rsalles-          #+#    #+#             */
/*   Updated: 2024/01/22 13:51:54 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot;
	size_t	i;
	char	*mem;

	i = 0;
	tot = count * size;
	mem = malloc(tot);
	if (mem == NULL)
		return (NULL);
	while (i < tot)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
