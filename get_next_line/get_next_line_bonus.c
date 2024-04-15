/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:54:36 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/15 17:20:25 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*make_main_buffer(int fd, char *main_buffer, char *read_buffer)
{
	ssize_t	byte_read;
	char	*temp_main_buffer;

	byte_read = 1;
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
			main_buffer = ft_strdup("");
		temp_main_buffer = main_buffer;
		main_buffer = ft_strjoin(temp_main_buffer, read_buffer);
		free(temp_main_buffer);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	return (main_buffer);
}

static char	*update_main_buffer(char *next_line)
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

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(read_buffer);
		free(main_buffer[fd]);
		main_buffer[fd] = NULL;
		read_buffer = NULL;
		return (NULL);
	}
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
