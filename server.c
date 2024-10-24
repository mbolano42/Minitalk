/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:16:13 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/24 15:19:29 by mbolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(void)
{
	printf("Señal recibida.\n");
}

int main(void)
{
	while (1)
	{
		signal(SIGUSR1, &ft_signal_handler);
	}
	return (0);
}
