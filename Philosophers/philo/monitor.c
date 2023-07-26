/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:12:21 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/26 16:57:13 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "cycle.h"
#include "utils.h"

void	get_monitor(t_ph *ph, t_th *thread)
{
	int		num;
	int		flag;

	while (1)
	{
		num = 0;
		flag = 1;
		while (num < ph->num_philo)
		{
			pthread_mutex_lock(&ph->times[num]);
			if (ph_time() - thread[num].lst_time >= ph->time_die && thread[num].live == 1)
			{
				thread[num].live = 0; 
				thread[num].lst_time = -1;
				pthread_mutex_lock(&ph->printer);
				printf("%lldms %d %s\n", ph_time() - ph->begin_time, num + 1, MSG_DIE);
				pthread_mutex_unlock(&ph->printer);
			}
			else if (thread[num].live == 1)
				flag = 0;
			pthread_mutex_unlock(&ph->times[num]);
			usleep(100);
			num++;
		}
		if (flag)
		{
			printf("ALL FINISHED\n");
			return ;
		}
	}
}
