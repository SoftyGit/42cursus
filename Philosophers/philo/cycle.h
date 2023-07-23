/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:51:41 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/24 01:59:35 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLE_H
# define CYCLE_H

# include "philo.h"
# include <unistd.h>

int		init_cycle(t_ph *ph, t_th *thread);
void*	get_action(void *arg);

#endif