/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles@student.42firenze.it>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:23:39 by rsalles-          #+#    #+#             */
/*   Updated: 2024/12/07 10:18:29 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mysignal(char c, int pid) 
{
	int i = 7;
	while (i >= 0) 
	{
		if(c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
    }
}

int 	main(int argc, char **argv)
{
	int pid;
	int i;

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
			mysignal(argv[2][i], pid);
			i++;
	}
	return (0);
}