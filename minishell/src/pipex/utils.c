/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:26:33 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/24 18:29:31 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex.h"
#include "envp.h"
#include "utils.h"

void	open_pipes(t_vars *vars, t_job *job)
{
	int	i;

	i = 0;
	while (i < job->num_command - 1)
	{
		pipe(vars->fds[i]);
		i++;
	}
}

void	close_pipes(t_vars *vars, t_job *job)
{
	int	i;

	i = 0;
	while (i < job->num_command - 1)
	{
		close(vars->fds[i][0]);
		close(vars->fds[i][1]);
		i++;
	}
}

int	count_words(char const *s, char c)
{
	int	i;
	int	cnt_words;

	i = 0;
	cnt_words = 0;
	if (s == 0)
		return (0);
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i) != 0)
			i++;
		if (*(s + i))
			cnt_words += 1;
		while (*(s + i) != c && *(s + i) != 0)
			i++;
	}
	return (cnt_words);
}

void	wait_pids(t_vars *var, t_job *job)
{
	int		i;
	int		statloc;
	char	*pwd;
	char	*isexit;

	i = 0;
	while (i < job->num_command)
	{
		wait4(var->pids[i], &statloc, 0, NULL);
		g_exit_status = WEXITSTATUS(statloc);
		pwd = find_envp("PWD");
		chdir(pwd);
		free(pwd);
		isexit = find_envp("ISEXIT");
		if (isexit != NULL && ms_strncmp(isexit, "TRUE", 4) == 0)
		{
			free(isexit);
			if (i == job->num_command - 1)
				exit (g_exit_status);
		}
		i++;
	}
}
