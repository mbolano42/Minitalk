/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:50:34 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/24 22:54:48 by mbolano-         ###   ########.fr       */
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

void	ft_send_byte_to_server(char *byte, int pid)
{
	while (*byte)
	{
		if (*byte == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		byte++;
		usleep(150);
	}
}

void	ft_char_to_binary(int letter, char *byte)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		byte[i] = letter % 2 + '0';
		letter /= 2;
		i++;
	}
}

void	ft_input_parser(long int pid, char *str)
{
	char	*byte;
	int		i;

	byte = (char *)malloc(sizeof(char) + 9);
	if (!byte || pid <= 0 || kill(pid, SIGUSR1) != 0)
	{
		free(byte);
		exit(EXIT_FAILURE);
	}
	while (*str)
	{
		ft_char_to_binary((int)*str, byte);
		ft_send_byte_to_server(byte, (int)pid);
		i = 0;
		while (i < 9)
		{
			byte[i] = '\0';
			i++;
		}
		str++;
	}
	free(byte);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_input_parser(ft_atoi(argv[1]), argv[2]);
	return (0);
}
