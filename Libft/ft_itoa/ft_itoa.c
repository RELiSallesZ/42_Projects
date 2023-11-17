#include <unistd.h>
// #include <stdio.h>
#include <stdlib.h>

static int countDigits(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return i + 1;
}

char *ft_itoa(int nbr)
{
	char *str;
	int len;
	int ini;

	len = countDigits(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len + 1] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
		ini = 1;
	}
	else
	{
		ini = 0;
	}
	while (--len >= ini)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return str;
}
/*
int main(void)
{
	int nbr;

	nbr = 0;
	printf("str = %s\n", ft_itoa(nbr));

	return 0;
}

/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/
