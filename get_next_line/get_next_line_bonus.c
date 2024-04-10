/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:54:36 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/10 13:52:44 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (byte_read == 0)
			break ;
		buffer[byte_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*set_line(char *line_buffer)
{
	char	*left_char;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (0);
	left_char = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - 1);
	if (*left_char == 0)
	{
		free(left_char);
		left_char = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_char);
}

char	*get_next_line(int fd)
{
	static char	*left_char[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(left_char[fd]);
		left_char[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_char[fd], buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_char[fd] = set_line(line);
	return (line);
}

int	main(void)
 {
 	int		fd;
 	int		lines;
 	char		*line;

 	lines = 1;
 	fd = open("./example.txt", O_RDONLY);
 	line = get_next_line(fd);
 	while (line)
 	{
 		printf("%2d: %s", lines++, line);
 		free(line);
 		line = get_next_line(fd);
 	}
 	close(fd);
 	return (0);
 }
