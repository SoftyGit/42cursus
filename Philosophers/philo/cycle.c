/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:49:01 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/22 15:06:59 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"

int	init_cycle(t_ph *ph)
{
	int	turn;
	int	num;

	turn = 1;
	while (1)
	{
		num = 0;
		while (num < ph->num_philo)
		{
			if (num % 2 == turn && !(turn && num == ph->num_philo - 1)) // 홀수 & 짝수 구분 (홀수이면서 마지막 값은 안됨)
				get_eat(ph, num);
			get_sleep(ph, turn);
		}
	}
}

int	get_eat(t_ph* ph, int num)
{
	phread_mutex_lock(&ph->forks[num]);
	if (num == ph->num_philo)
		pthread_mutex_locK(&ph->forks[0]);
	else
		pthread_mutex_lock(&ph->forks[num + 1]);
	printf("")
}

void	get_sleep(t_ph* ph, int turn)
{
	int	num;

	num = 0;
	while (num < ph->num_philo)
	{
		
	}
}
