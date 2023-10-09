/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:47:55 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 19:08:15 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"
#include "redirection.h"

int	redirection_command(t_command *command)
{
	if (command->infile != NULL)
		if (redirection_infile(command->infile) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if (command->outfile != NULL)
		if (redirection_outfile(command->outfile) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (0);
}

int	redirection_infile(t_red_in *red)
{
	int	fd_infile;

	while (red != NULL)
	{
		if (red->type == REDIRECTION_IN)
			fd_infile = open(red->infile, O_RDONLY);
		else if (red->type == REDIRECTION_HEREDOC)
		{
			here_doc(red);
			fd_infile = open("/var/tmp/pipex_temp", O_RDONLY);
		}
		if (fd_infile < 0)
		{
			dup2(STDERR_FILENO, STDOUT_FILENO);
			printf("%s: No such file or directory\n", red->infile);
			return (EXIT_FAILURE);
		}
		dup2(fd_infile, STDIN_FILENO);
		red = red->next;
	}
	return (0);
}

int	redirection_outfile(t_red_out *red)
{
	int	fd_outfile;

	while (red != NULL)
	{
		if (red->type == REDIRECTION_OUT)
			fd_outfile = open(red->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
		else if (red->type == REDIRECTION_APPEND)
			fd_outfile = open(red->outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (fd_outfile < 0)
		{
			dup2(STDERR_FILENO, STDOUT_FILENO);
			printf("%s: Error\n", red->outfile);
			return (EXIT_FAILURE);
		}
		dup2(fd_outfile, STDOUT_FILENO);
		red = red->next;
	}
	return (0);
}
