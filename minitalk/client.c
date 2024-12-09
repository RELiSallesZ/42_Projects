/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles@student.42firenze.it>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:23:39 by rsalles-          #+#    #+#             */
/*   Updated: 2024/12/09 18:55:34 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(int error_code);

void	mysignal(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(ERROR_KILL);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(ERROR_KILL);
		}
		i--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_error(ERROR_ARGS);
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

void	ft_error(int error_code)
{
	if (error_code == ERROR_ARGS)
		ft_putendl_fd("Error: type: ./client [PID] [message]\n", 2);
	else if (error_code == ERROR_PID)
		ft_putendl_fd("Error: invalid PID", 2);
	else if (error_code == ERROR_CHAR)
		ft_putendl_fd("Error: invalid character", 2);
	else if (error_code == ERROR_SIGNAL)
		ft_putendl_fd("Error: signal failed", 2);
	else if (error_code == ERROR_KILL)
		ft_putendl_fd("Error: kill failed", 2);
	exit(error_code);
}
