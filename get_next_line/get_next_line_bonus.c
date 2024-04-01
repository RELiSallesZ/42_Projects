/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:54:36 by relisallesz       #+#    #+#             */
/*   Updated: 2024/04/01 18:15:54 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

static char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*main_buffer_update(char *next_line)
{
	char	*updated_main_buffer;
	ssize_t	i;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != '\0')
		i++;
	if (next_line[i] == 0 || next_line[1] == 0)
		return (NULL);
	updated_main_buffer = ft_substr(next_line, i + 1, ft_strlen(next_line) - i);
	if (*updated_main_buffer == 0)
	{
		free(updated_main_buffer);
		updated_main_buffer = NULL;
	}
	next_line[i + 1] = 0;
	return (updated_main_buffer);
}

static char	*make_line(char *main_buffer, char *buffer, int fd)
{
	char	*temp_main_buffer;
	ssize_t	bytes_readed;

	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(main_buffer);
			return (NULL);
		}
		else if (bytes_readed == 0)
			break ;
		buffer[bytes_readed] = '\0';
		if (!main_buffer)
			main_buffer = ft_strdup("");
		temp_main_buffer = main_buffer;
		main_buffer = ft_strjoin(temp_main_buffer, buffer);
		free(temp_main_buffer);
		temp_main_buffer = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (main_buffer);
}

char	*get_next_line(int fd)
{
	static char	*main_buffer[MAX_FILES_OPEN];
	char		*next_line;
	char		*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(main_buffer[fd]);
		free(buffer);
		main_buffer[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	next_line = make_line(main_buffer[fd], buffer, fd);
	free(buffer);
	buffer = NULL;
	if (!next_line)
		return (NULL);
	main_buffer[fd] = main_buffer_update(next_line);
	return (next_line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("Erro ao abrir o arquivo!");
// 	printf ("line:%s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
