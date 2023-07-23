/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:12:02 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/24 01:34:05 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_ph
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_times_philo_must_eat;
	pthread_mutex_t printer;
	pthread_mutex_t *forks;
}t_ph;

typedef struct s_th
{
	int				num;
	long long int	begin_time;
	pthread_t		thread;
	t_ph			*ph;
}t_th;

enum e_ERROR{
	INVALID_ARGUMENTS = 1, 
	INVALID_VALUE = 2,
	FAILURE_MUTEX = 77,
	FAILURE_THREAD = 78
};

# define MSG_SLEEP "is sleeping"
# define MSG_EAT "is eating"
# define MSG_FORK "has taken a fork"

#endif