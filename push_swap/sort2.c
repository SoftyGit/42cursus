/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:52:19 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/11 12:59:39 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort5(t_stack *a, t_stack *b)
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
		else if (a->top->num <= CHUNK + i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}