/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:37:44 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/28 17:54:02 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_bitsignal(int server_pid, char send_byte)
{
	int	index;
	int	current_bit;

	index = 0;
	while (index < 8)
	{
		current_bit = send_byte >> (7 - index) & 1;
		if (current_bit == 0)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit(1);
		}
		else
			if (kill(server_pid, SIGUSR2) == -1)
				exit(1);
		usleep(30);
		index++;
	}
}

static void	send_signal(int server_pid, char *send_string)
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

static void	client_signal(int signal, siginfo_t *info, void *context)
{
	if (signal != SIGUSR1)
		return ;
	(void)info;
	(void)context;
	ft_printf("SUCCESS \n");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	action;
	char				signal[2];

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = client_signal;
	sigaction(SIGUSR1, &action, NULL);
	if (argc != 3)
		return (ft_printf("INVALID PARAMETERS\n"));
	if (ft_strlen(argv[1]) > 5)
		return (ft_printf("INVALID PID\n"));
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100 || server_pid > 99998)
		return (ft_printf("INVALID PID\n"));
	send_signal(server_pid, argv[2]);
	signal[0] = 127;
	signal[1] = 0;
	send_signal(server_pid, signal);
	while (1)
		pause();
}
