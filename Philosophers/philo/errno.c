/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:10:13 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/27 20:04:14 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_error(int errno)
{
	if (errno == INVALID_ARGUMENTS)
		printf("INVALID_ARGUMENTS\n");
	else if (errno == INVALID_VALUE)
		printf("INVALID_VALUE\n");
	else if (errno == FAILURE_MUTEX)
		printf("FAILURE_MUTEX\n");
	else if (errno == FAILURE_THREAD)
		printf("FAILURE_THREAD\n");
	return (1);
}
