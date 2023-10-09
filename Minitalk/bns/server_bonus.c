/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:50:41 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/28 17:51:45 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	server_signal(int signal, siginfo_t *info, void *context)
{
	static int	rece_byte = 0;
	static int	index = 0;
	static int	pid = 0;

	(void)context;
	if (info->si_pid != 0)
		pid = info->si_pid;
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		rece_byte |= signal - 30;
		if (index != 7)
			rece_byte <<= 1;
	}
	index++;
	if (index == 8)
	{
		if (rece_byte == 127)
			kill(pid, SIGUSR1);
		write(1, &rece_byte, 1);
		rece_byte = 0;
		index = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = server_signal;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
