/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:10:10 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/09 13:10:42 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ps.h"

void	ps_printer(int data)
{
	printf("%d\n", data);
}

void	ps_lstiter(t_node *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst -> num);
		lst = lst -> next;
	}
}

void	ps_lstreviter(t_node *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst -> num);
		lst = lst -> prev;
	}
}
