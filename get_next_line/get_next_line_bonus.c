/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:54:36 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/17 09:02:54 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*main_buffer_inicialize(const char *str)
{
	char	*first;

	first = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!first)
	{
		free(first);
		return (NULL);
	}
	return (first);
}

char	*make_main_buffer(int fd, char *main_buffer, char *read_buffer)
{
	ssize_t	byte_read;
	char	*temp_main_buffer;

	byte_read = 42;
	while (byte_read > 0)
	{
		byte_read = read(fd, read_buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(main_buffer);
			return (NULL);
		}
		else if (byte_read == 0)
			break ;
		read_buffer[byte_read] = 0;
		if (!main_buffer)
			main_buffer = main_buffer_inicialize("");
		temp_main_buffer = main_buffer;
		main_buffer = ft_strjoin(temp_main_buffer, read_buffer);
		free(temp_main_buffer);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	return (main_buffer);
}

char	*update_main_buffer(char *next_line)
{
	char	*upd_main_buffer;
	ssize_t	i;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != '\0')
		i++;
	if (next_line[i] == 0)
		return (0);
	upd_main_buffer = ft_substr(next_line, i + 1, ft_strlen(next_line) - 1);
	if (*upd_main_buffer == 0)
	{
		free(upd_main_buffer);
		upd_main_buffer = NULL;
	}
	next_line[i + 1] = 0;
	return (upd_main_buffer);
}

char	*get_next_line(int fd)
{
	static char	*main_buffer[MAX_FD];
	char		*next_line;
	char		*read_buffer;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0
		|| read(fd, 0, BUFFER_SIZE - BUFFER_SIZE < 0))
	{
		free(main_buffer[fd]);
		main_buffer[fd] = NULL;
		return (NULL);
	}
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
		return (NULL);
	next_line = make_main_buffer(fd, main_buffer[fd], read_buffer);
	free(read_buffer);
	if (!next_line)
		return (NULL);
	main_buffer[fd] = update_main_buffer(next_line);
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
