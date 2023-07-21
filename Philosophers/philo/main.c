/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:15:03 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/22 02:17:00 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errno.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		errno;

	memset(&data, 0, sizeof(t_data));
	if (argc != 4 && argc != 5)
		return (ph_error(INVALID_ARGUMENTS));
	errno = init_data(&data, argv);
	if (errno)
		return (ph_error(errno));
}

int	init_data(t_data *data, char **argv)
{
	data->num_philo = ph_atoi(argv[1]);
	data->time_die = ph_atoi(argv[2]);
	data->time_eat = ph_atoi(argv[3]);
	data->time_sleep = ph_atoi(argv[4]);
	data->num_times_philo_must_eat = 0;
	if (argv[5])
		data->num_times_philo_must_eat = ph_atoi(argv[5]);
	if (data->num_philo <= 0 || data->time_die <= 0 || data->time_eat <= 0 
		|| data->time_sleep <=0 || data->num_times_philo_must_eat < 0)
		return (INVALID_VALUE);
	if (init_mutex(data))
		return (FAILURE_MUTEX);
	
}

int	init_mutex(t_data *data)
{
	int	num;

	if (pthread_mutex_init(&(data->message), NULL))
		return (FAILURE_MUTEX);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (FAILURE_MUTEX);
	num = 0;
	while (num < data->num_philo)
		if (pthread_mutex_init(data->forks[i++], NULL))
			return (FAILURE_MUTEX);
	return (0);
}
