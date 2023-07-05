/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:03:24 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/05 23:15:46 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

void	sa(t_stack	*a)
{
	t_node	*first;
	t_node	*second;

	first = a->top;
	second = a->top->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
}

void	sb(t_stack	*b)
{
	t_node	*first;
	t_node	*second;

	first = b->top;
	second = b->top->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
}

void	ss(t_stack	*a, t_stack	*b)
{
	sa(a);
	sb(b);
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
}
