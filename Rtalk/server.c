#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

// void myhandler(int sig)
// {
//     static char store_bits = 0;  // Mantém o valor entre chamadas
//     static int bit_count = 0;    // Mantém o valor entre chamadas
    
//     if (sig == SIGUSR1)
//         store_bits |= (1 << bit_count);
//     if (sig == SIGUSR2)
//         store_bits &= ~(1 << bit_count);
    
//     bit_count++;
    
//     if (bit_count == 8)
//     {
//         write(1, &store_bits, 1);
//         store_bits = 0;
//         bit_count = 0;
//     }
// }


void myhandler(int sig)
{
    if (sig == SIGUSR1)
        write(1, "1", 1);
    if (sig == SIGUSR2)
        write(1, "0", 1);
}


int main(void)
{
    ft_printf("Server printf=%d\n", getpid());
    
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = myhandler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    while (1)
    {
        pause();  // Espera os sinais
    }
    
    return 0;
}
