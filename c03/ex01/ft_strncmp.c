#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2,  unsigned int n)
{
	int i = 0;
	while (i <= n)
	{
	if (s1[i] == s2[i])
		{
		return (0);
		}
		else if (s1[i] - s2[i] > 0)
		{
			return (1);
		}
		return (-1);
	i++;
	}
}

int	main ()
{
	char s1[] = "azzzzzzzzzz s1lascar";
	char s2[] = "Azzzzzzzzzzar";
	unsigned int n = 6;

	printf("cheeee %i\n", ft_strncmp(s1, s2, n));
}
