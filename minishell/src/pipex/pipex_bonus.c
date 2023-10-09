/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:58:14 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 19:12:39 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "pipex.h"
#include "envp.h"
#include "utils.h"
#include "execute.h"
#include "redirection.h"

int	multi_pipe(t_vars *vars, t_job *job, t_command *command, int i)
{
	if (i != 0)
		dup2(vars->fds[i - 1][0], STDIN_FILENO);
	if (command->next_command != NULL)
		dup2(vars->fds[i][1], STDOUT_FILENO);
	close_pipes(vars, job);
	if (redirection_command(command) == EXIT_FAILURE)
	{
		g_exit_status = EXIT_FAILURE;
		exit (EXIT_FAILURE);
	}
	classify_command(command, vars, job->num_command);
	free_vars(vars, job);
	return (EXIT_SUCCESS);
}

void	here_doc(t_red_in *red)
{
	char	*temp;
	int		len_limiter;
	char	*file_name;
	int		fd;

	temp = 0;
	len_limiter = ms_strlen(red->infile);
	file_name = "/var/tmp/pipex_temp";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		temp = readline(">");
		if (temp == NULL || ms_strncmp(temp, red->infile, len_limiter) == 0)
		{
			write(fd, "\n", 1);
			free(temp);
			close(fd);
			return ;
		}
		write(fd, temp, ms_strlen(temp));
		write(fd, "\n", 1);
		free(temp);
	}
}
