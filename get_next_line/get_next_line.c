/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:54:36 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/11 18:41:24 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_main_buffer(int fd, char *main_buffer, char *buffer)
{
	ssize_t	buffer_read;
	char	*tmp;

	buffer_read = 1;
	while (buffer_read > 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(main_buffer);
			return (NULL);
		}
		if (buffer_read == 0)
			break ;
		buffer[buffer_read] = 0;
		if (!main_buffer)
			main_buffer = ft_strdup("");
		tmp = main_buffer;
		main_buffer = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (main_buffer);
}

static char	*make_line(char *line_buffer)
{
	char	*main_buffers;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != 0)
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	main_buffers = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - 1);
	if (*main_buffers == 0)
	{
		free(main_buffers);
		main_buffers = NULL;
	}
	line_buffer[i + 1] = 0;
	return (main_buffers);
}

char	*get_next_line(int fd)
{
	static char	*main_buffers;
	char		*line;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(main_buffers);
		buffer = NULL;
		main_buffers = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = update_main_buffer(fd, main_buffers, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	main_buffers = make_line(line);
	return (line);
}

// int	main(void)
// {
//  	int	fd;
//  	int	lines;
//  	char 	*line;

//  	lines = 1;
//  	fd = open("./example.txt", O_RDONLY);
//  	line = get_next_line(fd);
//  	while (line)
//  	{
//  		printf("%2d: %s", lines++, line);
//  		free(line);
//  		line = get_next_line(fd);
//  	}
//  	close(fd);
//  	return (0);
//  }
