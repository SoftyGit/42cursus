/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:11:40 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/05 23:16:41 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_H
# define ORDER_H

# include "ps.h"

void	sa(t_stack	*a);
void	sb(t_stack	*b);
void	ss(t_stack	*a, t_stack	*b);
void	pa(t_stack	*a, int data);
void	pb(t_stack	*b, int data);

#endif