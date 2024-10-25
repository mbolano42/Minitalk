/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:50:34 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/25 11:07:43 by mbolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long int	ft_atoi(char *src)
{
	long int	sign;
	long int	result;

	sign = 1;
	result = 0;
	while (*src == ' ' || *src == '\t' || *src == '\n' || *src == '\v'
		|| *src == '\f' || *src == '\r')
		src++;
	if (*src == '+' || *src == '-')
	{
		if (*src == '-')
			sign *= -1;
		src++;
	}
	while (*src)
	{
		if (*src >= '0' && *src <= '9')
			result = result * 10 + ((*src) - '0');
		else
			return (0);
		src++;
	}
	return (sign * result);
}

void	ft_send_byte_to_server(int letter, long int pid)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = letter % 2;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		letter /= 2;
		i++;
	}
}

void	ft_input_parser(long int pid, char *str)
{
	if (pid <= 0 || kill(pid, SIGUSR1) != 0)
		exit(EXIT_FAILURE);
	while (*str)
	{
		ft_send_byte_to_server((int)*str, pid);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_input_parser(ft_atoi(argv[1]), argv[2]);
	return (0);
}
