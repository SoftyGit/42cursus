/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:16:14 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/11 13:05:13 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

void	rra(t_stack *a)
{
	t_node	*first;
	t_node	*lastsecond;
	t_node	*last;

	if (a->top == a->bot)
		return ;
	first = a->top;
	last = a->bot;
	lastsecond = last->prev;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	if (lastsecond != last)
		lastsecond->next = NULL;
	a->top = last;
	a->bot = lastsecond;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*first;
	t_node	*lastsecond;
	t_node	*last;

	if (b->top == b->bot)
		return ;
	first = b->top;
	last = b->bot;
	lastsecond = last->prev;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	if (lastsecond != last)
		lastsecond->next = NULL;
	b->top = last;
	b->bot = lastsecond;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
