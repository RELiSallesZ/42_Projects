#include <unistd.h>
#include <stdio.h>	
#include <string.h>

void putrow(char *row)
{
    while(row > 0)
    {
        write(1, "|", 1);
        *row--;
    }
}

int main(int argc, char **argv) 
{             
    char *row = NULL;
    char *column = NULL;

    row = 0;
    column = 0;

    row = &argv[1][0];
    column = &argv[1][1];
    while(column > 0)
    {
        write(1, "*", 1);
        putrow(row);
        column--;
    }
}