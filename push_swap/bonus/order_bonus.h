/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:11:40 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 09:58:08 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_BONUS_H
# define ORDER_BONUS_H

# include "ps_bonus.h"

void	sa(t_stack	*a);
void	sb(t_stack	*b);
void	ss(t_stack	*a, t_stack	*b);
void	pa(t_stack	*a, t_stack *b);
void	pb(t_stack	*a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	repeat_rb(t_stack *b, int num);
void	repeat_rrb(t_stack *b, int num);

#endif