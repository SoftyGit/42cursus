/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:41:58 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/24 00:51:36 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	int	ph_isblank(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ph_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ph_atoi(const char *str)
{
	size_t	ret;
	char	sign;

	ret = 0;
	sign = 1;

	while (ph_isblank(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - *(str++);
	while (ph_isdigit(*str))
		ret = ret * 10 + (*(str++) - '0');
	return (sign * ret);
}

long long int	ph_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec);
}

void	ph_sleep(t_th *thread, int wait_time)
{
	long long int	std_time;
	long long int	now_time;

	std_time = ph_time();
	usleep(wait_time);
	now_time = ph_time();
	thread->begin_time += now_time - std_time - wait_time;
}