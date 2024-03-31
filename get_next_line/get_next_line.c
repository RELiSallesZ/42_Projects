/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:09:05 by relisallesz       #+#    #+#             */
/*   Updated: 2024/03/31 15:20:18 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line_andfree(char *main_buffer, char *temp_buffer)
{
	char	*temp_line;

	temp_line = ft_strjoin(main_buffer, temp_buffer) ;
	free(main_buffer);
	return (temp_line);
}

char	*ft_next(char *main_buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (main_buffer[i] && main_buffer[i] != '\n')
		i++;
	if (!main_buffer[i])
	{
		free(main_buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(main_buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (main_buffer[i])
		line[j++] = main_buffer[i++];
	free(main_buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *main_buffer)
{
	char	*temp_buffer;
	int		byte_read;

	if (!main_buffer)
		main_buffer = ft_calloc(1, 1);
	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[byte_read] = 0;
		main_buffer = make_line_andfree(main_buffer, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (main_buffer);
}

char	*get_next_line(int fd)
{
	static char	*main_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(line);
		free(main_buffer);
		line = NULL;
		main_buffer = NULL;
		return (NULL);
	}
	main_buffer = read_file(fd, main_buffer);
	if (!main_buffer)
		return (NULL);
	line = ft_line(main_buffer);
	main_buffer = ft_next(main_buffer);
	return (line);
}