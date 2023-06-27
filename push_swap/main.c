/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:34:08 by yongjale          #+#    #+#             */
/*   Updated: 2023/06/27 11:48:08 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "err.h"
#include <stdio.h>

static int	check_integer(char *str);
static int	check(char **argv);

int	main(int argc, char **argv)
{
	printf("%d", check(argv));
}

static int	check_integer(char *str)
{
	if (*str)
		return (1);
	while (*str)
	{
		if (!ps_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_integer(argv[i]))
			ps_error();
		i++;
	}
	return (1);
}