/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:12:02 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/23 13:17:12 by yongjale         ###   ########.fr       */
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
	long long int	begin_time;
	pthread_mutex_t message;
	pthread_mutex_t *forks;
}t_ph;

enum e_ERROR{
	INVALID_ARGUMENTS = 1, 
	INVALID_VALUE = 2,
	FAILURE_MUTEX = 77
};

#endif