/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:12:51 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 10:04:17 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	check_sort(t_stack *a);
static int	find_chunk(int length);

void	sortlength(t_stack *a, t_stack *b)
{
	check_sort(a);
	if (a->length == 2)
		sort2(a);
	else if (a->length == 3)
		sort3(a);
	else if (a->length == 4)
		sort4(a, b);
	else if (a->length == 5)
		sort5(a, b);
	else if (a->length >= 6)
	{
		sort_a2b(a, b, find_chunk(a->length));
		sort_b2a(a, b);
	}
}

void	sort2(t_stack *a)
{
	if (a->top->num > a->bot->num)
		ra(a, 1);
}

void	sort3(t_stack *a)
{
	if (a->top->num < a->top->next->num)
	{
		if ((a->top->num < a->bot->num) && (a->top->next->num > a->bot->num))
		{
			sa(a, 1);
			ra(a, 1);
		}
		else if ((a->top->next->num > a->bot->num))
			rra(a, 1);
	}
	else
	{
		if (a->top->next->num > a->bot->num)
		{
			sa(a, 1);
			rra(a, 1);
		}
		else
		{
			if (a->top->num > a->bot->num)
				ra(a, 1);
			else
				sa(a, 1);
		}
	}
}

static void	check_sort(t_stack *a)
{
	t_node	*cur_node;
	int		last_value;

	last_value = a->top->data;
	cur_node = a->top;
	while (cur_node)
	{
		if (last_value <= cur_node->data)
			last_value = cur_node->data;
		else
			return ;
		cur_node = cur_node->next;
	}
	exit(0);
}

static int	find_chunk(int length)
{
	float	sum;

	sum = (0.000000053) * length * length + (0.03) * length + 14.5;
	return ((int)sum);
}
