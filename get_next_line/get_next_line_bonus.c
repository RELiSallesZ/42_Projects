/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:54:36 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/11 18:41:36 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*make_main_buffer(int fd, char *left_c, char *buffer)
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

static char	*make_line(char *line_buffer)
{
	char	*main_buffer;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (0);
	main_buffer = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - 1);
	if (*main_buffer == 0)
	{
		free(main_buffer);
		main_buffer = NULL;
	}
	line_buffer[i + 1] = 0;
	return (main_buffer);
}

char	*get_next_line(int fd)
{
	static char	*main_buffer[MAX_FD];
	char		*next_line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(main_buffer[fd]);
		main_buffer[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	next_line = make_main_buffer(fd, main_buffer[fd], buffer);
	free(buffer);
	if (!next_line)
		return (NULL);
	main_buffer[fd] = make_line(next_line);
	return (next_line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		lines;
// 	char	*line;

// 	lines = 1;
// 	fd = open("./example.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%2d: %s", lines++, line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
