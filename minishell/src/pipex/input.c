/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:59:43 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/24 13:09:51 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex.h"
#include "envp.h"
#include "utils.h"

t_vars	*get_vars(t_job *job)
{
	t_vars		*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == 0)
		print_error("Malloc error!");
	else
		vars->limiter = NULL;
	vars->path = get_path();
	get_fds(vars, job);
	return (vars);
}

char	**get_path(void)
{
	char	**ret;
	char	*temp;

	temp = find_envp("PATH");
	if (temp == NULL)
		return (NULL);
	ret = ms_split(temp + 5, ':');
	free(temp);
	return (ret);
}

void	get_fds(t_vars *vars, t_job *job)
{
	int		i;

	vars->pids = malloc(sizeof(int) * job->num_command);
	vars->fds = malloc(sizeof(int *) * job->num_command - 1);
	i = -1;
	while (++i < job->num_command - 1)
	{
		vars->fds[i] = malloc(sizeof(int) * 2);
		if (vars->fds[i] == 0)
			print_error("Malloc error!");
	}
}
