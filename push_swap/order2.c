/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:52:56 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/06 08:58:38 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

void	ra(t_stack *a)
{
	t_node  *first;
	t_node  *second;
	t_node  *last;

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
}

void	rb(t_stack *b)
{
	t_node  *first;
	t_node  *second;
	t_node  *last;

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
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
}
