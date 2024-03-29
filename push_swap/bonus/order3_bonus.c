/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:16:14 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 08:49:08 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order_bonus.h"

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
	if (lastsecond != first)
		lastsecond->next = NULL;
	else
		first->next = NULL;
	a->top = last;
	a->bot = lastsecond;
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
	if (lastsecond != first)
		lastsecond->next = NULL;
	else
		first->next = NULL;
	b->top = last;
	b->bot = lastsecond;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	repeat_rb(t_stack *b, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		rb(b);
		i++;
	}
}

void	repeat_rrb(t_stack *b, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		rrb(b);
		i++;
	}
}
