/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:11:40 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 08:45:57 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_H
# define ORDER_H

# include "ps.h"

void	sa(t_stack	*a, int mode);
void	sb(t_stack	*b, int mode);
void	ss(t_stack	*a, t_stack	*b);
void	pa(t_stack	*a, t_stack *b);
void	pb(t_stack	*a, t_stack *b);
void	ra(t_stack *a, int mode);
void	rb(t_stack *b, int mode);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int mode);
void	rrb(t_stack *b, int mode);
void	rrr(t_stack *a, t_stack *b);
void	repeat_rb(t_stack *b, int num);
void	repeat_rrb(t_stack *b, int num);

#endif