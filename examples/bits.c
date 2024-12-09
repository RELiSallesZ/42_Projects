#include <unistd.h>

void print_binary(char c) {
    int i = 7;  // Começamos pela posição do bit mais significativo (índice 7)
    while (i >= 0) {
        // Verifica se o bit na posição i é 1 ou 0
        if (c & (1 << i)) {
            write(1, "1", 1); // Escreve '1' na saída padrão
        } else {
            write(1, "0", 1); // Escreve '0' na saída padrão
        }
        i--; // Decrementa para verificar o próximo bit
    }
    write(1, "\n", 1); // Nova linha após o binário
}

int main() {
    char c;
    write(1, "Digite um caractere: ", 21);
    read(0, &c, 1); // Usa read() para capturar um caractere
    write(1, "Binário de '", 12);
    write(1, &c, 1); // Imprime o caractere
    write(1, "': ", 3);
    print_binary(c);
    return 0;
}
