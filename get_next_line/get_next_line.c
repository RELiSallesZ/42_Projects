/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:54:36 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/15 17:20:20 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (byte_read == 0)
			break ;
		read_buffer[byte_read] = 0;
		if (!main_buffer)
			main_buffer = ft_strdup("");
		temp_main_buffer = main_buffer;
		main_buffer = ft_strjoin(temp_main_buffer, read_buffer);
		free(temp_main_buffer);
		temp_main_buffer = NULL;
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	return (main_buffer);
}

static char	*update_main_buffer(char *next_line)
{
	char	*updated_main_buffer;
	ssize_t	i;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != 0)
		i++;
	if (next_line[i] == 0 || next_line[1] == 0)
		return (NULL);
	updated_main_buffer = ft_substr(next_line, i + 1, ft_strlen(next_line) - 1);
	if (*updated_main_buffer == 0)
	{
		free(updated_main_buffer);
		updated_main_buffer = NULL;
	}
	next_line[i + 1] = 0;
	return (updated_main_buffer);
}

char	*get_next_line(int fd)
{
	static char	*main_buffer;
	char		*line;
	char		*read_buffer;

	read_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(read_buffer);
		free(main_buffer);
		read_buffer = NULL;
		main_buffer = NULL;
		return (NULL);
	}
	if (!read_buffer)
		return (NULL);
	line = make_main_buffer(fd, main_buffer, read_buffer);
	free(read_buffer);
	read_buffer = NULL;
	if (!line)
		return (NULL);
	main_buffer = update_main_buffer(line);
	return (line);
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
