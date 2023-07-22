/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:42:19 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/22 14:55:35 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <time.h>

typdef struct s_timeval
{
    time_t		tv_sec;
    suseconds_t	tv_usec;
}t_timeval;

int	ph_atoi(const char *str);
long long int	ph_time(void);
#endif