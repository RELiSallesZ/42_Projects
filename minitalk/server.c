/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles@student.42firenze.it>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:23:39 by rsalles-          #+#    #+#             */
/*   Updated: 2024/12/09 18:57:47 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void	ft_error(int error_code);
void	argserr(int argc, char *argv[]);

void	myhandler(int sig)
{
	static char	store_bits = 0;
	static int	bit_count = 0;

	if (sig == SIGUSR1)
		store_bits |= (1 << (7 - bit_count));
	if (sig == SIGUSR2)
		store_bits &= ~(1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd(store_bits, 1);
		store_bits = 0;
		bit_count = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	if (pid < 0)
		ft_error(ERROR_PID);
	argserr(ac, av);
	ft_putstr_fd("Server PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	if (signal(SIGUSR1, &myhandler) == SIG_ERR)
		ft_error(ERROR_SIGNAL);
	if (signal(SIGUSR2, &myhandler) == SIG_ERR)
		ft_error(ERROR_SIGNAL);
	while (42)
	{
	}
	return (0);
}

void	ft_error(int error_code)
{
	if (error_code == ERROR_ARGS)
		ft_putendl_fd("Error: please, just type: ./server ", 2);
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

void	argserr(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		ft_error(ERROR_ARGS);
}
