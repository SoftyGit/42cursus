/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:16:14 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/06 10:25:15 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

void	rra(t_stack *a)
{
	t_node  *first;
	t_node  *lastsecond;
	t_node  *last;

	if (a->top == a->bot)
		return ;
	first = a->top;
	lastsecond = last->prev;
	last = a->bot;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	if (lastsecond != last)
		lastsecond->next = NULL;
	a->top = last;
	a->bot = lastsecond;
}

void	rrb(t_stack *b)
{
	t_node  *first;
	t_node  *lastsecond;
	t_node  *last;

	if (b->top == b->bot)
		return ;
	first = b->top;
	lastsecond = last->prev;
	last = b->bot;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	if (lastsecond != last)
		lastsecond->next = NULL;
	b->top = last;
	b->bot = lastsecond;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);	
}