/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:50:34 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/24 15:15:09 by mbolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long int	ft_chksign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

long int	ft_atoi(char *src)
{
	long int 	sign;
	long int	result;
	

	sign = 1;
	result = 0;
	while (*src == ' ' || *src == '\t' || *src == '\n' || *src == '\v' || *src == '\f' || *src == '\r')
		src++;
	if (*src == '+' || *src == '-')
		sign *= ft_chksign(*src++);
	while (*src)
	{
		if (*src >= '0' && *src <= '9')
			result = result * 10 + ((*src ) - '0');
		else
			return (0); 
		src++;
	}
	return (sign * result);
}

void	ft_input_parser(long int pid, char *str)
{
	(void)str;
	if (pid <= 0 || kill(pid, SIGUSR1) != 0)
		exit(EXIT_FAILURE);
	printf("El proceso con pid: %ld; existe.\n", pid);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_input_parser(ft_atoi(argv[1]), argv[2]);
	return (0);
}
