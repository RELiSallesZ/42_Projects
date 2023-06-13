#include <stdio.h>
#include <unistd.h>

int memoria(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		j++;
	}
	printf("i + j = %i", i+j+1);
	int k = i + j + 1;
	return k;
}

char *ft_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest [i] = '\0';
	return dest;
}

int main ()
{
	char dest[] = "vaai se ";
	char src[] = "ferrar";
	int memo = memoria(dest, src);

	char newdest[memo];

	newdest = ft_strcat(dest, src);
	
	printf("novo destino = %s\n", newdest);

	printf("destino = %s\n",ft_strcat(dest, src));
	printf("memoria = %i\n",memoria(dest, src));


}