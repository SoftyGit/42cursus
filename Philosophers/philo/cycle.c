/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:49:01 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/24 02:08:38 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "utils.h"

static void	get_eat(t_ph *ph, t_th* thread, int num);
static void	get_sleep(t_ph *ph, t_th* thread, int num);
static void	get_print(t_ph* ph, long long int time, int num, char* msg);

int	init_cycle(t_ph *ph, t_th *thread)
{
	int	num;

	num = 0;
	while (num < ph->num_philo)
	{
		if (pthread_create(&thread[num].thread, NULL, get_action, &thread[num]))
			return (FAILURE_THREAD);
		num += 2;
	}
	usleep(100);
	num = 1;
	while (num < ph->num_philo)
	{
		if (pthread_create(&thread[num].thread, NULL, get_action, &thread[num]))
			return (FAILURE_THREAD);
		num += 2;
	}
	return (0);
}

void*	get_action(void *arg)
{
	t_th	*thread;

	thread = arg;
	thread->begin_time = ph_time();
	get_eat(thread->ph, thread, thread->num);
	ph_sleep(thread, thread->ph->time_eat);
	get_sleep(thread->ph, thread, thread->num);
	return (NULL);
}

static void	get_eat(t_ph *ph, t_th* thread, int num)
{
	long long int	std_time;
	long long int	chk_time;

	std_time = ph_time();
	pthread_mutex_lock(&ph->forks[num]);
	chk_time = ph_time();
	get_print(ph, std_time - thread->begin_time, num + 1, MSG_FORK);
	if (num == ph->num_philo - 1)
		pthread_mutex_lock(&ph->forks[0]);
	else
		pthread_mutex_lock(&ph->forks[num + 1]);
	chk_time = ph_time();
	get_print(ph, std_time - thread->begin_time, num + 1, MSG_FORK);
}

static void	get_sleep(t_ph *ph, t_th* thread, int num)
{
	long long int	std_time;

	std_time = ph_time();
	if (num == ph->num_philo - 1)
		pthread_mutex_unlock(&ph->forks[0]);
	else
		pthread_mutex_unlock(&ph->forks[num + 1]);
	pthread_mutex_unlock(&ph->forks[num]);
	get_print(ph, std_time - thread->begin_time, num + 1, MSG_SLEEP);
}

static void	get_print(t_ph* ph, long long int time, int num, char* msg)
{
	pthread_mutex_lock(&ph->printer);
	printf("%lld %d %s\n", time, num, msg);
	pthread_mutex_unlock(&ph->printer);
}
