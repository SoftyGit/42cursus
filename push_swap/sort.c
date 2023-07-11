/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:12:51 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/11 12:15:02 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "order.h"

void	sortlength(t_stack *a, t_stack *b)
{
	if (a->length == 2)
		sort2(a, b);
	else if (a->length == 3)
		sort3(a, b);
}

void	sort2(t_stack *a, t_stack *b)
{
	if (a->top->num > a->bot->num)
		ra(a);
}

void	sort3(t_stack *a, t_stack *b)
{
	if (a->top->num > a->top->next->num)
	{
		ra(a);
		if (a->top->num > a->top->next->num)
			sa(a);
	}
	else
	{
		if (a->bot->prev->num > a->bot->num)
		{
			ra(a);
			sa(a);
			rra(a);
		}
	}
}