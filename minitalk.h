/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:50:55 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/25 10:59:19 by mbolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

// Algoritmos implementados en el cliente:
long int	ft_atoi(char *src);
void		ft_send_byte_to_server(int letter, long int pid);
void		ft_input_parser(long int pid, char *str);
// Algoritmos implementados en el servidor:
void		ft_signal_handler(int signum);
void		ft_fill_nbr(char *nbr);
void		ft_putnbr(int pid);

#endif