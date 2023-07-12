/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:34:08 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 08:50:29 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"
#include "err_bonus.h"
#include "ps_bonus.h"
#include "input_bonus.h"

static void	initialize(t_stack *a, t_stack *b);
static void	dup_check(int data, t_node *cur_node);
static void	check(char **argv, t_stack *a);
static void	assign(t_stack *a);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		exit(0);
	initialize(&a, &b);
	check(argv, &a);
	assign(&a);
	get_input(&a, &b);
	exit(0);
}

static void	initialize(t_stack *a, t_stack *b)
{
	a->bot = NULL;
	a->top = NULL;
	a->length = 0;
	b->bot = NULL;
	b->top = NULL;
	b->length = 0;
}

static void	dup_check(int data, t_node *cur_node)
{
	while (cur_node)
	{
		if (data == cur_node->data)
			ps_error();
		cur_node = cur_node -> next;
	}
}

static void	check(char **argv, t_stack *a)
{
	t_node	*new_node;
	int		i;

	i = 1;
	while (argv[i])
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		new_node->next = NULL;
		new_node->prev = a->bot;
		new_node->data = ps_atoi(argv[i]);
		new_node->num = -1;
		a->length++;
		dup_check(new_node->data, a->top);
		if (a->bot)
			a->bot->next = new_node;
		if (!a->top)
			a->top = new_node;
		a->bot = new_node;
		i++;
	}
}

static void	assign(t_stack *a)
{
	t_node		*min_node;
	t_node		*cur_node;
	int			num;
	long long	min;

	num = 0;
	while (num < (a->length))
	{
		min = INT_MAX;
		min_node = a->top;
		cur_node = a->top;
		while (cur_node)
		{
			if (cur_node->data <= min && cur_node->num == -1)
			{
				min = cur_node ->data;
				min_node = cur_node;
			}
			cur_node = cur_node->next;
		}
		min_node->num = num;
		num++;
	}
}
