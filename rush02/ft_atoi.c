#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int ft_atoi(char *str)
{
    int i;
    int nb;
    int countplus;
    int countminus;
    int signal;
    
    i = 0;
    nb = 0;
    countplus = 0;
    countminus = 0;
    while (str[i] && ((str[i] >= 9 && str[i] <= 13) || 
        (str[i] == ' ') || (str[i] == '+') || (str[i] == '-')))
    {
        if(str[i] == '+')
            countplus++;
        if(str[i] == '-')
            countminus ++;
        i++;
    }
    if ((countplus + countminus) > 1)
        return (0);
    if (countplus == 1 || (countplus + countminus) == 0)
        signal = 1;
    if (countminus == 1)
        signal = -1;
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return(nb*signal);
}

int main(void)
{
    char    str[] = " -  42556s55d56++";
    printf("Atoi vale: %i\n", ft_atoi(str));
}