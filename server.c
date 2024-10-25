/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:16:13 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/25 12:49:54 by mbolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_fill_nbr(char *nbr)
{
	int	i;

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
		ft_putnbr(pid / 10);
	write(1, &nbr[pid % 10], 1);
}

// For a better understanding:
//	-	(1 << 0) = 2^0 -> (1 << 1) = 2^1 ... (1 << 8) = 2^8.
//	-	letter |= (1 << count); IS THE SAME THAN: letter += (1 << count).
//	-	Once the server has received 8 signals ().

void	ft_signal_handler(int signum)
{
	static int	letter = 0;
	static int	count = 0;

	if (signum == SIGUSR2)
		letter |= (1 << count);
	count++;
	if (count == 8)
	{
		write(1, &letter, 1);
		count = 0;
		letter = 0;
	}
}

int	main(void)
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
		usleep(500);
	}
	return (0);
}
