/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:03:51 by rsalles-          #+#    #+#             */
/*   Updated: 2024/02/05 12:39:21 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static char	*file_reader(int fd)
{
	int			bytes_read;
	char		*teco;
	static int	count = 1;

	printf("ft_calloc#[%d]---", count++);
	teco = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (teco == NULL)
		return (NULL);
	bytes_read = read(fd, teco, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		return (free(teco), NULL);
	}
	return (teco);
}

char	*get_next_line(int fd)
{
	char	*buffer_sum;

	buffer_sum = file_reader(fd);
	return (buffer_sum);
}