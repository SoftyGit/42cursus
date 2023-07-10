/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:52:56 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/10 11:23:17 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (a->top == a->bot)
		return ;
	first = a->top;
	second = first->next;
	last = a->bot;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (second != last)
		second->prev = NULL;
	a->top = second;
	a->bot = last;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (b->top == b->bot)
		return ;
	first = b->top;
	second = first->next;
	last = b->bot;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (second != last)
		second->prev = NULL;
	b->top = second;
	b->bot = last;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
	write(1, "rr\n", 3);
}
