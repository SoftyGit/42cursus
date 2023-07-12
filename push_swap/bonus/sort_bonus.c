/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:12:51 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 09:49:44 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_bonus.h"

int	check_sort(t_stack *a)
{
	t_node	*cur_node;
	int		last_value;

	last_value = a->top->num;
	cur_node = a->top;
	while (cur_node)
	{
		if (last_value <= cur_node->num)
			last_value = cur_node->num;
		else
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}
