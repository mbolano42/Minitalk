/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:16:13 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/24 16:44:15 by mbolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_fill_nbr(char *nbr)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		nbr[i] = '0' + i;
		i++;
	}
}

void	ft_putnbr(int pid)
{
	char	nbr[10];

	ft_fill_nbr(nbr);
	if (pid > 9)
		ft_putnbr(pid/10);
	write(1, &nbr[pid % 10], 1);
}

void	ft_signal_handler(int signum)
{
	
}

int main(void)
{
	int	pid;

	pid = getpid();
	if (pid > 0)
		write(1, "El PID del programa servidor es: ", 33);
	else
		exit(EXIT_FAILURE);
	ft_putnbr(pid);
	write(1, "\n- Esperando mensaje: ", 22);
	while (1)
	{
		signal(SIGUSR1, &ft_signal_handler);
		signal(SIGUSR2, &ft_signal_handler);
	}
	return (0);
}
