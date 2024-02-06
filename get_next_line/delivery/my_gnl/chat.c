#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char    *get_chunck(int fd)
{
    char    *chunk;
    int     bytes_read;

    chunk = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (chunk == NULL)
        return (NULL);
    bytes_read = read(fd, chunk, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        free(chunk);
        return (NULL);
    }
    chunk[bytes_read] = '\0'; // Coloca o terminador de string no final do chunk lido
    return (chunk);
}

static char *make_buffer(char *buffer, char *chunk)
{
    int chunk_len;

    if (buffer == NULL) {
        buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // Aloca memória para o buffer inicialmente
        if (buffer == NULL) {
            free(chunk); // Libera a memória do chunk se a alocação do buffer falhar
            return (NULL);
        }
        buffer[0] = '\0'; // Inicializa o buffer como uma string vazia
    }

    chunk_len = 0;
    if (chunk != NULL)
        chunk_len = strlen(chunk);
    
    // Realoca memória para o buffer para acomodar o chunk e os dados anteriores
    buffer = (char *)realloc(buffer, (strlen(buffer) + chunk_len + 1) * sizeof(char));
    if (buffer == NULL) {
        free(chunk); // Libera a memória do chunk se a realocação do buffer falhar
        return (NULL);
    }
    
    if (chunk != NULL)
        strcat(buffer, chunk); // Concatena o chunk no final do buffer
    
    return (buffer);
}

char    *get_next_line(int fd)
{
    static char *buffer = NULL; // Declara o buffer como estático para ser persistente entre chamadas
    char *chunk = get_chunck(fd); // Lê um novo chunk do arquivo
    
    if (chunk == NULL) { // Verifica se não há mais nada para ler
        free(buffer); // Libera o buffer se não houver mais dados para ler
        return (NULL);
    }

    buffer = make_buffer(buffer, chunk); // Atualiza o buffer com o novo chunk
    free(chunk); // Libera a memória do chunk, pois já foi processado

    return (buffer);
}

int main ()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        printf("Arquivo não encontrado");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL) { // Lê linhas até que não haja mais dados para ler
        printf("Linha lida: %s\n", line);
    }
    
    close(fd);
    return (0);
}
