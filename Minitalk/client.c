/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:37:44 by yongjale          #+#    #+#             */
/*   Updated: 2023/05/19 10:52:11 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	
	if (argc != 3)
		return (ft_printf("INVALID PARAMETERS"));
	if (ft_strlen(argv[1] > 5))
		return (ft_printf("INVALID PID"));
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100 || server_pid > 99998)
		return (ft_printf("INVALID PID"));

}

void	send_signal(int server_pid, char *send_string)
{
	char	send_byte;

	send_byte = *(send_string++);
	while (send_byte)
	{
		send_bitsignal(server_pid, send_byte);
		send_byte = *(send_string++);
	}
	send_bitsignal(server_pid, '\n');
}

void send_bitsignal(int server_pid, char send_byte)
{
	int index = 0;
	int	current_bit;

	index = 0;
	while (index < 8)
	{
		current_bit = send_byte >> (7 - index) & 1;
		if (current_bit == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(30);
		index++;
	}
}