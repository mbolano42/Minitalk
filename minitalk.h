/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbolano- <mbolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:50:55 by mbolano-          #+#    #+#             */
/*   Updated: 2024/10/24 15:06:23 by mbolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

long int	ft_chksign(char c);
long int	ft_atoi(char *src);
void		ft_input_parser(long int pid, char *str);

#endif