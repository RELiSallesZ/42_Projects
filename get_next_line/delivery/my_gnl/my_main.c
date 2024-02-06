/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:45:32 by relisallesz       #+#    #+#             */
/*   Updated: 2024/02/06 15:55:17 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct afifa
{
    char nome;
    int idade;
    
};


char	*get_chunck(int fd)
{
    char        *chunk;
    int          bytes_read;
    static int  calls;
    char        *buffer;

    calls = 1 + calls;
    chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if(chunk == NULL)
        return (NULL);
    bytes_read = read(fd, chunk, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(chunk);
            return (NULL);
        }
    chunk[BUFFER_SIZE + 1] = '\0';
    
    printf("calls = %i\n", calls);
    buffer = calloc((1 + (BUFFER_SIZE * calls)), sizeof(char));
    
    buffer = ft_strlcat(buffer, chunk, (1 + (BUFFER_SIZE * calls)));
    
    return (chunk);
}





char	*get_next_line(int fd)
{
    return(get_chunck(fd));
}

int main ()
{
    int     fd;

    fd = open("test.txt", O_RDONLY);
    if(fd < 0)
        printf("file not found");

    printf("1GNL retorna= %s\n\n\n", get_next_line(fd));
    printf("2GNL retorna= %s\n\n\n", get_next_line(fd));
    printf("2GNL retorna= %s\n\n\n", get_next_line(fd));
    printf("2GNL retorna= %s\n\n\n", get_next_line(fd));
    
    return(0);
}