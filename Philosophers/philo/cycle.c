/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:49:01 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/23 15:28:13 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "utils.h"

static void	get_eat(t_ph* ph, int num);
static void	get_sleep(t_ph* ph, int turn);

int	init_cycle(t_ph *ph)
{
	int	num;

	ph->begin_time = ph_time();
	while (1)
	{
		num = 0;
		while (num < ph->num_philo)
		{
			if (pthread_create(&ph->philo[num].thread, NULL, init_thread, ph))
				return (FAILURE_THREAD);
			num += 2;
		}
		num = 1;
		while (num < ph->num_philo)
		{
			if (pthread_create(&ph->philo[num].thread, NULL, init_thread, ph))
				return (FAILURE_THREAD);
			num += 2;
		}
		return (0);
	}
}

/*
int	init_cycle(t_ph *ph)
{
	int	turn;
	int	num;

	turn = 1;
	ph->begin_time = ph_time();
	while (1)
	{
		num = 0;
		while (num < ph->num_philo)
		{
			if (pthread_create(&ph->philo[num].thread, NULL, get_eat, ph))
				return (FAILURE_THREAD);
			if (num % 2 == turn && !(turn && num == ph->num_philo - 1)) // 홀수 & 짝수 구분 (홀수이면서 마지막 값은 안됨)
				get_eat(ph, num);
			num++;
		}
		get_sleep(ph, turn);
		turn = (turn + 1) % 2;
		return (0);
	}
}
*/

void	init_thread(t_ph *ph)
{
	get_eat(ph)
}

static void	get_eat(t_ph* ph, int num)
{
	long long int	std_time;

	std_time = ph_time();
	pthread_mutex_lock(&ph->forks[num]);
	printf("%lld %d has taken a fork\n", std_time - ph->begin_time, num + 1);
	if (num == ph->num_philo)
		pthread_mutex_lock(&ph->forks[0]);
	else
		pthread_mutex_lock(&ph->forks[num + 1]);
	printf("%lld %d has taken a fork\n", std_time - ph->begin_time, num + 1);
	printf("%lld %d is eating\n", std_time - ph->begin_time, num + 1);
	ph->begin_time += ph_time() - std_time;
}

static void	get_sleep(t_ph* ph, int turn)
{
	long long int	std_time;
	int	num;

	num = 0;
	std_time = ph_time();
	while (num < ph->num_philo)
	{
		if (num % 2 == turn && !(turn && num == ph->num_philo - 1))
		{
			printf("%lld %d is sleeping\n", std_time - ph->begin_time, num + 1);
			pthread_mutex_unlock(&ph->forks[num]);
			if (num == ph->num_philo)
				pthread_mutex_unlock(&ph->forks[0]);
			else
				pthread_mutex_unlock(&ph->forks[num + 1]);
		}
		num++;
	}
	ph->begin_time += ph_time() - std_time;
}
