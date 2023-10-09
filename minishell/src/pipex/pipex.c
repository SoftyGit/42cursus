/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:10:10 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:40:52 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex.h"
#include "envp.h"
#include "utils.h"

int	pipex(t_job *job)
{
	t_vars		*vars;
	t_command	*current_command;
	int			i;

	vars = get_vars(job);
	if (job->num_command > 1)
		open_pipes(vars, job);
	current_command = job->command;
	i = -1;
	while (++i < job->num_command)
	{
		vars->pids[i] = fork();
		if (vars->pids[i] == 0)
			multi_pipe(vars, job, current_command, i);
		current_command = current_command->next_command;
	}
	close_pipes(vars, job);
	wait_pids(vars, job);
	if (vars->limiter != 0)
		unlink("/var/tmp/pipex_temp");
	free_vars(vars, job);
	return (0);
}
