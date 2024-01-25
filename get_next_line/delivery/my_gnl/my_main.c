/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relisallesz <relisallesz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:45:32 by relisallesz       #+#    #+#             */
/*   Updated: 2024/01/25 19:04:21 by relisallesz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//calloc p alocar memoria, lembra de fazer o free 

//read para abrir o arquivo r criar o teco

//variavel global para alterar o tamanho do teco

//strjoin para gravar os tecos no buffer

//get next line para identificar nova linha, imprimi-la e exclui-la do buffer

//main que atribui o fd a uma variavel e grama gnl em looping passando o fd

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char    *get_chunk(int fd)
{
    char       *chunk;
    int        readed;
    
    chunk = ft_calloc((BUFFER_SIZE + 1) , sizeof(char));
    if(chunk == NULL)
        return (NULL);
    read(fd, chunk, BUFFER_SIZE);
    if(read <= 0)
    {
        return(free(chunk),NULL);
    }
    return(chunk);
}

char	*get_next_line(int fd)
{
    char        *chunk;
    int         i;
    char        *buffer;
    char        *line;
    
    buffer = ft_strjoin(buffer, get_chunk(fd));
    i = 0;
    while (i < ft_strlen(buffer))
    {
        if (buffer[i] == '\n')
        {
            while (i >= 0)
            {
                line = buffer;
                line[i + 1] = '\0';
                line[i] = buffer [i];
                
            }
            
        }
        
        i++;        
    }
    
    printf("buffer = %s\n", buffer);
    i = 0;
}

int main ()
{
    int     fd;

    fd = open("test.txt", O_RDONLY);
    if(fd < 0)
        printf("file not found\n");

    get_next_line(fd);
            
    return(0);
}

