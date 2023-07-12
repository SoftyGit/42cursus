/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:11:05 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 09:56:26 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_bonus.h"

static void		sort2_input(char *str, t_stack *a, t_stack *b);
static void		sort3_input(char *str, t_stack *a, t_stack *b);
static size_t	ps_strnewlen(const char *s);

void	get_input(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
		{
			if (b->top == NULL && check_sort(a))
				ps_ok();
			else
				ps_ko();
		}
		if (ps_strnewlen(str) == 2)
			sort2_input(str, a, b);
		else if (ps_strnewlen(str) == 3)
			sort3_input(str, a, b);
		else
		{
			free(str);
			ps_error();
		}
		free(str);
		if (b->top == NULL && check_sort(a))
			ps_ok();
	}
}

static void	sort2_input(char *str, t_stack *a, t_stack *b)
{
	if (ps_strncmp(str, "sa", 2) == 0)
		sa(a);
	else if (ps_strncmp(str, "sb", 2) == 0)
		sb(b);
	else if (ps_strncmp(str, "ss", 2) == 0)
		ss(a, b);
	else if (ps_strncmp(str, "pa", 2) == 0)
		pa(a, b);
	else if (ps_strncmp(str, "pb", 2) == 0)
		pb(a, b);
	else if (ps_strncmp(str, "ra", 2) == 0)
		ra(a);
	else if (ps_strncmp(str, "rb", 2) == 0)
		rb(b);
	else if (ps_strncmp(str, "rr", 2) == 0)
		rr(a, b);
	else
	{
		free(str);
		ps_error();
	}
}

static void	sort3_input(char *str, t_stack *a, t_stack *b)
{
	if (ps_strncmp(str, "rra", 2) == 0)
		rra(a);
	else if (ps_strncmp(str, "rrb", 2) == 0)
		rrb(b);
	else if (ps_strncmp(str, "rrr", 2) == 0)
		rrr(a, b);
	else
	{
		free(str);
		ps_error();
	}
}

static size_t	ps_strnewlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s && *s != '\n')
	{
		len++;
		s++;
	}
	return (len);
}
