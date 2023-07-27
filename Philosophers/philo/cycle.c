/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:49:01 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/27 20:09:40 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "utils.h"
#include "monitor.h"

static void	get_eat(t_ph *ph, t_th *thread, int num);
static void	get_sleep(t_ph *ph, t_th *thread, int num);
static int	get_print(t_th *thread, int num, char *msg);

int	init_cycle(t_ph *ph, t_th *thread)
{
	int	num;

	ph->begin_time = ph_time();
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
	usleep(100);
	get_monitor(ph, thread);
	num = 0;
	while (num < ph->num_philo)
		pthread_join(thread[num++].thread, NULL);
	return (0);
}

void	*get_action(void *arg)
{
	t_th	*thread;
	t_ph	*ph;

	thread = arg;
	ph = thread->ph;
	thread->live = 1;
	thread->count_eat = 0;
	pthread_mutex_lock(&ph->times[thread->num]);
	thread->lst_time = ph->begin_time;
	pthread_mutex_unlock(&ph->times[thread->num]);
	while (thread->count_eat < ph->num_times_philo_must_eat 
		&&thread->lst_time != -1)
	{
		get_eat(ph, thread, thread->num);
		ph_sleep(ph->time_eat);
		get_sleep(ph, thread, thread->num);
		ph_sleep(ph->time_sleep);
		get_print(thread, thread->num, MSG_THINK);
	}
	return (NULL);
}

static void	get_eat(t_ph *ph, t_th *thread, int num)
{
	pthread_mutex_lock(&ph->times[num]);
	if (thread->lst_time == -1)
		return ;
	pthread_mutex_unlock(&ph->times[num]);
	pthread_mutex_lock(&ph->forks[num]);
	if (get_print(thread, num + 1, MSG_RFORK))
	{
		pthread_mutex_unlock(&ph->forks[num]);
		return ;
	}
	pthread_mutex_lock(&ph->forks[(num + 1) % ph->num_philo]);
	if (get_print(thread, num + 1, MSG_LFORK))
	{
		pthread_mutex_unlock(&ph->forks[num]);
		pthread_mutex_unlock(&ph->forks[(num + 1) % ph->num_philo]);
		return ;
	}
	if (get_print(thread, num + 1, MSG_EAT))
		return ;
}

static void	get_sleep(t_ph *ph, t_th *thread, int num)
{
	long long int	time;

	pthread_mutex_lock(&ph->times[num]);
	if (thread->lst_time == -1)
		return ;
	thread->lst_time = ph_time();
	thread->count_eat++;
	pthread_mutex_unlock(&ph->times[num]);
	time = ph_time();
	pthread_mutex_unlock(&ph->forks[(num + 1) % ph->num_philo]);
	pthread_mutex_unlock(&ph->forks[num]);
	thread->std_time += ph_time() - time;
	get_print(thread, num + 1, MSG_SLEEP);
}

int	get_print(t_th *thread, int num, char *msg)
{
	t_ph	*ph;

	ph = thread->ph;
	pthread_mutex_lock(&ph->times[num - 1]);
	if (thread->lst_time == -1)
		return (1);
	pthread_mutex_unlock(&ph->times[num - 1]);
	pthread_mutex_lock(&ph->printer);
	printf("%lldms %d %s\n", ph_time() - ph->begin_time, num, msg);
	pthread_mutex_unlock(&ph->printer);
	return (0);
}
