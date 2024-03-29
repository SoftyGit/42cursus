/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:50:41 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/28 15:30:07 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_signal(int signal)
{
	static int	rece_byte = 0;
	static int	index = 0;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		rece_byte |= signal - 30;
		if (index != 7)
			rece_byte <<= 1;
	}
	index++;
	if (index == 8)
	{
		write(1, &rece_byte, 1);
		rece_byte = 0;
		index = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, server_signal);
	signal(SIGUSR2, server_signal);
	while (1)
		pause();
}
