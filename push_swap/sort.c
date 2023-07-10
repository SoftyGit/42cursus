/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:12:51 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/10 11:27:38 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "order.h"

void	sortlength(t_stack *a, t_stack *b)
{
	if (a->length == 2)
		sort2(a, b);
	else if (a->legth == 3)
		sort3(a, b);
}

void	sort2(t_stack *a, t_stack *b)
{
	if (a->top->data > a->bot->data)
		ra(a);
}