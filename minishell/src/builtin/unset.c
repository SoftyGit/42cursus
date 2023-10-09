/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:23:21 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 18:50:34 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "utils.h"
#include "envp.h"

int	ms_unset(char **args, int num_commands)
{
	int	i;
	int	flag;

	if (args == NULL || args[0] == NULL || num_commands > 1)
		return (EXIT_SUCCESS);
	i = 0;
	flag = EXIT_SUCCESS;
	while (args[i])
	{
		if (ms_isdigit(args[i][0]) == 1)
		{
			printf("%s: not a valid identifier\n", args[i]);
			flag = EXIT_FAILURE;
		}
		del_envp(args[i]);
		i++;
	}
	return (flag);
}
