/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:03:24 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/10 11:23:00 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	ss(t_stack	*a, t_stack	*b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack	*a, int data)
{
	t_node	*top;

	top = a->top;
	a->top = (t_node *)malloc(sizeof(t_node));
	a->top->data = data;
	a->top->prev = NULL;
	a->top->next = top;
	top->prev = a->top;
	write(1, "pa\n", 3);
}

void	pb(t_stack	*b, int data)
{
	t_node	*top;

	top = b->top;
	b->top = (t_node *)malloc(sizeof(t_node));
	b->top->data = data;
	b->top->prev = NULL;
	b->top->next = top;
	top->prev = b->top;
	write(1, "pb\n", 3);
}
