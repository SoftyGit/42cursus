/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:52:56 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/11 17:28:23 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	write(1, "ra\n", 3);
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
	else
		last->prev = NULL;
	a->top = second;
	a->bot = first;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	write(1, "rb\n", 3);
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
	else
		last->prev = NULL;
	b->top = second;
	b->bot = first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
	write(1, "rr\n", 3);
}
