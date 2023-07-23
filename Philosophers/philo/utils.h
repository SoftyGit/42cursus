/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:42:19 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/24 00:51:33 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

int				ph_atoi(const char *str);
long long int	ph_time(void);
void			ph_sleep(t_th *thread, int wait_time);

#endif