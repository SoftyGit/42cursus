/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:50 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/24 14:40:25 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex.h"
#include "envp.h"
#include "utils.h"

void	free_vars(t_vars *vars, t_job *job)
{
	int	i;

	i = 0;
	if (vars == 0)
		return ;
	if (vars->fds != 0)
	{
		while (i < job->num_command - 1 && vars->fds[i] != 0)
			free(vars->fds[i++]);
		free(vars->fds);
		vars->fds = 0;
	}
	if (vars->pids != 0)
	{
		free(vars->pids);
		vars->pids = 0;
	}
	free_arrarr(vars->path);
	free(vars);
	vars = 0;
}

void	free_arrarr(char **arrarr)
{
	int	i;

	i = 0;
	if (arrarr == 0)
		return ;
	while (arrarr[i])
	{
		free(arrarr[i]);
		arrarr[i] = 0;
		i++;
	}
	free(arrarr);
}

void	free_temp(char **temp, char **first, char **last)
{
	free(temp[0]);
	free(temp[2]);
	free(temp);
	free(first);
	free(last);
}

char	*check_local(char *command)
{
	int	fd_temp;

	fd_temp = open(command, O_RDONLY);
	if (fd_temp > 0)
	{
		close(fd_temp);
		return (command);
	}
	return (NULL);
}

char	*get_cmd_path(t_command *command, char **path)
{
	char	*temp;
	int		fd_temp;
	int		i;

	i = -1;
	if (check_local(command->command) != NULL)
		return (command->command);
	if (path == NULL)
		return (NULL);
	while (path[++i])
	{
		temp = ms_strcat(path[i], '/', command->args[0]);
		fd_temp = open(temp, O_RDONLY);
		if (fd_temp > 0)
			break ;
		else
		{
			free(temp);
			temp = 0;
		}
	}
	close(fd_temp);
	return (temp);
}
