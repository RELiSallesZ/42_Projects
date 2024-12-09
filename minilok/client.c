/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles@student.42firenze.it>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:23:13 by ajaidi            #+#    #+#             */
/*   Updated: 2024/12/07 07:46:26 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mysignal(char c, int pid) 
{
	int i = 7;
	while (i >= 0) 
	{
		if(c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
    }
}

int 	main(`int argc, char **argv)
{
	int pid;
	int i;
	int j;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		write(1, "Type: PID [your message]\n", 25);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		j = 0;
		while (j < 8)
		{
			mysignal(argv[2][i], pid);
			j++;
			argv[2][i] = argv[2][i] << 1;
		}
		i++;
	}
	return (0);
}