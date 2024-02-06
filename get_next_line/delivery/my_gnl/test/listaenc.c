#include    <unistd.h>
#include    <stdio.h>

typedef struct no {
    int valor;
    struct no *proximo;
}No;

void inserir_no_inicio (No **lista, int num)
{
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo ->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
}

int main()
{
    printf("valor = %i", inserir_no_inicio())
}
