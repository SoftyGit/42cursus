/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:28:24 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:57:55 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "utils.h"
#include "envp.h"

int	ms_env(char **args)
{
	int		i;
	char	**envp;
	int		num_envp;

	i = 0;
	if (args[0] != NULL)
	{
		printf("env: %s: No such file or directory\n", args[0]);
		exit (EXIT_COMMAND_NOT_FOUND);
	}
	envp = read_envp();
	num_envp = count_envp_from_file();
	while (i < num_envp)
	{
		printf("%s", envp[i]);
		++i;
	}
	free_envp(envp);
	return (0);
}
