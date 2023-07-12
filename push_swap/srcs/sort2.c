/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:52:19 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 08:45:52 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	find_num(t_stack *b, int num);

void	sort4(t_stack *a, t_stack *b)
{
	int	max_index;
	int	i;

	i = 0;
	max_index = find_num(a, 0);
	if (max_index <= 2)
		while (i++ < max_index)
			ra(a, 1);
	else
		while (i++ < 4 - max_index)
			rra(a, 1);
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_stack *a, t_stack *b)
{
	int	index;
	int	i;

	index = find_num(a, 4);
	i = 0;
	if (index <= 2)
		while (i++ < index)
			ra(a, 1);
	else
		while (i++ < 5 - index)
			rra(a, 1);
	pb(a, b);
	sort4(a, b);
	pa(a, b);
	ra(a, 1);
}

void	sort_a2b(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 1;
	while (i <= a->length)
	{
		if (a->top->num <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->top->num <= chunk + i)
		{
			pb(a, b);
			rb(b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
}

void	sort_b2a(t_stack *a, t_stack *b)
{
	int		cur_num;
	int		cur_index;

	cur_num = a->length - 1;
	while (cur_num >= 0)
	{
		cur_index = find_num(b, cur_num);
		if (cur_index < ((cur_num + 1) / 2))
		{
			repeat_rb(b, cur_index);
			pa(a, b);
		}
		else
		{
			repeat_rrb(b, cur_num - cur_index + 1);
			pa(a, b);
		}
		cur_num--;
	}
}

static int	find_num(t_stack *b, int num)
{
	t_node	*cur_node;
	int		index;

	index = 0;
	cur_node = b->top;
	while (cur_node)
	{
		if (cur_node->num == num)
			return (index);
		cur_node = cur_node->next;
		index++;
	}
	return (-1);
}
