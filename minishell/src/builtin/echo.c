/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:30:58 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/26 20:47:26 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "utils.h"

int	is_flag(char *arg)
{
	if (*arg != '-')
		return (-1);
	arg++;
	while (*arg)
	{
		if (*arg == 'n')
			arg++;
		else
			return (-1);
	}
	return (1);
}

int	find_flag(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (is_flag(args[i]) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

int	ms_echo(char **args)
{
	int	i;
	int	flag;

	if (args == 0 || args[0] == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	flag = -1;
	i = find_flag(args) - 1;
	if (i > -1)
		flag = 1;
	while (args[++i])
	{
		write(1, args[i], ms_strlen(args[i]));
		if (args[i + 1] != NULL)
			write(1, " ", 1);
	}
	if (flag == -1)
		write(1, "\n", 1);
	return (0);
}
