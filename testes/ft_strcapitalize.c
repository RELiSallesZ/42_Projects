#include <stdio.h>
#include <unistd.h>

char *ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if ((str[i] >= 97 && str[i] <= 122) &&
			(i == 0 || str[i-1] == 32))
			{
				str[i] -= 32;
			}
			else if ((str[i] >= 'A' && str[i] <= 'Z') && 
						(str[i-1] != 32))
				{
					str[i] += 32;
				}

	}
}

main (void)
{
	char	str[] = "vai se lascar";
	char *ft_strcapitalize(char *str);
	printf("A frase convertida é: %s", char *ft_strcapitalize(*str)); 
}