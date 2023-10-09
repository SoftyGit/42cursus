/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:31:38 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:50:44 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "envp.h"
#include "utils.h"

int	check_overflow(const char *str)
{
	int			negative;
	long long	num;
	long long	num_temp;

	negative = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	num = 0;
	while ((*str >= 48) && (*str <= 57))
	{
		num_temp = (num * 10) + (*str - 48);
		if (negative == 1 && num_temp <= num)
			return (EXIT_FAILURE);
		else if (negative == -1 && (-1 * num_temp) >= (-1 * num))
			return (EXIT_FAILURE);
		num = num_temp;
		str++;
	}
	return (EXIT_SUCCESS);
}

int	is_numeric_argument(char *arg)
{
	int	i;

	i = 1;
	if (check_overflow(arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ms_isdigit(arg[0]) == 0 && arg[0] != '-')
		return (EXIT_FAILURE);
	while (arg[i])
	{
		if (ms_isdigit(arg[i]) == 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ms_exit(char **args)
{
	if (!(args == NULL || args[0] == NULL))
	{
		if (args[1] != NULL)
		{
			perror("exit: too many arguments\n");
			exit (EXIT_FAILURE);
		}
		else
		{
			if (is_numeric_argument(args[0]) == EXIT_FAILURE)
			{
				printf("numeric argument required");
				update_envp("ISEXIT", "TRUE");
				exit(EXIT_NONNUMERIC);
			}
		}
		g_exit_status = ms_atoi(args[0]);
	}
	update_envp("ISEXIT", "TRUE");
	exit(g_exit_status);
}
