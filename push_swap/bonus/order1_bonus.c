/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:03:24 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 09:37:02 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order_bonus.h"

void	sa(t_stack	*a)
{
	t_node	*first;
	t_node	*second;

	if (a->top == a->bot)
		return ;
	first = a->top;
	second = a->top->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	a->top = second;
}

void	sb(t_stack	*b)
{
	t_node	*first;
	t_node	*second;

	if (b->top == b->bot)
		return ;
	first = b->top;
	second = b->top->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	b->top = second;
}

void	ss(t_stack	*a, t_stack	*b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack	*a, t_stack *b)
{
	t_node	*top;

	top = b->top;
	if (!top)
		return ;
	if (top->next)
		top->next->prev = NULL;
	else
		b->bot = NULL;
	b->top = top->next;
	top->next = a->top;
	if (a->top)
		a->top->prev = top;
	else
		a->bot = top;
	a->top = top;
}

void	pb(t_stack	*a, t_stack *b)
{
	t_node	*top;

	top = a->top;
	if (!top)
		return ;
	if (top->next)
		top->next->prev = NULL;
	else
		a->bot = NULL;
	a->top = top->next;
	top->next = b->top;
	if (b->top)
		b->top->prev = top;
	else
		b->bot = top;
	b->top = top;
}
