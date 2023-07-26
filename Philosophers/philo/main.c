/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:15:03 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/26 16:05:44 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errno.h"
#include "cycle.h"

static int	init_ph(t_ph *ph, t_th **thread, char **argv);
static int	init_thread(t_ph *ph, t_th **thread);
static int	init_mutex(t_ph *ph);

int	main(int argc, char **argv)
{
	t_th	*thread;
	int		errno;
	t_ph	ph;

	memset(&ph, 0, sizeof(t_ph));
	if (argc != 5 && argc != 6)
		return (ph_error(INVALID_ARGUMENTS));
	errno = init_ph(&ph, &thread, argv);
	if (errno)
		return (ph_error(errno));
	errno = init_cycle(&ph, thread);
	if (errno)
		return (ph_error(errno));
}

static int	init_ph(t_ph *ph, t_th **thread, char **argv)
{
	ph->num_philo = ph_atoi(argv[1]);
	ph->time_die = ph_atoi(argv[2]);
	ph->time_eat = ph_atoi(argv[3]);
	ph->time_sleep = ph_atoi(argv[4]);
	ph->num_times_philo_must_eat = 0;
	if (argv[5])
		ph->num_times_philo_must_eat = ph_atoi(argv[5]);
	else
		ph->num_times_philo_must_eat = INT_MAX;
	if (ph->num_philo <= 0 || ph->time_die <= 0 || ph->time_eat <= 0 
		|| ph->time_sleep <=0 || ph->num_times_philo_must_eat < 0)
		return (INVALID_VALUE);
	if (init_thread(ph, thread))
		return (FAILURE_THREAD);
	if (init_mutex(ph))
		return (FAILURE_MUTEX);
	return (0);
}

static int	init_thread(t_ph *ph, t_th **thread)
{
	int	num;

	*thread = malloc(sizeof(t_th) * ph->num_philo);
	if (!*thread)
		return (FAILURE_THREAD);
	num = 0;
	while (num < ph->num_philo)
	{
		(*thread)[num].num = num;
		(*thread)[num].ph = ph;
		num++;
	}
	return (0);
}

static int	init_mutex(t_ph *ph)
{
	int	num;

	if (pthread_mutex_init(&(ph->printer), NULL))
		return (FAILURE_MUTEX);
	ph->forks = malloc(sizeof(pthread_mutex_t) * ph->num_philo);
	if (!ph->forks)
		return (FAILURE_MUTEX);
	ph->times = malloc(sizeof(pthread_mutex_t) * ph->num_philo);
	if (!ph->times)
	{
		free(ph->forks);
		return (FAILURE_MUTEX);
	}
	num = 0;
	while (num < ph->num_philo)
	{
		if (pthread_mutex_init(&(ph->forks[num]), NULL))
			return (FAILURE_MUTEX);
		if (pthread_mutex_init(&(ph->times[num]), NULL))
			return (FAILURE_MUTEX);
		num++;
	}
	return (0);
}
